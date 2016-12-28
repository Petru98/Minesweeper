#ifndef MINESWEEPER_TABLE_HPP_INCLUDED
#define MINESWEEPER_TABLE_HPP_INCLUDED

#include "Matrix.hpp"
#include "Cell.hpp"
#include "Exception.hpp"

class Table : public sf::Drawable, public sf::Transformable
{
private:

    static constexpr std::size_t DIRECTIONS_COUNT = 8;
    static const sf::Vector2i directions[DIRECTIONS_COUNT];

    Matrix<Cell> m_table;
    sf::Uint16   m_mines;
    sf::Uint16   m_flags;

    void M_initializeCells(const sf::Texture& textures);
    void M_placeMines(sf::Uint16 mines);

    sf::Vector2i M_getCellPositionFromPixels(const int x, const int y)const;
    void M_pressAdjacentCells(const sf::Vector2i index);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Table();

    bool create(const sf::Uint16 lines, const sf::Uint16 columns, const sf::Uint16 mines);
    void destroy();

    bool isCreated()const;

    sf::Uint16 lines()const;
    sf::Uint16 columns()const;
    sf::Uint16 flags()const;

    sf::Vector2f getSize()const;

    Cell* operator[] (const sf::Uint16 index);
    const Cell* operator[] (const sf::Uint16 index)const;

    template<typename T> bool contains(const T x, const T y)const;
    template<typename T> bool outOfBounds(const T line, const T column)const;

    void onMouseButtonPressed(const sf::Event::MouseButtonEvent&);
    void onMouseButtonReleased(const sf::Event::MouseButtonEvent&);
    void onMouseMoved(const sf::Event::MouseMoveEvent&);
};

#endif
