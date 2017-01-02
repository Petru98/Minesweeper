#include "GameMenu.hpp"
#include "Level.hpp"
#include "string.hpp"

const sf::Vector2f GameMenu::TEXT_OFFSET = {4.0f, 4.0f};

void GameMenu::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    target.draw(m_background, states);
    target.draw(m_lines, states);
    target.draw(m_columns, states);
    target.draw(m_mines, states);

    for(std::size_t i = 0; i < Buttons::Count; ++i)
        target.draw(m_buttons[i], states);
}

GameMenu::GameMenu(Level* level) : m_background(), m_lines(), m_columns(), m_mines(), m_focus(nullptr), m_level(level), m_open(false)
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

    m_lines.initialize(textures);
    m_columns.initialize(textures);
    m_mines.initialize(textures);

    beginner.setPosition(this->TEXT_OFFSET);
    intermediate.setPosition(beginner.getPosition() + sf::Vector2f(beginner.getSize().x + this->TEXT_INNER_SPACE, 0.0f));
    expert.setPosition(intermediate.getPosition() + sf::Vector2f(intermediate.getSize().x + this->TEXT_INNER_SPACE, 0.0f));

    m_lines.setPosition(sf::Vector2f(this->TEXT_OFFSET.x, beginner.getPosition().y + beginner.getSize().y + this->VERTICAL_SPACE));
    m_columns.setPosition(sf::Vector2f(m_lines.getPosition().x + m_lines.getSize().x + this->TEXTBOX_INNER_SPACE, m_lines.getPosition().y));
    m_mines.setPosition(sf::Vector2f(m_columns.getPosition().x + m_columns.getSize().x + this->TEXTBOX_INNER_SPACE, m_columns.getPosition().y));
    new_game.setPosition(this->TEXT_OFFSET + sf::Vector2f(0.0f, m_lines.getPosition().y + m_lines.getSize().y + 8.0f));

    m_background.setOutlineThickness(-1.0f);
    m_background.setOutlineColor(sf::Color::Black);
    m_background.setFillColor(sf::Color(236, 233, 216));
    m_background.setSize(sf::Vector2f(expert.getPosition().x + expert.getSize().x + this->TEXT_OFFSET.x,
                                      new_game.getPosition().y + new_game.getSize().y + this->TEXT_OFFSET.y));

    m_focus = &m_lines;
    m_focus->showCursor();
}

void GameMenu::open()
{
    m_open = true;
}
void GameMenu::close()
{
    m_open = false;
}
bool GameMenu::isOpen()const
{
    return m_open;
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
{
    if(event.unicode == '\33')
        this->close();
    else
        m_focus->onTextEntered(event);
}

void GameMenu::onKeyPressed(const sf::Event::KeyEvent& event)
{}

void GameMenu::onKeyReleased(const sf::Event::KeyEvent& event)
{}

void GameMenu::onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event)
{}

void GameMenu::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{
    float relative_x = event.x - this->getPosition().x;
    float relative_y = event.y - this->getPosition().y;

    if(m_lines.contains(relative_x, relative_y) == true)
        M_setFocus(m_lines);
    else if(m_columns.contains(relative_x, relative_y) == true)
        M_setFocus(m_columns);
    else if(m_mines.contains(relative_x, relative_y) == true)
        M_setFocus(m_mines);
    else if(m_buttons[Buttons::Beginner].contains(relative_x, relative_y) == true)
        m_buttons[Buttons::Beginner].press();
    else if(m_buttons[Buttons::Intermediate].contains(relative_x, relative_y) == true)
        m_buttons[Buttons::Intermediate].press();
    else if(m_buttons[Buttons::Expert].contains(relative_x, relative_y) == true)
        m_buttons[Buttons::Expert].press();
    else if(m_buttons[Buttons::NewGame].contains(relative_x, relative_y) == true)
        m_buttons[Buttons::NewGame].press();
}
void GameMenu::M_setFocus(TextBoxBase& text_box)
{
    m_focus->hideCursor();
    m_focus = &text_box;
    m_focus->showCursor();
}

void GameMenu::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{
    float relative_x = event.x - this->getPosition().x;
    float relative_y = event.y - this->getPosition().y;

    if(m_buttons[Buttons::Beginner].contains(relative_x, relative_y) == true)
    {
        m_buttons[Buttons::Beginner].release();
        char buffer[4];
        m_lines.setText(Uint16ToString(Level::beginner.lines, buffer));
        m_columns.setText(Uint16ToString(Level::beginner.columns, buffer));
        m_mines.setText(Uint16ToString(Level::beginner.mines, buffer));
    }
    else if(m_buttons[Buttons::Intermediate].contains(relative_x, relative_y) == true)
    {
        m_buttons[Buttons::Intermediate].release();
        char buffer[4];
        m_lines.setText(Uint16ToString(Level::intermediate.lines, buffer));
        m_columns.setText(Uint16ToString(Level::intermediate.columns, buffer));
        m_mines.setText(Uint16ToString(Level::intermediate.mines, buffer));
    }
    else if(m_buttons[Buttons::Expert].contains(relative_x, relative_y) == true)
    {
        m_buttons[Buttons::Expert].release();
        char buffer[4];
        m_lines.setText(Uint16ToString(Level::expert.lines, buffer));
        m_columns.setText(Uint16ToString(Level::expert.columns, buffer));
        m_mines.setText(Uint16ToString(Level::expert.mines, buffer));
    }
    else if(m_buttons[Buttons::NewGame].contains(relative_x, relative_y) == true)
    {
        m_buttons[Buttons::NewGame].release();
        Level::Difficulty difficulty;
        difficulty.lines   = stringToUint16(m_lines.getText());
        difficulty.columns = stringToUint16(m_columns.getText());
        difficulty.mines   = stringToUint16(m_mines.getText());
        m_level->create(difficulty);
        this->close();
    }
}

void GameMenu::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{

}

void GameMenu::onMouseEntered()
{}

void GameMenu::onMouseLeft()
{}
