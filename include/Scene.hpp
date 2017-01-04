#ifndef MINESWEEPER_SCENE_HPP_INCLUDED
#define MINESWEEPER_SCENE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Scene : virtual public sf::Drawable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;

public:
    virtual void onClosed() = 0;
    virtual void onResized(const sf::Event::SizeEvent&) = 0;
    virtual void onLostFocus() = 0;
    virtual void onGainedFocus() = 0;
    virtual void onTextEntered(const sf::Event::TextEvent&) = 0;
    virtual void onKeyPressed(const sf::Event::KeyEvent&) = 0;
    virtual void onKeyReleased(const sf::Event::KeyEvent&) = 0;
    virtual void onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent&) = 0;
    virtual void onMouseButtonPressed(const sf::Event::MouseButtonEvent&) = 0;
    virtual void onMouseButtonReleased(const sf::Event::MouseButtonEvent&) = 0;
    virtual void onMouseMoved(const sf::Event::MouseMoveEvent&) = 0;
    virtual void onMouseEntered() = 0;
    virtual void onMouseLeft() = 0;

    void handleEvent(const sf::Event& event);
};

#endif
