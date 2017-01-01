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
