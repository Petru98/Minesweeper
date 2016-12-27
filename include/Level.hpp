#ifndef MINESWEEPER_LEVEL_HPP_INCLUDED
#define MINESWEEPER_LEVEL_HPP_INCLUDED

#include "Scene.hpp"
#include "Matrix.hpp"
#include "Cell.hpp"

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
        sf::Uint8  lines;
        sf::Uint8  columns;
        sf::Uint16 mines;

        Difficulty() : lines(0), columns(0), mines(0) {}
        Difficulty(const sf::Uint8 w, const sf::Uint8 h, const sf::Uint16 m) : lines(w), columns(h), mines(m) {}
    };

    static const Difficulty easy;
    static const Difficulty medium;
    static const Difficulty hard;

    static constexpr unsigned int s_menu_height        = 19;
    static constexpr unsigned int s_cell_left_offset   = 12;
    static constexpr unsigned int s_cell_right_offset  = 8;
    static constexpr unsigned int s_cell_top_offset    = s_menu_height + 56;
    static constexpr unsigned int s_cell_bottom_offset = 8;

private:
    static Difficulty S_correctDifficulty(Difficulty difficulty);

    sf::RenderWindow&  m_window;
    const sf::Texture& m_textures;
    Matrix<Cell>       m_cells;

    void M_drawBackground(sf::RenderTarget& target, sf::RenderStates& states)const;
    void M_drawRect(sf::RenderTarget& target, const sf::Color color, const float x, const float y, const float w, const float h)const;
    void M_drawHead(sf::RenderTarget& target, sf::RenderStates& states)const;
    void M_drawCells(sf::RenderTarget& target, sf::RenderStates& states)const;

    void M_initializeCells();
    void M_placeMines(Level::Difficulty difficulty);
    void M_initializeWindow(const Level::Difficulty difficulty);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Level(sf::RenderWindow& window, const sf::Texture& texture);
    ~Level();

    void create(const Difficulty difficulty);

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
