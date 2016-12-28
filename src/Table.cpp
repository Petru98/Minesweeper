#include "Table.hpp"

#include "random.hpp"

Table::Table() : m_table(), m_mines(0), m_flags(0)
{}

bool Table::create(const sf::Uint8 lines, const sf::Uint8 columns, const sf::Uint16 mines, const sf::Texture& textures)
{
    if(m_table.create(lines, columns) == false)
        return false;
    M_initializeCells(textures);
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
