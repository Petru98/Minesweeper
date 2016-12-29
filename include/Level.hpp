#ifndef MINESWEEPER_LEVEL_HPP_INCLUDED
#define MINESWEEPER_LEVEL_HPP_INCLUDED

#include "Scene.hpp"
#include "Table.hpp"
#include "Background.hpp"

class Level : public Scene
{
public:
    struct Error
    {
        enum
        {
            None,
            Allocate,
            CreateWindow
        };

        static constexpr const char* messages[] =
        {
            "No error",
            "Could not allocate memory for a new game",
            "Could not create an OpenGL window"
        };
    };

    struct Difficulty
    {
        sf::Uint16 lines;
        sf::Uint16 columns;
        sf::Uint16 mines;

        Difficulty() : lines(0), columns(0), mines(0) {}
        Difficulty(const sf::Uint16 w, const sf::Uint16 h, const sf::Uint16 m) : lines(w), columns(h), mines(m) {}
    };

    static const Difficulty beginner;
    static const Difficulty intermediate;
    static const Difficulty expert;

    static constexpr unsigned int s_MENU_HEIGHT = 19;

private:
    static Difficulty S_correctDifficulty(Difficulty difficulty);

    sf::RenderWindow&  m_window;
    const sf::Texture& m_textures;
    Background         m_background;
    Table              m_table;
    bool               m_game_over;

    void M_drawHead(sf::RenderTarget& target, sf::RenderStates& states)const;

    void M_initializeBackground();
    void M_resizeWindow();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Level(sf::RenderWindow& window, const sf::Texture& texture);
    ~Level();

    void create(const Difficulty difficulty);

    void win();
    void lose();

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
