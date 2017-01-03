#ifndef MINESWEEPER_GAMEMENU_HPP_INCLUDED
#define MINESWEEPER_GAMEMENU_HPP_INCLUDED

#include "Scene.hpp"
#include "RectangularObject.hpp"
#include "SpriteButton.hpp"
#include "IntegralTextBox.hpp"

class Level;

class GameMenu : public Scene, public RectangularObject
{
private:
    struct Buttons
    {
        enum
        {
            Beginner,
            Intermediate,
            Expert,
            NewGame,

            Count
        };
    };

    static const sf::Vector2f TEXT_OFFSET;
    static constexpr float TEXT_INNER_SPACE = 6.0f;
    static constexpr float TEXTBOX_INNER_SPACE = 16.0f;
    static constexpr float VERTICAL_SPACE = 8.0f;

    sf::RectangleShape m_background;
    SpriteButton       m_buttons[Buttons::Count];
    IntegralTextBox<2> m_lines;
    IntegralTextBox<2> m_columns;
    IntegralTextBox<3> m_mines;
    TextBoxBase*       m_focus;
    Level*             m_level;
    bool               m_open;

    void M_setFocus(TextBoxBase& text_box);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    GameMenu(Level* level);
    virtual ~GameMenu();

    void initialize(const sf::Texture& textures);

    void open();
    void close();
    bool isOpen()const;

    virtual sf::Vector2f getSize()const;

    virtual void onClosed();
    virtual void onResized(const sf::Event::SizeEvent&);
    virtual void onLostFocus();
    virtual void onGainedFocus();
    virtual void onTextEntered(const sf::Event::TextEvent&);
    virtual void onKeyPressed(const sf::Event::KeyEvent&);
    virtual void onKeyReleased(const sf::Event::KeyEvent&);
    virtual void onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent&);
    virtual void onMouseButtonPressed(const sf::Event::MouseButtonEvent&);
    virtual void onMouseButtonReleased(const sf::Event::MouseButtonEvent&);
    virtual void onMouseMoved(const sf::Event::MouseMoveEvent&);
    virtual void onMouseEntered();
    virtual void onMouseLeft();
};

#endif
