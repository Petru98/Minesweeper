#ifndef MINESWEEPER_RECTANGLEAREA_HPP_INCLUDED
#define MINESWEEPER_RECTANGLEAREA_HPP_INCLUDED

#include "def.hpp"
#include <SFML/Graphics.hpp>

class RectangularObject : virtual public sf::Drawable, virtual public sf::Transformable
{
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;

public:
    RectangularObject() {}
    virtual ~RectangularObject() {}

    virtual sf::Vector2f getSize()const = 0;

    sf::FloatRect getRect()const;
    sf::Vector2f getRelativePoint(const float x, const float y)const;
    sf::Vector2f getRelativePoint(const sf::Vector2f point)const;

    bool contains(const float x, const float y)const;
    bool contains(const sf::Vector2f point)const;

    bool intersects(const sf::FloatRect rect)const;
    bool intersects(const sf::FloatRect rect, sf::FloatRect& intersection)const;

    bool intersects(const RectangularObject& rect)const;
    bool intersects(const RectangularObject& rect, sf::FloatRect& intersection)const;
};

FUNCTION_NO_DUPLICATES sf::FloatRect RectangularObject::getRect()const
{
    return sf::FloatRect(this->getPosition(), this->getSize());
}
FUNCTION_NO_DUPLICATES sf::Vector2f RectangularObject::getRelativePoint(const float x, const float y)const
{
    return this->getRelativePoint(sf::Vector2f(x,y));
}
FUNCTION_NO_DUPLICATES sf::Vector2f RectangularObject::getRelativePoint(const sf::Vector2f point)const
{
    return point - this->getPosition();
}

FUNCTION_NO_DUPLICATES bool RectangularObject::contains(const sf::Vector2f point)const
{
    return this->contains(point.x, point.y);
}
FUNCTION_NO_DUPLICATES bool RectangularObject::contains(const float x, const float y)const
{
    const sf::Vector2f position = this->getPosition() - this->getOrigin();
    const sf::Vector2f size = this->getSize();
    return (x >= position.x) && (x < position.x + size.x) && (y >= position.y) && (y < position.y + size.y);
}

FUNCTION_NO_DUPLICATES bool RectangularObject::intersects(const sf::FloatRect rect)const
{
    return this->getRect().intersects(rect);
}
FUNCTION_NO_DUPLICATES bool RectangularObject::intersects(const sf::FloatRect rect, sf::FloatRect& intersection)const
{
    return this->getRect().intersects(rect, intersection);
}

FUNCTION_NO_DUPLICATES bool RectangularObject::intersects(const RectangularObject& rect)const
{
    return this->getRect().intersects(rect.getRect());
}
FUNCTION_NO_DUPLICATES bool RectangularObject::intersects(const RectangularObject& rect, sf::FloatRect& intersection)const
{
    return this->getRect().intersects(rect.getRect(), intersection);
}

#endif
