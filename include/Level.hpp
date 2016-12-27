#ifndef MINESWEEPER_LEVEL_HPP_INCLUDED
#define MINESWEEPER_LEVEL_HPP_INCLUDED

#include "Scene.hpp"
#include "Matrix.hpp"
#include "Cell.hpp"

class Level : public Scene
{
public:
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

private:
    sf::RenderWindow& m_window;
    Matrix<Cell> m_cells;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    static Difficulty S_correctDifficulty(Difficulty difficulty);

public:
    Level(sf::RenderWindow& window);
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
