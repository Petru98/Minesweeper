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

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Smiley();
    ~Smiley();

    void initialize(const sf::Texture& textures);
    void reset();

    void press();
    void release();

    void setWin();
    void setLose();
    void setScared();

    bool isPressed()const;

    template<typename T> bool contains(const T x, const T y)const
    {
        const sf::Vector2f position = this->getPosition() - sf::Vector2f(this->WIDTH/2.0f, this->HEIGHT/2.0f);
        const float right = position.x + this->WIDTH;
        const float bottom = position.y + this->HEIGHT;

        return x >= position.x && x < right && y >= position.y && y < bottom;
    }
    template<typename T> bool contains(const sf::Vector2<T> point)const
    {
        const sf::Vector2f position = this->getPosition() - this->getOrigin();
        const float right = position.x + this->WIDTH;
        const float bottom = position.y + this->HEIGHT;

        return (point.x >= position.x) && (point.x < right) && (point.y >= position.y) && (point.y < bottom);
    }
};

#endif
