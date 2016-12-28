#include "Cell.hpp"

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Cell::Cell() : m_sprite(), m_mines_count(0), m_has_mine(false), m_revealed(false)
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
    m_revealed = false;
}

void Cell::setMine()
{
    m_has_mine = 0;
}
bool Cell::reveal(const bool game_over = false)
{
    using namespace Resources::Textures::Rectangles;

    if(game_over == true)
        m_sprite.setTextureRect(cell[Indexes::CellMine]);
    else if(m_revealed == false)
    {
        m_revealed = true;
        if(m_has_mine == true)
        {
            m_sprite.setTextureRect(cell[Indexes::CellMineClicked]);
            return false;
        }
        m_sprite.setTextureRect(cell[m_mines_count]);
    }
    return true;
}
void Cell::press()
{
    if(m_revealed == false)
    {
        using namespace Resources::Textures::Rectangles;
        m_sprite.setTextureRect(cell[Indexes::CellEmpty]);
    }
}
void Cell:release()
{
    if(m_revealed == false)
    {
        using namespace Resources::Textures::Rectangles;
        m_sprite.setTextureRect(cell[Indexes::CellNormal]);
    }
}

bool Cell::hasMine()const
{
    return m_has_mine;
}
bool Cell::isRevealed()const
{
    return m_isRevealed;
}
