#include "Table.hpp"

#include "random.hpp"

const sf::Vector2i Level::directions[Level::DIRECTIONS_COUNT] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};

Table::Table() : m_table(), m_mines(0), m_flags(0)
{}

bool Table::create(const sf::Uint8 lines, const sf::Uint8 columns, const sf::Uint16 mines, const sf::Texture& textures)
{
    if(m_table.create(lines, columns) == false)
        return false;
    M_initializeCells(textures);
    M_placeMines(mines);
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

}

bool Table::isCreated()const    {return m_table.isCreated();}

sf::Uint8 Table::lines()const   {return m_table.lines();}
sf::Uint8 Table::columns()const {return m_table.columns();}
sf::Uint16 Table::mines()const  {return m_mines;}
sf::Uint16 Table::flags()const  {return m_flags;}

Cell* Table::operator[] (const sf::Uint8 index)            {return m_table[index];}
const Cell* Table::operator[] (const sf::Uint8 index)const {return m_table[index];}

template<typename U> bool Table::outOfBounds(const U line, const U column)
{
    return m_table.outOfBounds(line, column);
}
