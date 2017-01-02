#ifndef MINESWEEPER_BUTTON_HPP_INCLUDED
#define MINESWEEPER_BUTTON_HPP_INCLUDED

#include "def.hpp"
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;

public:
    Button() {}
    virtual ~Button() {}

    virtual bool press() = 0;
    virtual bool release() = 0;
    virtual bool isPressed()const = 0;

    virtual sf::Vector2f getSize()const = 0;

    virtual bool contains(const float x, const float y)const;
    virtual bool contains(const sf::Vector2f point)const;
};

FUNCTION_NO_DUPLICATES bool Button::contains(const sf::Vector2f point)const
{
    return this->contains(point.x, point.y);
}
FUNCTION_NO_DUPLICATES bool Button::contains(const float x, const float y)const
{
    const sf::Vector2f position = this->getPosition();
    const sf::Vector2f size = this->getSize();
    return (x >= position.x) && (x < position.x + size.x) && (y >= position.y) && (y < position.y + size.y);
}

#endif
