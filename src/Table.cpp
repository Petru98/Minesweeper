#include "Table.hpp"
#include "Level.hpp"
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

Table::Table() : m_table(), m_pressed_cell_index(this->INVALID_INDEX), m_mines(0), m_cells_left(0)
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

int Table::getStatus(const int normal_status)const
{
    return (m_cells_left == m_mines) ? (Level::Status::Won) : (normal_status);
}

sf::Vector2f Table::getSize()const
{
    return sf::Vector2f(Cell::WIDTH * m_table.columns(), Cell::HEIGHT * m_table.lines());
}

Cell* Table::operator[] (const sf::Uint16 index)            {return m_table[index];}
const Cell* Table::operator[] (const sf::Uint16 index)const {return m_table[index];}

/* onMouseButtonPressed */
int Table::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
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
            return M_toggleFlag(index);
    }
    return 0;
}

sf::Vector2i Table::M_getCellIndexAtPosition(const int x, const int y)const
{
    const sf::Vector2f position = this->getPosition();
    return sf::Vector2i((x - position.x) / Cell::WIDTH, (y - position.y) / Cell::HEIGHT);
}

int Table::M_toggleFlag(const sf::Vector2i index)
{
    Cell& cell = m_table[index.y][index.x];

    if(cell.isRevealed() == true)
        return 0;

    cell.toggleFlag();
    return ((cell.hasFlag() == true) ? 1 : -1);
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

            M_releaseCell(m_pressed_cell_index);
            M_revealFromCell(m_pressed_cell_index);
            if(m_table[m_pressed_cell_index.y][m_pressed_cell_index.x].hasMine() == true)
                return Level::Status::Lost;

            m_pressed_cell_index = this->INVALID_INDEX;
            return this->getStatus(1);
        }
        else if(event.button == sf::Mouse::Right)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
                M_releaseAdjacentCells(m_pressed_cell_index);
        }
    }

    return this->getStatus();
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
    M_releaseArea(index);

    if(cell.isRevealed() == true && cell.getMinesCount() > 0 && M_countAdjacentFlags(index) == cell.getMinesCount())
        return M_revealAdjacentCells(index);

    return this->getStatus();
}
int Table::M_revealAdjacentCells(const sf::Vector2i index)
{
    bool revealed_mines = false;
    bool revealed_cells = false;

    for(std::size_t i = 0; i < DIRECTIONS_COUNT; ++i)
    {
        const sf::Vector2i index_adjacent = index + directions[i];

        if(m_table.outOfBounds(index_adjacent.y, index_adjacent.x) == false)
        {
            const Cell& cell = m_table[index_adjacent.y][index_adjacent.x];

            if(cell.canReveal() == true)
            {
                M_revealFromCell(index_adjacent);
                revealed_cells = true;

                if(cell.hasMine() == true)
                    revealed_mines = true;
            }
        }
    }

    if(revealed_mines == true)
        return Level::Status::Lost;
    return this->getStatus(revealed_cells == true ? 1 : Level::Status::None);
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

/* Save/Load */
bool Table::save(File& file)const
{
    file.writeUint16(m_table.lines());
    file.writeUint16(m_table.columns());
    file.writeUint16(m_mines);
    file.writeUint16(m_cells_left);

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            M_saveCell(i, j, file);
    return true;
}
bool Table::M_saveCell(const std::size_t line, const std::size_t column, File& file)const
{
    const Cell& cell = m_table[line][column];

    file.writeUint8(cell.getMinesCount());
    file.writeUint8(static_cast<sf::Uint8>(cell.getState()));

    const sf::IntRect rect = cell.getTextureRect();
    file.writeUint16(rect.left);
    file.writeUint16(rect.top);
    file.writeUint16(rect.width);
    file.writeUint16(rect.height);

    return true;
}

bool Table::load(File& file, const sf::Texture& textures, bool game_over)
{
    const sf::Uint16 lines_count = file.readUint16();
    const sf::Uint16 columns_count = file.readUint16();

    if(m_table.create(lines_count, columns_count) == false)
        return false;

    m_mines = file.readUint16();
    m_cells_left = file.readUint16();

    for(std::size_t i = 0; i < m_table.lines(); ++i)
        for(std::size_t j = 0; j < m_table.columns(); ++j)
            M_loadCell(i, j, file, textures, game_over);
    return true;
}
bool Table::M_loadCell(const std::size_t line, const std::size_t column, File& file, const sf::Texture& textures, const bool game_over)
{
    Cell& cell = m_table[line][column];

    cell.setMinesCount(file.readUint8());
    cell.setState(file.readUint8());

    sf::IntRect rect;
    rect.left   = file.readUint16();
    rect.top    = file.readUint16();
    rect.width  = file.readUint16();
    rect.height = file.readUint16();

    cell.setTexture(textures);
    cell.setTextureRect(rect);
    cell.setPosition(sf::Vector2f(column * Cell::WIDTH, line * Cell::HEIGHT));

    return true;
}
