#include "Cell.hpp"

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Cell::Cell() : m_sprite(), m_mines_count(0), m_has_mine(false), m_revealed(false)
{}

void Cell::initialize(const sf::Texture& texture)
{
    m_sprite.setTexture(texture);
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
bool Cell::hasMine()const
{
    return m_has_mine;
}
