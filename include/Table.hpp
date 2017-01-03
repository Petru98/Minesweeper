#ifndef MINESWEEPER_TABLE_HPP_INCLUDED
#define MINESWEEPER_TABLE_HPP_INCLUDED

#include "RectangularObject.hpp"
#include "Smiley.hpp"
#include "Matrix.hpp"
#include "Cell.hpp"
#include "file.hpp"
#include "Exception.hpp"

class Table : public RectangularObject
{
public:
    static constexpr std::size_t LEFT_OFFSET = 12;
    static constexpr std::size_t TOP_OFFSET = 56;
    static constexpr std::size_t RIGHT_OFFSET = 8;
    static constexpr std::size_t BOTTOM_OFFSET = 8;

    static const sf::Vector2i INVALID_INDEX;

private:
    static constexpr std::size_t DIRECTIONS_COUNT = 8;
    static const sf::Vector2i directions[DIRECTIONS_COUNT];

    Matrix<Cell> m_table;
    sf::Vector2i m_pressed_cell_index;
    sf::Uint16   m_mines;
    sf::Uint16   m_cells_left;

    void M_initializeCells(const sf::Texture& textures);
    void M_placeMines(sf::Uint16 mines);

    sf::Vector2i M_getCellIndexAtPosition(const int x, const int y)const;
    sf::Uint16   M_countAdjacentFlags(const sf::Vector2i index);

    bool M_toggleFlag(const sf::Vector2i index);

    void M_pressCell(const sf::Vector2i index);
    void M_pressArea(const sf::Vector2i index);
    void M_pressAdjacentCells(const sf::Vector2i index);

    void M_releaseCell(const sf::Vector2i index);
    void M_releaseArea(const sf::Vector2i index);
    void M_releaseAdjacentCells(const sf::Vector2i index);

    void M_revealFromCell(const sf::Vector2i index);
    int  M_revealFromArea(const sf::Vector2i index);
    int  M_revealAdjacentCells(const sf::Vector2i index);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Table();
    virtual ~Table();

    bool create(const sf::Uint16 lines, const sf::Uint16 columns, const sf::Uint16 mines, const sf::Texture& textures);
    void destroy();

    sf::Uint16 lines()const;
    sf::Uint16 columns()const;
    sf::Uint16 mines()const;
    sf::Uint16 cellsLeft()const;

    bool isCreated()const;
    bool outOfBounds(const int line, const int column)const;

    virtual sf::Vector2f getSize()const;

    Cell* operator[] (const sf::Uint16 index);
    const Cell* operator[] (const sf::Uint16 index)const;

    void onMouseButtonPressed(const sf::Event::MouseButtonEvent&);
    int  onMouseButtonReleased(const sf::Event::MouseButtonEvent&);
    bool onMouseMoved(const sf::Event::MouseMoveEvent&);
};

#endif
