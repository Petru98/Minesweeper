#ifndef MINESWEEPER_TABLE_HPP_INCLUDED
#define MINESWEEPER_TABLE_HPP_INCLUDED

#include "Matrix.hpp"
#include "Cell.hpp"
#include "Exception.hpp"

class Table : public sf::Drawable, public sf::Transformable
{
private:
    Matrix<Cell> m_table;
    sf::Uint16   m_mines;
    sf::Uint16   m_flags;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Table();

    bool create(const sf::Uint8 lines, const sf::Uint8 columns, const sf::Uint16 mines);
    void destroy();

    bool isCreated()const;

    sf::Uint8  lines()const;
    sf::Uint8  columns()const;
    sf::Uint16 flags()const;

    Cell* operator[] (const sf::Uint8 index);
    const Cell* operator[] (const sf::Uint8 index)const;

    template<typename U> bool outOfBounds(const U line, const U column);
};

#endif
