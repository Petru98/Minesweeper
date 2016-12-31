#include "Menu.hpp"
#include "textures.hpp"

const sf::Vector2f Menu::ITEM_OFFSET = {6.0f, 4.0f};

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_background, states);
    target.draw(game_button, states);
}

Menu::Menu() : m_background(), game_button()
{
    m_background.setFillColor(sf::Color(236, 233, 216));
}

Menu::~Menu()
{}

void Menu::initialize(const sf::Texture& textures)
{
    using namespace Resources::Textures::Rectangles;
    game_button.initialize(textures, text[Indexes::TextGame]);
    game_button.setPosition(this->ITEM_OFFSET);
    m_background.setOutlineThickness(-1.0f);
    m_background.setOutlineColor(sf::Color(192, 192, 192));
}

sf::Vector2f Menu::getSize()const
{
    return m_background.getSize();
}
