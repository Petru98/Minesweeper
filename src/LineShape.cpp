#include "LineShape.hpp"

void LineShape::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(points, 2, sf::Lines, states);
}

LineShape::LineShape()
{}

LineShape::~LineShape()
{}

std::size_t LineShape::getPointCount()const
{
    return 2;
}
sf::Vector2f LineShape::getPoint(std::size_t index)const
{
    return points[index].position;
}
