#ifndef MINESWEEPER_MENU_HPP_INCLUDED
#define MINESWEEPER_MENU_HPP_INCLUDED

#include "Scene.hpp"
#include "RectangularObject.hpp"
#include "SpriteButton.hpp"

class Menu : public Scene, public RectangularObject
{
    friend class MenuBar;

protected:
    //MenuBar* m_menu_bar;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;

public:
    SpriteButton button;

    Menu() {}
    virtual ~Menu() {}

    virtual void open() = 0;
    virtual void close() = 0;
    virtual bool isOpen()const = 0;
};

#endif
