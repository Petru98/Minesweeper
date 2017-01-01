#include "GameMenu.hpp"

GameMenu::GameMenu() : m_background(), m_lines(), m_columns(), m_mines()
{}

GameMenu::~GameMenu()
{}

void GameMenu::initialize(const sf::Texture& textures)
{
    using namespace Resources::Textures::Rectangles;

    m_buttons[Buttons::Beginner].initialize(textures, text[Indexes::TextBeginner]);
    m_buttons[Buttons::Intermediate].initialize(textures, text[Indexes::TextIntermediate]);
    m_buttons[Buttons::Expert].initialize(textures, text[Indexes::TextExpert]);
    m_buttons[Buttons::NewGame].initialize(textures, text[Indexes::TextNewGame]);
}

void GameMenu::onClosed()
{}

void GameMenu::onResized(const sf::Event::SizeEvent& event)
{}

void GameMenu::onLostFocus()
{}

void GameMenu::onGainedFocus()
{}

void GameMenu::onTextEntered(const sf::Event::TextEvent& event)
{}

void GameMenu::onKeyPressed(const sf::Event::KeyEvent& event)
{}

void GameMenu::onKeyReleased(const sf::Event::KeyEvent& event)
{}

void GameMenu::onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event)
{}

void GameMenu::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{

}

void GameMenu::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{

}

void GameMenu::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{

}

void GameMenu::onMouseEntered()
{}

void GameMenu::onMouseLeft()
{}
