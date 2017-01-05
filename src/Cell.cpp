#include "Cell.hpp"
#include <cassert>

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Cell::Cell() : m_sprite(), m_mines_count(0), m_state(0)
{}
Cell::~Cell()
{}

void Cell::initialize(const sf::Texture& textures)
{
    this->setTexture(textures);
    this->reset();
}
void Cell::setTexture(const sf::Texture& textures)
{
    m_sprite.setTexture(textures);
}

void Cell::reset()
{
    using namespace Resources::Textures::Rectangles;

    m_sprite.setTextureRect(cell[Indexes::CellNormal]);
    m_mines_count = 0;
    m_state = 0;
}

bool Cell::reveal(const bool game_over)
{
    if(game_over == true)
        return M_revealGameOver();
    return M_revealInGame();
}
bool Cell::M_revealGameOver()
{
    using namespace Resources::Textures::Rectangles;

    if(this->isRevealed() == true)
        return false;

    if(this->hasMine() == true)
    {
        if(this->hasFlag() == false)
            m_sprite.setTextureRect(cell[Indexes::CellMine]);
    }
    else
    {
        if(this->hasFlag() == true)
            m_sprite.setTextureRect(cell[Indexes::CellMineWrong]);
    }
    return true;
}
bool Cell::M_revealInGame()
{
    using namespace Resources::Textures::Rectangles;

    if(this->canReveal() == false)
        return false;

    m_state.set(Flags::IsRevealed);

    if(this->hasMine() == true)
        m_sprite.setTextureRect(cell[Indexes::CellMineClicked]);
    else
        m_sprite.setTextureRect(cell[m_mines_count]);

    return true;
}

void Cell::setMine()
{
    m_state.set(Flags::HasMine);
    this->incrementMinesCount();
}
void Cell::incrementMinesCount()
{
    ++m_mines_count;
}
bool Cell::toggleFlag()
{
    using namespace Resources::Textures::Rectangles;

    if(this->isRevealed() == true)
        return false;

    m_state.toggle(Flags::HasFlag);

    if(this->hasFlag() == true)
        m_sprite.setTextureRect(cell[Indexes::CellFlag]);
    else
        m_sprite.setTextureRect(cell[Indexes::CellNormal]);

    return true;
}
void Cell::setState(Flags8 state)
{
    m_state = state & (Flags::HasMine | Flags::HasFlag | Flags::IsRevealed);
}
void Cell::setTextureRect(const sf::IntRect& rect)
{
    m_sprite.setTextureRect(rect);
}

bool Cell::hasMine()const            {return m_state.get(Flags::HasMine);}
bool Cell::hasFlag()const            {return m_state.get(Flags::HasFlag);}
bool Cell::isRevealed()const         {return m_state.get(Flags::IsRevealed);}
bool Cell::canPress()const           {return this->isRevealed() == false && this->hasFlag() == false && this->isPressed() == false;}
bool Cell::canRelease()const         {return this->isPressed() == true;}
bool Cell::canReveal()const          {return this->isRevealed() == false && this->hasFlag() == false;}

sf::Uint8          Cell::getMinesCount()const  {return m_mines_count;}
Flags8             Cell::getState()const       {return m_state & (~Flags::IsPressed);}
const sf::IntRect& Cell::getTextureRect()const {return m_sprite.getTextureRect();}

bool Cell::press()
{
    using namespace Resources::Textures::Rectangles;

    if(this->canPress() == false)
        return false;

    m_state.set(Flags::IsPressed);
    m_sprite.setTextureRect(cell[Indexes::CellEmpty]);
    return true;
}
bool Cell::release()
{
    using namespace Resources::Textures::Rectangles;

    if(this->canRelease() == false)
        return false;

    m_state.reset(Flags::IsPressed);
    m_sprite.setTextureRect(cell[Indexes::CellNormal]);
    return true;
}
bool Cell::isPressed()const
{
    using namespace Resources::Textures::Rectangles;
    return m_state.get(Flags::IsPressed);
}

sf::Vector2f Cell::getSize()const
{
    return sf::Vector2f(this->WIDTH, this->HEIGHT);
}
