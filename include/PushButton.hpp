#ifndef MINESWEEPER_PUSHBUTTON_HPP_INCLUDED
#define MINESWEEPER_PUSHBUTTON_HPP_INCLUDED

#include "Button.hpp"

class PushButton : public Button
{
private:
    sf::Sprite m_sprite;
    bool m_pressed;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    PushButton();
    virtual ~PushButton();

    void initialize(const sf::Texture& textures, const sf::IntRect rect);

    void press();
    bool release();

    bool isPressed()const;

    template<typename T> bool contains(const T x, const T y)const
    {
        const sf::Vector2f position = this->getPosition();
        const sf::IntRect texture_rect = m_sprite.getTextureRect();
        return (x >= position.x) && (x < position.x + texture_rect.width) && (y >= position.y) && (y < position.y + texture_rect.height);
    }
};

#endif
