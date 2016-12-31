#ifndef MINESWEEPER_MENU_HPP_INCLUDED
#define MINESWEEPER_MENU_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Menu();
    ~Menu();
};

#endif
