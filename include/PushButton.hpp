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
};

#endif
