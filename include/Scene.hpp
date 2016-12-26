#ifndef MINESWEEPER_SCENE_HPP_INCLUDED
#define MINESWEEPER_SCENE_HPP_INCLUDED

#include "Game.hpp"

class Scene
{
public:
    static Game* game;

    void (*onClosed)();
    void (*onResized)(const sf::Event::SizeEvent&);
    void (*onLostFocus)();
    void (*onGainedFocus)();
    void (*onTextEntered)(const sf::Event::TextEvent&);
    void (*onKeyPressed)(const sf::Event::KeyEvent&);
    void (*onKeyReleased)(const sf::Event::KeyEvent&);
    void (*onMouseWheelScrolled)(const sf::Event::MouseWheelEvent&);
    void (*onMouseButtonPressed)(const sf::Event::MouseButtonEvent&);
    void (*onMouseButtonReleased)(const sf::Event::MouseButtonEvent&);
    void (*onMouseMoved)(const sf::Event::MouseMoveEvent&);
    void (*onMouseEntered)();
    void (*onMouseLeft)();

    Scene();

    void handleEvent(const sf::Event& event);
};

#endif
