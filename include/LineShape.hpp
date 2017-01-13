#ifndef LINESHAPE_HPP_INCLUDED
#define LINESHAPE_HPP_INCLUDED

#include "def.hpp"
#include <SFML/Graphics.hpp>

class LineShape : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    sf::Vertex points[2];

    LineShape() {}
    virtual ~LineShape() {}

    void setColor(const sf::Color color);

    void setOffset(const float x, const float y);
    void setOffset(const sf::Vector2f offset);

    void moveOffset(const sf::Vector2f offset);
    void moveOffset(const float x, const float y);

    sf::Vertex& operator[] (const std::size_t index);
    const sf::Vertex operator[] (const std::size_t index)const;
};

FUNCTION_NO_DUPLICATES void LineShape::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(points, 2, sf::Lines, states);
}

FUNCTION_NO_DUPLICATES void LineShape::setColor(const sf::Color color)
{
    points[0].color = color;
    points[1].color = color;
}

FUNCTION_NO_DUPLICATES void LineShape::setOffset(const float x, const float y)
{
    points[1].position.x = x;
    points[1].position.y = y;
}
FUNCTION_NO_DUPLICATES void LineShape::setOffset(const sf::Vector2f offset)
{
    points[1].position = offset;
}

FUNCTION_NO_DUPLICATES void LineShape::moveOffset(const float x, const float y)
{
    points[1].position.x += x;
    points[1].position.y += y;
}
FUNCTION_NO_DUPLICATES void LineShape::moveOffset(const sf::Vector2f offset)
{
    points[1].position += offset;
}

FUNCTION_NO_DUPLICATES sf::Vertex& LineShape::operator[] (const std::size_t index)
{
    return points[index];
}
FUNCTION_NO_DUPLICATES const sf::Vertex LineShape::operator[] (const std::size_t index)const
{
    return points[index];
}

#endif
