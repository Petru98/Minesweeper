#include "Cell.hpp"
#include <cassert>

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Cell::Cell() : m_sprite(), m_mines_count(0), m_has_mine(false), m_flag(false), m_revealed(false)
{}

void Cell::initialize(const sf::Texture& textures)
{
    m_sprite.setTexture(textures);
    this->reset();
}

void Cell::reset()
{
    using namespace Resources::Textures::Rectangles;

    m_sprite.setTextureRect(cell[Indexes::CellNormal]);
    m_mines_count = 0;
    m_has_mine = false;
    m_flag     = false;
    m_revealed = false;
}

void Cell::reveal(const bool game_over)
{
    using namespace Resources::Textures::Rectangles;

    if(m_revealed == false)
    {
        if(game_over == true)
        {
            assert(m_has_mine == true);

            m_flag = false;
            m_sprite.setTextureRect(cell[Indexes::CellMine]);
        }
        else if(m_flag == false)
        {
            m_revealed = true;
            if(m_has_mine == true)
                m_sprite.setTextureRect(cell[Indexes::CellMineClicked]);
            else
                m_sprite.setTextureRect(cell[m_mines_count]);
        }
    }
}

void Cell::setMine()
{
    m_has_mine = true;
}
bool Cell::toggleFlag()
{
    using namespace Resources::Textures::Rectangles;

    if(m_revealed == true)
        return false;

    if(m_flag == false)
    {
        m_flag = true;
        m_sprite.setTextureRect(cell[Indexes::CellFlag]);
    }
    else
    {
        m_flag = false;
        m_sprite.setTextureRect(cell[Indexes::CellNormal]);
    }
    return true;
}

bool Cell::press()
{
    using namespace Resources::Textures::Rectangles;

    if(m_revealed == true || m_flag == true)
        return false;

    m_sprite.setTextureRect(cell[Indexes::CellEmpty]);
    return true;
}
bool Cell::release()
{
    using namespace Resources::Textures::Rectangles;

    if(m_revealed == true || m_flag == true)
        return false;

    m_sprite.setTextureRect(cell[Indexes::CellNormal]);
    return true;
}

bool Cell::hasMine()const
{
    return m_has_mine;
}
bool Cell::hasFlag()const
{
    return m_flag;
}
bool Cell::isRevealed()const
{
    return m_revealed;
}
