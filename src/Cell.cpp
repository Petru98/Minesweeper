#include "Cell.hpp"

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Cell::Cell() : m_sprite(), m_mines_count(0), m_has_mine(false), m_flag(false), m_revealed(false)
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
    m_has_mine = false;
    m_flag     = false;
    m_revealed = false;
}

bool Cell::reveal(const bool game_over)
{
    using namespace Resources::Textures::Rectangles;

    if(this->canReveal() == true)
    {
        if(game_over == true)
            M_revealGameOver();
        else if(this->hasFlag() == false)
            M_revealInGame();
        return true;
    }
    return false;
}
void Cell::M_revealGameOver()
{
    using namespace Resources::Textures::Rectangles;

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
}
void Cell::M_revealInGame()
{
    using namespace Resources::Textures::Rectangles;
    m_revealed = true;

    if(this->hasMine() == true)
        m_sprite.setTextureRect(cell[Indexes::CellMineClicked]);
    else
        m_sprite.setTextureRect(cell[m_mines_count]);
}

void Cell::setMine()
{
    m_has_mine = true;
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

    if(this->hasFlag() == false)
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

sf::Uint8 Cell::getMinesCount()const {return m_mines_count;}

bool Cell::hasMine()const            {return m_has_mine;}
bool Cell::hasFlag()const            {return m_flag;}
bool Cell::isRevealed()const         {return m_revealed;}
bool Cell::canPress()const           {return m_revealed == false && m_flag == false && this->isPressed() == false;}
bool Cell::canRelease()const         {return this->isPressed() == true;}
bool Cell::canReveal()const          {return m_revealed == false && m_flag == false;}

bool Cell::press()
{
    using namespace Resources::Textures::Rectangles;

    if(this->canPress() == true)
    {
        m_sprite.setTextureRect(cell[Indexes::CellEmpty]);
        return true;
    }
    return false;
}
bool Cell::release()
{
    using namespace Resources::Textures::Rectangles;

    if(this->canRelease() == true)
    {
        m_sprite.setTextureRect(cell[Indexes::CellNormal]);
        return true;
    }
    return false;
}
bool Cell::isPressed()const
{
    using namespace Resources::Textures::Rectangles;
    return m_revealed == false && m_sprite.getTextureRect() == cell[Indexes::CellEmpty];
}

sf::Vector2f Cell::getSize()const
{
    return sf::Vector2f(this->WIDTH, this->HEIGHT);
}
