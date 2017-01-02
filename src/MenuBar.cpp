#include "MenuBar.hpp"
#include "textures.hpp"

const sf::Vector2f MenuBar::ITEM_OFFSET = {6.0f, 4.0f};

void MenuBar::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_background, states);
    target.draw(game_button, states);
}

MenuBar::MenuBar() : m_background(), game_button()
{
    m_background.setFillColor(sf::Color(236, 233, 216));
}
MenuBar::~MenuBar()
{}

void MenuBar::setTexture(const sf::Texture& textures)
{
    using namespace Resources::Textures::Rectangles;

    game_button.setPosition(this->ITEM_OFFSET);
    game_button.setTexture(textures, text[Indexes::TextGame]);
    m_background.setOutlineThickness(-1.0f);
    m_background.setOutlineColor(sf::Color(192, 192, 192));
}

void MenuBar::setSize(const float width, const float height)
{
    m_background.setSize(sf::Vector2f(width, height));
}
void MenuBar::setSize(const sf::Vector2f size)
{
    m_background.setSize(size);
}

sf::Vector2f MenuBar::getSize()const
{
    return m_background.getSize();
}
