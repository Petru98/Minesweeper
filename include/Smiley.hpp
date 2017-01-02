#ifndef MINESWEEPER_SMILEY_HPP_INCLUDED
#define MINESWEEPER_SMILEY_HPP_INCLUDED

#include "Button.hpp"
#include "textures.hpp"

class Smiley : public Button
{
public:
    static constexpr std::size_t WIDTH = Resources::Textures::SMILEY_WIDTH;
    static constexpr std::size_t HEIGHT = Resources::Textures::SMILEY_HEIGHT;

private:
    sf::Sprite   m_sprite;
    sf::IntRect  m_sprite_rect;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Smiley();
    virtual ~Smiley();

    void initialize(const sf::Texture& textures);
    void setTexture(const sf::Texture& textures);

    void reset();

    void setWin();
    void setLose();
    void setScared();

    virtual bool press();
    virtual bool release();
    virtual bool isPressed()const;

    virtual sf::Vector2f getSize()const;
};

#endif
