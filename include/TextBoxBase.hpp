#ifndef MINESWEEPER_TEXTBOXBASE_HPP_INCLUDED
#define MINESWEEPER_TEXTBOXBASE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class TextBoxBase : public sf::Drawable, public sf::Transformable
{
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;

public:
    virtual void showCursor() = 0;
    virtual void hideCursor() = 0;
    virtual bool isCursorVisible()const = 0;

    virtual sf::Vector2f getSize()const = 0;

    virtual void clear() = 0;
    virtual const char* getText()const = 0;
    virtual std::size_t getTextLength()const = 0;

    virtual void onTextEntered(const sf::Event::TextEvent& event) = 0;
};

#endif
