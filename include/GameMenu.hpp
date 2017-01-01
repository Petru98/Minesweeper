#ifndef MINESWEEPER_GAMEMENU_HPP_INCLUDED
#define MINESWEEPER_GAMEMENU_HPP_INCLUDED

#include "Scene.hpp"
#include "PushButton.hpp"
#include "TextBox.hpp"

class GameMenu : public Scene
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

    sf::RectangleShape m_background;
    PushButton         m_buttons[4];
    TextBox<2>         m_lines;
    TextBox<2>         m_columns;
    TextBox<2>         m_mines;
    TextBox<2>*        m_focus;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    GameMenu();
    virtual ~GameMenu();

    void initialize(const sf::Texture& textures);

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
