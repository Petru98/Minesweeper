#ifndef MINESWEEPER_BUTTON_HPP_INCLUDED
#define MINESWEEPER_BUTTON_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;

public:
    Button() {}
    virtual ~Button() {}

    virtual void press() = 0;
    virtual void release() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual void show() = 0;
    virtual void hide() = 0;

    virtual bool isPressed()const = 0;
    virtual bool isDisabled()const = 0;
    virtual bool isHidden()const = 0;
};

#endif
