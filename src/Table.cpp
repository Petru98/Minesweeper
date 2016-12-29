#include "Table.hpp"

#include "random.hpp"

const sf::Vector2i Table::directions[Table::DIRECTIONS_COUNT] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};

void Table::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            target.draw(m_table[i][j], states);
}

Table::Table() : m_table(), m_mines(0), m_cells_left(0), m_flags(0), m_pressed_cell_index(-1,-1)
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

        if(m_table[line][column].hasMine() == false)
        {
            m_table[line][column].setMine();
            m_table[line][column].incrementMinesCount();
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
    m_flags = 0;
}

bool Table::isCreated()const       {return m_table.isCreated();}

sf::Uint16 Table::lines()const     {return m_table.lines();}
sf::Uint16 Table::columns()const   {return m_table.columns();}
sf::Uint16 Table::mines()const     {return m_mines;}
sf::Uint16 Table::cellsLeft()const {return m_cells_left;}
sf::Uint16 Table::flags()const     {return m_flags;}

sf::Vector2f Table::getSize()const
    {return sf::Vector2f(Cell::width * m_table.columns(), Cell::height * m_table.lines());}

Cell* Table::operator[] (const sf::Uint16 index)            {return m_table[index];}
const Cell* Table::operator[] (const sf::Uint16 index)const {return m_table[index];}

/* Events */
void Table::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
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
sf::Vector2i Table::M_getCellPositionFromPixels(const int x, const int y)const
{
    const sf::Vector2f position = this->getPosition();
    return sf::Vector2i((x - position.x) / Cell::width, (y - position.y) / Cell::height);
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

int Table::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{
    const sf::Vector2i index = m_pressed_cell_index;

    if(m_table.outOfBounds(index.y, index.x) == false)
    {
        if(event.button == sf::Mouse::Left)
        {
            m_pressed_cell_index.x = -1;
            m_pressed_cell_index.y = -1;

            if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
                return M_revealFromArea(index);
            else
            {
                M_revealFromCell(index);
                return (m_table[index.y][index.x].hasMine() == false) ? 0 : -1;
            }
        }
        else if(event.button == sf::Mouse::Right)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
                M_releaseAdjacentCells(index);
        }
    }

    return 0;
}
int Table::M_revealFromArea(const sf::Vector2i index)
{
    Cell& cell = m_table[index.y][index.x];

    if(cell.isRevealed() == true && M_countAdjacentFlags(index) == cell.getMinesCount())
        return M_revealAdjacentCells(index);

    cell.release();
    M_releaseAdjacentCells(index);
    return 0;
}
sf::Uint16 Table::M_countAdjacentFlags(const sf::Vector2i index)
{
    sf::Uint16 flags_count = 0;
    for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
    {
        const sf::Vector2i next_index = index + directions[i];

        if(m_table.outOfBounds(next_index.y, next_index.x) == false)
        {
            Cell& cell = m_table[next_index.y][next_index.x];

            if(cell.hasFlag() == true)
                ++flags_count;
        }
    }
    return flags_count;
}
int Table::M_revealAdjacentCells(const sf::Vector2i index)
{
    int revealed_mine = 0;

    for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
    {
        const sf::Vector2i next_index = {index.x + directions[i].x, index.y + directions[i].y};

        if(m_table.outOfBounds(next_index.y, next_index.x) == false)
        {
            M_revealFromCell(next_index);
            Cell& cell = m_table[next_index.y][next_index.x];

            if(cell.hasMine() == true && cell.isRevealed() == true)
                revealed_mine = -1;
        }
    }

    return revealed_mine;
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
        Cell& cell = m_table[index.y][index.x];

        if(cell.isRevealed() == false && cell.hasFlag() == false)
        {
            cell.reveal();
            if(cell.getMinesCount() == 0)
                for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
                    M_revealFromCell(index + directions[i]);
        }
    }
}

void Table::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{
    if(m_table.outOfBounds(m_pressed_cell_index.y, m_pressed_cell_index.x) == false)
    {
        m_table[m_pressed_cell_index.y][m_pressed_cell_index.x].release();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
            M_releaseAdjacentCells(m_pressed_cell_index);
    }

    if(this->contains(event.x, event.y) == true)
    {
        const sf::Vector2i index = M_getCellPositionFromPixels(event.x, event.y);

        m_table[index.y][index.x].press();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
            M_pressAdjacentCells(index);

        m_pressed_cell_index = index;
    }
    else
    {
        m_pressed_cell_index.x = -1;
        m_pressed_cell_index.y = -1;
    }
}
