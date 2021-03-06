#ifndef MINESWEEPER_LEVEL_HPP_INCLUDED
#define MINESWEEPER_LEVEL_HPP_INCLUDED

#include "Scene.hpp"
#include "MenuBar.hpp"
#include "GameMenu.hpp"
#include "Background.hpp"
#include "Header.hpp"
#include "Table.hpp"

class Level : public Scene
{
public:
    struct Difficulty
    {
        sf::Uint16 lines;
        sf::Uint16 columns;
        sf::Uint16 mines;

        Difficulty() : lines(0), columns(0), mines(0) {}
        Difficulty(const sf::Uint16 l, const sf::Uint16 c, const sf::Uint16 m) : lines(l), columns(c), mines(m) {}

        static const Difficulty beginner;
        static const Difficulty intermediate;
        static const Difficulty expert;
        static const Difficulty maximum;
    };

    struct Status
    {
        enum
        {
            Lost = -2,
            Won  = -1,
            None = 0
        };
    };

    static bool mouse_left_pressed;
    static bool mouse_right_pressed;

private:
    static constexpr sf::Uint32 MAGIC_NUMBER = 0x4D535750;

    GameMenu           m_game_menu;
    Background         m_background;
    Header             m_header;
    MenuBar            m_menu_bar;
    Table              m_table;
    sf::RenderWindow&  m_window;
    const sf::Texture& m_textures;
    sf::Int8           m_game_over;

    void M_updateFlagsCount();

    bool M_initializeBackground(const sf::Uint16 lines, const sf::Uint16 columns);
    void M_initializeMenu();
    void M_initializeHeader();
    void M_resizeWindow();

    void M_setButtonPressStatus(const int button, const bool pressed);

    void M_onMouseButtonPressedTable(const sf::Event::MouseButtonEvent event);
    void M_onMouseButtonPressedSmiley(const sf::Event::MouseButtonEvent event);

    void M_onMouseButtonReleasedTable(const sf::Event::MouseButtonEvent event);
    void M_onMouseButtonReleasedSmiley(const sf::Event::MouseButtonEvent event);

    void M_onMouseMovedInGame(const sf::Event::MouseMoveEvent event);
    void M_onMouseMovedGameOver(const sf::Event::MouseMoveEvent event);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    static constexpr char SAVE_FILE[] = "last_game.sav";

    static Difficulty setDifficultyInBounds(Difficulty difficulty);

    Level(sf::RenderWindow& window, const sf::Texture& texture);
    virtual ~Level();

    bool create(const Difficulty difficulty);

    void win();
    void lose();

    void handleEvent(const sf::Event& event);

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

    bool save(const char* const filename)const;
    bool save(File& file)const;
    bool load(const char* const filename);
    bool load(File& file);
};

#endif
