#include "Level.hpp"

#include "random.hpp"
#include <ctime>

const Level::Difficulty Level::easy   = {9 , 9 , 10};
const Level::Difficulty Level::medium = {16, 16, 40};
const Level::Difficulty Level::hard   = {16, 30, 99};

/* Constructor / Destructor */
Level::Level(sf::RenderWindow& window, const sf::Texture& texture)
    : m_window(window), m_textures(texture), m_cells_area(), m_background(), m_table(), m_pressed_cell_index(-1,-1)
{
    Random::seed(std::time(nullptr));
}

Level::~Level()
{}

/* New game */
void Level::create(Level::Difficulty difficulty)
{
    difficulty = S_correctDifficulty(difficulty);
    if(m_table.create(difficulty.lines, difficulty.columns, difficulty.mines) == false)
        throw Exception(Error::Allocate, Error::messages[Error::Allocate]);

    M_initializeBackground(difficulty);
    m_table.setPosition(m_background.getPosition() + m_background.table_position);
    M_resizeWindow();
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
void Level::M_initializeBackground(const Level::Difficulty difficulty)
{
    m_background.setPosition(0.0f, s_MENU_HEIGHT);
    m_background.setSize(Cell::width * difficulty.columns + Cell::LEFT_OFFSET + Cell::RIGHT_OFFSET,
                         Cell::height* difficulty.lines   + Cell::TOP_OFFSET  + Cell::BOTTOM_OFFSET);
}
/*
void Level::M_initializeCells()
{
    m_cells_area.left   = Cell::LEFT_OFFSET;
    m_cells_area.top    = s_MENU_HEIGHT + Cell::TOP_OFFSET;
    m_cells_area.width  = Cell::width * m_cells.columns();
    m_cells_area.height = Cell::height * m_cells.lines();

    for(std::size_t i = 0; i < m_cells.lines(); ++i)
        for(std::size_t j = 0; j < m_cells.columns(); ++j)
        {
            m_cells[i][j].initialize(m_textures);
            m_cells[i][j].setPosition(Cell::LEFT_OFFSET + j*Cell::width, s_MENU_HEIGHT + Cell::TOP_OFFSET + i*Cell::height);
        }
}
void Level::M_placeMines(Level::Difficulty difficulty)
{
    while(difficulty.mines > 0)
    {
        const std::size_t line = Random::rand() % difficulty.lines;
        const std::size_t column = Random::rand() % difficulty.columns;

        if(m_cells[line][column].hasMine() == false)
        {
            m_cells[line][column].setMine();
            --difficulty.mines;

            for(std::size_t i = 0; i < 8; ++i)
            {
                const std::size_t line_adjacent = line + direction[i].y;
                const std::size_t column_adjacent = column + direction[i].x;

                if(m_cells.outOfBounds(line_adjacent, column_adjacent) == false)
                    m_cells[line_adjacent][column_adjacent].incrementMinesCount();
            }
        }
    }
}
*/
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

}
void Level::lose()
{

}

/* Draw */
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    //M_drawMenu(target, states);
    target.draw(m_background, states);
    M_drawHead(target, states);
    target.draw(m_table, states);
}
void Level::M_drawHead(sf::RenderTarget& target, sf::RenderStates& states)const
{

}

/*
void Level::M_drawCells(sf::RenderTarget& target, sf::RenderStates& states)const
{
    for(std::size_t i = 0; i < m_cells.lines(); ++i)
        for(std::size_t j = 0; j < m_cells.columns(); ++j)
            target.draw(m_cells[i][j]);
}
*/


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
    if(m_cells_area.contains(event.x, event.y) == true)
    {
        const sf::Vector2i index = M_getCellPositionFromPixels(event.x, event.y);
        Cell& cell = m_table[index.y][index.x];

        if(event.button == sf::Mouse::Left && sf::Mouse::isButtonPressed(sf::Mouse::Right) == false)
        {
            if(cell.press() == true)
            m_pressed_cell_index = index;
        }
        else if(event.button == sf::Mouse::Right)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
            {
                m_pressed_cell_index = index;
                cell.press();
                M_pressAdjacentCells(index);
            }
            else
                cell.toggleFlag();
        }
    }
}
sf::Vector2i Level::M_getCellPositionFromPixels(const int x, const int y)const
{
    return sf::Vector2i((x - m_cells_area.left) / Cell::width, (y - m_cells_area.top) / Cell::height);
}
void Level::M_pressAdjacentCells(const sf::Vector2i index)
{
    for(std::size_t i = 0; i < 9; ++i)
    {
        const int line = index.y + direction[i].y;
        const int column = index.x + direction[i].x;
        if(m_table.outOfBounds(line, column) == false)
            m_table[line][column].press();
    }
}

void Level::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{
    if(m_table.outOfBounds(m_pressed_cell_index.y, m_pressed_cell_index.x) == false)
    {
        const sf::Vector2i index = m_pressed_cell_index;
        Cell& cell = m_table[index.y][index.x];

        if(event.button == sf::Mouse::Left)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == false)
            {
                cell.reveal();
                if(cell.isRevealed() == true && cell.hasMine() == true)
                    lose();
            }
            else
            {
                cell.reveal();
                M_revealAdjacentCells(index);
            }
        }
        else if(event.button == sf::Mouse::Right)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
                M_releaseAdjacentCells(index);
        }
    }
}
void Level::M_releaseAdjacentCells(const sf::Vector2i index)
{
    for(std::size_t i = 0; i < 8; ++i)
    {
        const int line = index.y + direction[i].y;
        const int column = index.x + direction[i].x;
        if(m_table.outOfBounds(line, column) == false)
            m_table[line][column].release();
    }
}
void Level::M_revealAdjacentCells(const sf::Vector2i index)
{
    for(std::size_t i = 0; i < 8; ++i)
    {
        const int line = index.y + direction[i].y;
        const int column = index.x + direction[i].x;
        if(m_table.outOfBounds(line, column) == false)
            m_table[line][column].reveal();
    }
}

void Level::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{

}

void Level::onMouseEntered()
{

}

void Level::onMouseLeft()
{

}
