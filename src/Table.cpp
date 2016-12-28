#include "Table.hpp"

#include "random.hpp"

const sf::Vector2i Table::directions[Level::DIRECTIONS_COUNT] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};

void Table::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            target.draw(m_table[i][j], states);
}

Table::Table() : m_table(), m_mines(0), m_flags(0)
{
}

bool Table::create(const sf::Uint16 lines, const sf::Uint16 columns, const sf::Uint16 mines, const sf::Texture& textures)
{
    if(m_table.create(lines, columns) == false)
        return false;
    M_initializeCells(textures);
    M_placeMines(mines);
    m_mines = mines;
    m_flags = 0;
    return true;
}
void Table::M_initializeCells(const sf::Texture& textures)
{
    sf::Vector2f position(0.0f, 0.0f);

    for(std::size_t i = 0; i < m_table.lines(); ++i)
    {
        for(std::size_t j = 0; j < m_table.columns(); ++j)
        {
            m_table[i][j].initialize(textures);
            m_table[i][j].setPosition(position);
            position.x += Cell::width;
        }
        position.y += Cell::height;
        position.x = 0.0f;
    }
}
void Table::M_placeMines(sf::Uint16 mines)
{
    while(mines > 0)
    {
        const std::size_t line = Random::rand() % m_table.lines();
        const std::size_t column = Random::rand() % m_table.columns();

        if(m_cells[line][column].hasMine() == false)
        {
            m_cells[line][column].setMine();
            --difficulty.mines;

            for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
            {
                const std::size_t line_adjacent = line + directions[i].y;
                const std::size_t column_adjacent = column + directions[i].x;

                if(m_cells.outOfBounds(line_adjacent, column_adjacent) == false)
                    m_cells[line_adjacent][column_adjacent].incrementMinesCount();
            }
        }
    }
}

void Table::destroy()
{
    m_table.destroy();
    m_mines = 0;
    m_flags = 0;
}

bool Table::isCreated()const     {return m_table.isCreated();}

sf::Uint16 Table::lines()const   {return m_table.lines();}
sf::Uint16 Table::columns()const {return m_table.columns();}
sf::Uint16 Table::mines()const   {return m_mines;}
sf::Uint16 Table::flags()const   {return m_flags;}

sf::Vector2f Table::getSize()const
    {return sf::Vector2f(Cell::width * m_table.columns(), Cell::height * m_table.lines());}

Cell* Table::operator[] (const sf::Uint16 index)            {return m_table[index];}
const Cell* Table::operator[] (const sf::Uint16 index)const {return m_table[index];}

template<typename T> bool Table::contains(const T x, const T y)const
{
    const sf::Vector2f position = this->getPosition();
    const float right = position.x + Cell::width * m_table.columns();
    const float bottom = position.y + Cell::height * m_table.lines();

    return x >= position.x && x < right && y >= position.y && y < bottom;
}
template<typename T> bool Table::outOfBounds(const T line, const T column)const
    {return m_table.outOfBounds(line, column);}

/* Events */
void Table::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{

}
sf::Vector2i Table::M_getCellPositionFromPixels(const int x, const int y)const
{
    return sf::Vector2i((x - m_cells_area.left) / Cell::width, (y - m_cells_area.top) / Cell::height);
}
void Table::M_pressAdjacentCells(const sf::Vector2i index)
{
    for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
    {
        const int line = index.y + directions[i].y;
        const int column = index.x + directions[i].x;
        if(m_table.outOfBounds(line, column) == false)
            m_table[line][column].press();
    }
}

void Table::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{

}

void Table::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{

}
