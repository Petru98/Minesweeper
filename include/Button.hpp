#ifndef MINESWEEPER_BUTTON_HPP_INCLUDED
#define MINESWEEPER_BUTTON_HPP_INCLUDED

#include "RectangularObject.hpp"

class Button : public RectangularObject
{
public:
    Button() {}
    virtual ~Button() {}

    virtual bool press() = 0;
    virtual bool release() = 0;
    virtual bool isPressed()const = 0;
};

#endif
