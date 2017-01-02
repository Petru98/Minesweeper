#ifndef MINESWEEPER_MENU_HPP_INCLUDED
#define MINESWEEPER_MENU_HPP_INCLUDED

#include "SpriteButton.hpp"

class MenuBar : public sf::Drawable, public sf::Transformable
{
public:
    static constexpr std::size_t HEIGHT = 19;
    static const sf::Vector2f ITEM_OFFSET;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    sf::RectangleShape m_background;
public:
    SpriteButton game_button;

    MenuBar();
    ~MenuBar();

    void setTexture(const sf::Texture& textures);

    void setSize(const float width, const float height);
    void setSize(const sf::Vector2f size);

    sf::Vector2f getSize()const;
};

#endif
