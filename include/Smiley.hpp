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
    sf::Sprite  m_sprite;
    sf::IntRect m_rect;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Smiley();

    void initialize(const sf::Texture& textures);
    void reset();


};

#endif
