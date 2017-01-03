#ifndef MINESWEEPER_TEXTBOXBASE_HPP_INCLUDED
#define MINESWEEPER_TEXTBOXBASE_HPP_INCLUDED

#include "RectangularObject.hpp"

class TextBoxBase : public RectangularObject
{
public:
    TextBoxBase() {}
    virtual ~TextBoxBase() {}

    virtual void showCursor() = 0;
    virtual void hideCursor() = 0;
    virtual bool isCursorVisible()const = 0;

    virtual void clear() = 0;
    virtual void setText(const char* str) = 0;

    virtual const char* getText()const = 0;
    virtual std::size_t getTextLength()const = 0;

    virtual void onTextEntered(const sf::Event::TextEvent& event) = 0;
};

#endif
