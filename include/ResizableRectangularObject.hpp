#ifndef MINESWEEPER_RESIZABLERECTANGULAROBJECT_HPP_INCLUDED
#define MINESWEEPER_RESIZABLERECTANGULAROBJECT_HPP_INCLUDED

#include "RectangularObject.hpp"

class ResizableRectangularObject : public RectangularObject
{
public:
    virtual void setSize(const float width, const float height) = 0;
    virtual void setSize(const sf::Vector2f size) = 0;
};

#endif
