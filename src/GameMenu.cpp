#include "GameMenu.hpp"

void GameMenu::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(m_background, states);
    target.draw(m_lines, states);
    target.draw(m_columns, states);
    target.draw(m_mines, states);

    for(std::size_t i = 0; i < Buttons::Count; ++i)
        target.draw(m_buttons[i], states);
}

GameMenu::GameMenu() : m_background(), m_lines(), m_columns(), m_mines(), m_focus(nullptr)
{}

GameMenu::~GameMenu()
{}

void GameMenu::initialize(const sf::Texture& textures)
{
    using namespace Resources::Textures::Rectangles;
    using namespace Resources::Textures;

    PushButton& beginner     = m_buttons[Buttons::Beginner];
    PushButton& intermediate = m_buttons[Buttons::Intermediate];
    PushButton& expert       = m_buttons[Buttons::Expert];
    PushButton& new_game     = m_buttons[Buttons::NewGame];

    beginner.initialize(textures, text[Indexes::TextBeginner]);
    intermediate.initialize(textures, text[Indexes::TextIntermediate]);
    expert.initialize(textures, text[Indexes::TextExpert]);
    new_game.initialize(textures, text[Indexes::TextNewGame]);

    beginner.setPosition(3.0f, 3.0f);
    intermediate.setPosition(beginner.getPosition() + sf::Vector2f(beginner.getSize().x + 8.0f, 0.0f));
    expert.setPosition(intermediate.getPosition() + sf::Vector2f(intermediate.getSize().x + 8.0f, 0.0f));
    new_game.setPosition(sf::Vector2f(3.0f, 3.0f + TEXT_HEIGHT + 3.0f + m_lines.getSize().y + 8.0f));

    m_focus = &m_lines;
    m_focus->showCursor();
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
