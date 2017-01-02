#ifndef MINESWEEPER_PUSHBUTTON_HPP_INCLUDED
#define MINESWEEPER_PUSHBUTTON_HPP_INCLUDED

#include "Button.hpp"

class SpriteButton : public Button
{
private:
    sf::Sprite m_sprite;
    bool       m_pressed;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    SpriteButton();
    virtual ~SpriteButton();

    void initialize(const sf::Texture& textures, const sf::IntRect rect);
    void setTexture(const sf::Texture& textures, const sf::IntRect rect);

    virtual bool press();
    virtual bool release();
    virtual bool isPressed()const;

    virtual sf::Vector2f getSize()const;
};

#endif
