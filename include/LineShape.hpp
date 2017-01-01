#ifndef LINESHAPE_HPP_INCLUDED
#define LINESHAPE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class LineShape : public sf::Shape
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    sf::Vertex points[2];

    LineShape();
    virtual ~LineShape();
};

#endif
