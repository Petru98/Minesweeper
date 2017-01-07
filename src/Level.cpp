#include "Level.hpp"

#include "random.hpp"
#include "File.hpp"
#include <ctime>

const Level::Difficulty Level::Difficulty::beginner     = {9 , 9 , 10};
const Level::Difficulty Level::Difficulty::intermediate = {16, 16, 40};
const Level::Difficulty Level::Difficulty::expert       = {16, 30, 99};

constexpr char Level::SAVE_FILE[];

Level::Difficulty Level::setDifficultyInBounds(Level::Difficulty difficulty)
{
    if(difficulty.lines == 0)
        difficulty.lines = 1;
    else if(difficulty.lines > 35)
        difficulty.lines = 35;

    if(difficulty.columns < 8)
        difficulty.columns = 8;
    else if(difficulty.columns > 75)
        difficulty.columns = 75;

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
    Random::seed(std::time(nullptr));
    m_game_menu.initialize(m_textures);
    m_menu_bar.addMenu(m_game_menu);
}
Level::~Level()
{}

/* New game */
void Level::create(Level::Difficulty difficulty)
{
    difficulty = setDifficultyInBounds(difficulty);
    if(m_table.create(difficulty.lines, difficulty.columns, difficulty.mines, m_textures) == false)
        throw Exception(Error::Allocate, Error::messages[Error::Allocate]);

    M_initializeMenu();
    M_initializeBackground();
    M_initializeHeader();
    m_table.setPosition(m_background.getPosition() + m_background.table_position);
    M_resizeWindow();
    m_game_over = Status::None;
}
void Level::M_initializeMenu()
{
    m_menu_bar.setSize(sf::Vector2f(m_table.getSize().x + Table::LEFT_OFFSET + Table::RIGHT_OFFSET, MenuBar::HEIGHT));
}
void Level::M_initializeBackground()
{
    m_background.setPosition(0.0f, MenuBar::HEIGHT);
    m_background.setSize(m_table.getSize() + sf::Vector2f(Table::LEFT_OFFSET + Table::RIGHT_OFFSET, Table::TOP_OFFSET + Table::BOTTOM_OFFSET));
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
            throw Exception(Error::CreateWindow, Error::messages[Error::CreateWindow]);
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

/* onMouseButtonPressed */
void Level::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{
    if(m_game_over == false && m_table.contains(event.x, event.y) == true)
        M_onMouseButtonPressedTable(event);
    else if(m_header.smiley.contains(m_header.getRelativePoint(event.x, event.y)) == true)
        M_onMouseButtonPressedSmiley(event);
    else if(m_menu_bar.contains(event.x, event.y) == true)
        m_menu_bar.onMouseButtonPressed(event);
}

void Level::M_onMouseButtonPressedTable(const sf::Event::MouseButtonEvent event)
{
    m_header.moves += m_table.onMouseButtonPressed(event);

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
        win();
    else if(status == Status::Lost)
        lose();
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
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
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

    if(m_table.load(file, m_textures, m_game_over) == false)
        return false;

    M_initializeMenu();
    M_initializeBackground();
    M_initializeHeader();
    m_table.setPosition(m_background.getPosition() + m_background.table_position);
    M_resizeWindow();

    if(m_game_over == Status::Won)
        m_header.smiley.setWin();
    else if (m_game_over == Status::Lost)
        m_header.smiley.setLose();

    return true;
}
