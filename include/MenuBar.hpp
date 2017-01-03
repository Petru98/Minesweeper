#ifndef MINESWEEPER_MENU_HPP_INCLUDED
#define MINESWEEPER_MENU_HPP_INCLUDED

#include "SpriteButton.hpp"
#include "ResizableRectangularObject.hpp"

class MenuBar : public ResizableRectangularObject
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
    virtual ~MenuBar();

    void initialize(const sf::Texture& textures);
    void setTexture(const sf::Texture& textures);

    virtual void setSize(const float width, const float height);
    virtual void setSize(const sf::Vector2f size);

    virtual sf::Vector2f getSize()const;
};

#endif
