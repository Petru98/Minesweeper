#include "Level.hpp"

#include "textures.hpp"
#include "random.hpp"
#include "File.hpp"
#include "os.hpp"

const Level::Difficulty Level::Difficulty::beginner     = {9 , 9 , 10};
const Level::Difficulty Level::Difficulty::intermediate = {16, 16, 40};
const Level::Difficulty Level::Difficulty::expert       = {16, 30, 99};
const Level::Difficulty Level::Difficulty::maximum      = {35, 75, 999};

bool Level::mouse_left_pressed = false;
bool Level::mouse_right_pressed = false;

constexpr char Level::SAVE_FILE[];

Level::Difficulty Level::setDifficultyInBounds(Level::Difficulty difficulty)
{
    if(difficulty.lines == 0)
        difficulty.lines = 1;
    else if(difficulty.lines > Difficulty::maximum.lines)
        difficulty.lines = Difficulty::maximum.lines;

    if(difficulty.columns < 8)
        difficulty.columns = 8;
    else if(difficulty.columns > Difficulty::maximum.columns)
        difficulty.columns = Difficulty::maximum.columns;

    if(difficulty.mines == 0)
        difficulty.mines = 1;
    else if(difficulty.mines >= difficulty.lines*difficulty.columns)
        difficulty.mines = difficulty.lines*difficulty.columns - 1;

    return difficulty;
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(m_menu_bar, states);

    if(m_menu_bar.getOpenMenu() == nullptr)
    {
        target.draw(m_background, states);
        target.draw(m_header, states);
        target.draw(m_table, states);
    }
}

/* Constructor / Destructor */
Level::Level(sf::RenderWindow& window, const sf::Texture& textures)
    : m_game_menu(this), m_background(), m_header(), m_menu_bar(), m_table(), m_window(window), m_textures(textures), m_game_over(Status::None)
{
    m_game_menu.initialize(m_textures);
    m_menu_bar.addMenu(m_game_menu);
}
Level::~Level()
{}

/* New game */
bool Level::create(Level::Difficulty difficulty)
{
    difficulty = setDifficultyInBounds(difficulty);

    if(M_initializeBackground(difficulty.lines, difficulty.columns) == false)
        return false;

    if(m_table.create(difficulty.lines, difficulty.columns, difficulty.mines, m_textures) == false)
        throw Exception("Could not allocate memory for the cells");

    M_initializeMenu();
    M_initializeHeader();
    M_resizeWindow();
    m_table.setPosition(m_background.getPosition() + m_background.table_position);

    m_header.flags_left = difficulty.mines;
    m_game_over = Status::None;

    return true;
}
bool Level::M_initializeBackground(const sf::Uint16 lines, const sf::Uint16 columns)
{
    using namespace Resources::Textures;

    const sf::Vector2f size = {static_cast<float>(columns * CELL_WIDTH + Table::LEFT_OFFSET + Table::RIGHT_OFFSET),
                               static_cast<float>(lines * CELL_HEIGHT + Table::TOP_OFFSET + Table::BOTTOM_OFFSET)};

    m_background.setPosition(0.0f, MenuBar::HEIGHT);

    try
        {m_background.setSize(size);}
    catch(const std::exception& error)
    {
        if(sf::Vector2u(m_background.getSize()) == sf::Vector2u(0,0))
            throw;
        os::error(error.what());
        return false;
    }

    return true;
}
void Level::M_initializeMenu()
{
    m_menu_bar.setSize(sf::Vector2f(m_table.getSize().x + Table::LEFT_OFFSET + Table::RIGHT_OFFSET, MenuBar::HEIGHT));
}
void Level::M_initializeHeader()
{
    m_header.setPosition(m_background.getPosition() + m_background.header_position);
    m_header.setSize(sf::Vector2f(m_table.getSize().x + 2.0f, Header::HEIGHT));
    m_header.initialize(m_textures);
}

void Level::M_resizeWindow()
{
    const sf::Vector2u size(m_background.getSize().x, m_background.getSize().y + MenuBar::HEIGHT);
    if(m_window.isOpen() == false)
    {
        m_window.create(sf::VideoMode(size.x, size.y), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);
        if(m_window.isOpen() == false)
            throw Exception("Could not create the window");
    }
    else
        m_window.setSize(size);
}

/* Win / Lose */
void Level::win()
{
    m_game_over = Status::Won;
    m_header.smiley.setWin();

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            if(m_table[i][j].isRevealed() == false && m_table[i][j].hasFlag() == false)
                m_table[i][j].toggleFlag();
}
void Level::lose()
{
    m_game_over = Status::Lost;
    m_header.smiley.setLose();

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            m_table[i][j].reveal(true);
}

/* Events */
void Level::handleEvent(const sf::Event& event)
{
    if(event.type == sf::Event::Closed)
        this->onClosed();
    else if(m_menu_bar.getOpenMenu() != nullptr)
        m_menu_bar.handleEvent(event);
    else
        Scene::handleEvent(event);
}

void Level::onClosed()
{
    this->save(SAVE_FILE);
    m_table.destroy();
}

void Level::onResized(const sf::Event::SizeEvent& event)
{
    m_window.setView(sf::View(sf::FloatRect(0, 0, event.width, event.height)));
}

void Level::onLostFocus() {}
void Level::onGainedFocus() {}
void Level::onTextEntered(const sf::Event::TextEvent& event) {}
void Level::onKeyPressed(const sf::Event::KeyEvent& event) {}
void Level::onKeyReleased(const sf::Event::KeyEvent& event) {}
void Level::onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event) {}

void Level::M_setButtonPressStatus(const int button, const bool pressed)
{
    switch(button)
    {
        case sf::Mouse::Left : this->mouse_left_pressed = pressed; break;
        case sf::Mouse::Right: this->mouse_right_pressed = pressed; break;
    }
}

/* onMouseButtonPressed */
void Level::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{
    M_setButtonPressStatus(event.button, true);

    if(m_game_over == false && m_table.contains(event.x, event.y) == true)
        M_onMouseButtonPressedTable(event);
    else if(m_header.smiley.contains(m_header.getRelativePoint(event.x, event.y)) == true)
        M_onMouseButtonPressedSmiley(event);
    else if(m_menu_bar.contains(event.x, event.y) == true)
        m_menu_bar.onMouseButtonPressed(event);
}

void Level::M_onMouseButtonPressedTable(const sf::Event::MouseButtonEvent event)
{
    const int flags_set = m_table.onMouseButtonPressed(event);

    if(flags_set != 0)
    {
        ++m_header.moves;
        m_header.flags_left -= flags_set;
    }

    if(event.button == sf::Mouse::Left)
        m_header.smiley.setScared();
}

void Level::M_onMouseButtonPressedSmiley(const sf::Event::MouseButtonEvent event)
{
    if(event.button == sf::Mouse::Left)
        m_header.smiley.press();
}

/* onMouseButtonReleased */
void Level::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{
    M_setButtonPressStatus(event.button, false);

    if(m_game_over == false && m_table.contains(event.x, event.y) == true)
        M_onMouseButtonReleasedTable(event);
    else if(m_header.smiley.contains(m_header.getRelativePoint(event.x, event.y)) == true)
        M_onMouseButtonReleasedSmiley(event);
    else if(m_menu_bar.contains(event.x, event.y) == true)
        m_menu_bar.onMouseButtonReleased(event);
}

void Level::M_onMouseButtonReleasedTable(const sf::Event::MouseButtonEvent event)
{
    int status = m_table.onMouseButtonReleased(event);

    if(status == Status::Won)
    {
        ++m_header.moves;
        win();
    }
    else if(status == Status::Lost)
    {
        ++m_header.moves;
        lose();
    }
    else if(event.button == sf::Mouse::Left)
    {
        m_header.smiley.reset();
        m_header.moves += status;
    }
}

void Level::M_onMouseButtonReleasedSmiley(const sf::Event::MouseButtonEvent event)
{
    if(m_header.smiley.isPressed() == true)
        this->create(Difficulty(m_table.lines(), m_table.columns(), m_table.mines()));
}

/* onMouseMoved */
void Level::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{
    if(this->mouse_left_pressed == false)
        return;

    m_menu_bar.onMouseMoved(event);

    if(m_game_over == false)
        M_onMouseMovedInGame(event);
    else
        M_onMouseMovedGameOver(event);
}

void Level::M_onMouseMovedInGame(const sf::Event::MouseMoveEvent event)
{
    if(m_table.onMouseMoved(event) == true)
        m_header.smiley.setScared();
    else if(m_header.smiley.contains(m_header.getRelativePoint(event.x, event.y)) == false)
    {
        if(m_header.smiley.isPressed() == true)
            m_header.smiley.release();
        else
            m_header.smiley.reset();
    }
}

void Level::M_onMouseMovedGameOver(const sf::Event::MouseMoveEvent event)
{
    if(m_header.smiley.contains(m_header.getRelativePoint(event.x, event.y)) == false)
            m_header.smiley.release();
}

void Level::onMouseEntered() {}
void Level::onMouseLeft() {}

/* Save/Load */
bool Level::save(const char* const filename)const
{
    File file(filename, "wb");

    if(file.isOpen() == false)
        return false;
    return this->save(file);
}
bool Level::save(File& file)const
{
    file.writeUint32(MAGIC_NUMBER);
    file.writeInt8(m_game_over);
    file.writeInt16(m_header.moves.getCount());
    return m_table.save(file);
}
bool Level::load(const char* const filename)
{
    File file(filename, "rb");

    if(file.isOpen() == false)
        return false;
    return this->load(file);
}
bool Level::load(File& file)
{
    if(file.readUint32() != MAGIC_NUMBER)
        return false;

    m_game_over = file.readInt8();
    sf::Int16 moves_count = file.readInt16();

    if(m_table.load(file, m_textures, m_game_over) == false)
        return false;
    if(M_initializeBackground(m_table.lines(), m_table.columns()) == false)
        return false;

    M_initializeMenu();
    M_initializeHeader();
    M_resizeWindow();
    m_table.setPosition(m_background.getPosition() + m_background.table_position);

    M_updateFlagsCount();
    m_header.moves = moves_count;

    if(m_game_over == Status::Won)
        m_header.smiley.setWin();
    else if (m_game_over == Status::Lost)
        m_header.smiley.setLose();

    return true;
}

void Level::M_updateFlagsCount()
{
    sf::Uint16 count = 0;

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            if(m_table[i][j].hasFlag() == true)
                ++count;
    m_header.flags_left = m_table.mines() - count;
}
