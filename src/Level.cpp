#include "Level.hpp"

#include "random.hpp"
#include <ctime>

const Level::Difficulty Level::beginner     = {9 , 9 , 10};
const Level::Difficulty Level::intermediate = {16, 16, 40};
const Level::Difficulty Level::expert       = {16, 30, 99};

/* Constructor / Destructor */
Level::Level(sf::RenderWindow& window, const sf::Texture& texture)
    : m_window(window), m_textures(texture), m_header(), m_table(), m_background(), m_game_over(false)
{
    Random::seed(std::time(nullptr));
}

Level::~Level()
{}

/* New game */
void Level::create(Level::Difficulty difficulty)
{
    difficulty = S_correctDifficulty(difficulty);
    if(m_table.create(difficulty.lines, difficulty.columns, difficulty.mines, m_textures) == false)
        throw Exception(Error::Allocate, Error::messages[Error::Allocate]);

    M_initializeBackground();
    M_initializeHeader();
    m_table.setPosition(m_background.getPosition() + m_background.table_position);

    M_resizeWindow();
    m_game_over = false;
}
Level::Difficulty Level::S_correctDifficulty(Level::Difficulty difficulty)
{
    if(difficulty.lines == 0)
        difficulty.lines = 1;
    if(difficulty.columns < 8)
        difficulty.columns = 8;
    if(difficulty.mines == 0)
        difficulty.mines = 1;
    else if(difficulty.mines >= difficulty.lines*difficulty.columns)
        difficulty.mines = difficulty.lines*difficulty.columns;
    return difficulty;
}
void Level::M_initializeBackground()
{
    m_background.setPosition(0.0f, s_MENU_HEIGHT);
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
    const sf::Vector2u size(m_background.getSize().x, m_background.getSize().y + s_MENU_HEIGHT);
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
    m_game_over = true;
    m_header.smiley.setWin();

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            if(m_table[i][j].isRevealed() == false && m_table[i][j].hasFlag() == false)
                m_table[i][j].toggleFlag();
}
void Level::lose()
{
    m_game_over = true;
    m_header.smiley.setLose();

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            m_table[i][j].reveal(true);
}

/* Draw */
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    //M_drawMenu(target, states);
    target.draw(m_background, states);
    target.draw(m_header, states);
    target.draw(m_table, states);
}

/* Events */
void Level::onClosed()
{
    m_table.destroy();
}

void Level::onResized(const sf::Event::SizeEvent& event)
{}

void Level::onLostFocus()
{}

void Level::onGainedFocus()
{}

void Level::onTextEntered(const sf::Event::TextEvent& event)
{}

void Level::onKeyPressed(const sf::Event::KeyEvent& event)
{}

void Level::onKeyReleased(const sf::Event::KeyEvent& event)
{}

void Level::onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event)
{}

void Level::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{
    if(m_table.contains(event.x, event.y) == true)
    {
        if(m_game_over == false)
        {
            m_table.onMouseButtonPressed(event);
            if(event.button == sf::Mouse::Left)
                m_header.smiley.setScared();
        }
    }
    else if(m_header.smiley.contains(event.x, event.y) == true)
        m_header.smiley.press();
}

void Level::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{
    if(m_table.contains(event.x, event.y) == true)
    {
        if(m_game_over == false)
        {
            int status = m_table.onMouseButtonReleased(event);

            if(status == 1)
                win();
            else if(status == -1)
                lose();
            else if(event.button == sf::Mouse::Left)
                m_header.smiley.reset();
        }
    }
    else if(m_header.smiley.contains(event.x, event.y) == true)
    {
        if(m_header.smiley.isPressed() == true)
            this->create(Difficulty(m_table.lines(), m_table.columns(), m_table.mines()));
    }
}

void Level::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
    {
        if(m_game_over == false && m_table.onMouseMoved(event) == true)
            m_header.smiley.setScared();
        else if(m_header.smiley.contains(event.x, event.y) == false)
            m_header.smiley.release();
    }
}

void Level::onMouseEntered()
{}

void Level::onMouseLeft()
{}
