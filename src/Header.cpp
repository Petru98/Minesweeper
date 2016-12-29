#include "Header.hpp"

void Header::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(smiley, states);
}

Header::Header() : smiley()
{}

Header::~Header()
{}
