#ifndef MINESWEEPER_SMILEY_HPP_INCLUDED
#define MINESWEEPER_SMILEY_HPP_INCLUDED

#include "textures.hpp"
#include <SFML/Graphics.hpp>

class Smiley : public sf::Drawable, public sf::Transformable
{
public:
    static constexpr std::size_t WIDTH = Resources::Textures::SMILEY_WIDTH;
    static constexpr std::size_t HEIGHT = Resources::Textures::SMILEY_HEIGHT;

private:
    sf::Sprite   m_sprite;
    sf::IntRect  m_sprite_rect;
    sf::Vector2f m_position_offset;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Smiley();
    ~Smiley();

    void initialize(const sf::Texture& textures, const sf::Vector2f position_offset);
    void reset();

    void press();
    void release();

    void setWin();
    void setLose();
    void setScared();

    template<typename T> bool contains(const T x, const T y)const
    {
        const sf::Vector2f position = this->getPosition() + m_position_offset - sf::Vector2f(Smiley::WIDTH/2.0f, Smiley::HEIGHT/2.0f);
        const float right = position.x + Smiley::WIDTH;
        const float bottom = position.y + Smiley::HEIGHT;

        return x >= position.x && x < right && y >= position.y && y < bottom;
    }
};

#endif
