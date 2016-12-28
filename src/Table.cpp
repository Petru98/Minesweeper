#include "Table.hpp"

#include "random.hpp"

Table::Table() : m_table(), m_mines(0), m_flags(0)
{}

bool Table::create(const sf::Uint8 lines, const sf::Uint8 columns, const sf::Uint16 mines)
{
    if(m_table.create(lines, columns) == false)
        return false;
    return true;
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
