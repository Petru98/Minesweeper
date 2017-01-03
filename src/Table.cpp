#include "Table.hpp"

#include "random.hpp"

const sf::Vector2i Table::INVALID_INDEX = {-1, -1};
const sf::Vector2i Table::directions[Table::DIRECTIONS_COUNT] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};

void Table::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            target.draw(m_table[i][j], states);
}

Table::Table() : m_table(), m_pressed_cell_index(-1,-1), m_mines(0), m_cells_left(0)
{}
Table::~Table()
{}

bool Table::create(const sf::Uint16 lines, const sf::Uint16 columns, const sf::Uint16 mines, const sf::Texture& textures)
{
    if(m_table.create(lines, columns) == false)
        return false;

    M_initializeCells(textures);
    M_placeMines(mines);

    m_mines = mines;
    m_cells_left = lines * columns;
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
            position.x += Cell::WIDTH;
        }
        position.y += Cell::HEIGHT;
        position.x = 0.0f;
    }
}
void Table::M_placeMines(sf::Uint16 mines)
{
    while(mines > 0)
    {
        const std::size_t line = Random::rand() % m_table.lines();
        const std::size_t column = Random::rand() % m_table.columns();

        if(m_table[line][column].hasMine() == false)
        {
            m_table[line][column].setMine();
            --mines;

            for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
            {
                const std::size_t line_adjacent = line + directions[i].y;
                const std::size_t column_adjacent = column + directions[i].x;

                if(m_table.outOfBounds(line_adjacent, column_adjacent) == false)
                    m_table[line_adjacent][column_adjacent].incrementMinesCount();
            }
        }
    }
}

void Table::destroy()
{
    m_table.destroy();
    m_mines = 0;
    m_cells_left = 0;
}

sf::Uint16 Table::lines()const      {return m_table.lines();}
sf::Uint16 Table::columns()const    {return m_table.columns();}
sf::Uint16 Table::mines()const      {return m_mines;}
sf::Uint16 Table::cellsLeft()const  {return m_cells_left;}

bool Table::isCreated()const
{
    return m_table.isCreated();
}
bool Table::outOfBounds(const int line, const int column)const
{
    return m_table.outOfBounds(line, column);
}

sf::Vector2f Table::getSize()const
{
    return sf::Vector2f(Cell::WIDTH * m_table.columns(), Cell::HEIGHT * m_table.lines());
}

Cell* Table::operator[] (const sf::Uint16 index)            {return m_table[index];}
const Cell* Table::operator[] (const sf::Uint16 index)const {return m_table[index];}

/* onMouseButtonPressed */
void Table::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{
    const sf::Vector2i index = M_getCellIndexAtPosition(event.x, event.y);

    if(event.button == sf::Mouse::Left)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == false)
            M_pressCell(index);
        else
            M_pressArea(index);
    }
    else if(event.button == sf::Mouse::Right)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
            M_pressArea(index);
        else
            M_toggleFlag(index);
    }
}

sf::Vector2i Table::M_getCellIndexAtPosition(const int x, const int y)const
{
    const sf::Vector2f position = this->getPosition();
    return sf::Vector2i((x - position.x) / Cell::WIDTH, (y - position.y) / Cell::HEIGHT);
}

bool Table::M_toggleFlag(const sf::Vector2i index)
{
    m_table[index.y][index.x].toggleFlag();
    return m_table[index.y][index.x].hasFlag();
}

void Table::M_pressCell(const sf::Vector2i index)
{
    if(m_table[index.y][index.x].press() == true)
        m_pressed_cell_index = index;
}
void Table::M_pressArea(const sf::Vector2i index)
{
    m_table[index.y][index.x].press();
    m_pressed_cell_index = index;
    M_pressAdjacentCells(index);
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

/* onMouseButtonReleased */
int Table::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{
    if(m_pressed_cell_index != this->INVALID_INDEX)
    {
        if(event.button == sf::Mouse::Left)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
                return M_revealFromArea(m_pressed_cell_index);
            else
            {
                M_revealFromCell(m_pressed_cell_index);
                if(m_table[m_pressed_cell_index.y][m_pressed_cell_index.x].hasMine() == true)
                    return -1;
            }
            m_pressed_cell_index = this->INVALID_INDEX;
        }
        else if(event.button == sf::Mouse::Right)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
                M_releaseAdjacentCells(m_pressed_cell_index);
        }
    }

    return m_cells_left == m_mines;
}

sf::Uint16 Table::M_countAdjacentFlags(const sf::Vector2i index)
{
    sf::Uint16 flags_count = 0;
    for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
    {
        const sf::Vector2i index_adjacent = index + directions[i];

        if(m_table.outOfBounds(index_adjacent.y, index_adjacent.x) == false)
            if(m_table[index_adjacent.y][index_adjacent.x].hasFlag() == true)
                ++flags_count;
    }
    return flags_count;
}

void Table::M_releaseCell(const sf::Vector2i index)
{
    m_table[index.y][index.x].release();
}
void Table::M_releaseArea(const sf::Vector2i index)
{
    m_table[index.y][index.x].release();
    M_releaseAdjacentCells(index);
}
void Table::M_releaseAdjacentCells(const sf::Vector2i index)
{
    for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
    {
        const int line = index.y + directions[i].y;
        const int column = index.x + directions[i].x;

        if(m_table.outOfBounds(line, column) == false)
            m_table[line][column].release();
    }
}

void Table::M_revealFromCell(const sf::Vector2i index)
{
    if(m_table.outOfBounds(index.y, index.x) == false)
    {
        if(m_table[index.y][index.x].reveal() == true)
        {
            --m_cells_left;

            if(m_table[index.y][index.x].getMinesCount() == 0)
            {
                for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
                    M_revealFromCell(index + directions[i]);
            }
        }
    }
}
int Table::M_revealFromArea(const sf::Vector2i index)
{
    const Cell& cell = m_table[index.y][index.x];

    if(cell.isRevealed() == true && M_countAdjacentFlags(index) == cell.getMinesCount())
        return M_revealAdjacentCells(index);

    M_releaseArea(index);
    return m_cells_left == m_mines;
}
int Table::M_revealAdjacentCells(const sf::Vector2i index)
{
    bool revealed_mines = false;

    for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
    {
        const sf::Vector2i index_adjacent = {index.x + directions[i].x, index.y + directions[i].y};

        if(m_table.outOfBounds(index_adjacent.y, index_adjacent.x) == false)
        {
            const Cell& cell = m_table[index_adjacent.y][index_adjacent.x];

            if(cell.canReveal() == true)
            {
                M_revealFromCell(index_adjacent);
                if(cell.hasMine() == true)
                    revealed_mines = true;
            }
        }
    }

    if(revealed_mines == true)
        return -1;
    return m_cells_left == m_mines;
}

/* onMouseMoved */
bool Table::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{
    if(m_pressed_cell_index != this->INVALID_INDEX)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == false)
            M_releaseCell(m_pressed_cell_index);
        else
            M_releaseArea(m_pressed_cell_index);

        m_pressed_cell_index = this->INVALID_INDEX;
    }

    if(this->contains(event.x, event.y) == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
    {
        const sf::Vector2i index = M_getCellIndexAtPosition(event.x, event.y);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
            M_pressArea(index);
        else
            M_pressCell(index);

        return true;
    }

    return false;
}
