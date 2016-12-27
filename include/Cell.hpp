#ifndef MINESWEEPER_CELL_HPP_INCLUDED
#define MINESWEEPER_CELL_HPP_INCLUDED

#include "textures.hpp"
#include <SFML/Graphics.hpp>

class Cell : public sf::Drawable, public sf::Transformable
{
public:
    static constexpr std::size_t width = Resources::Textures::CELL_WIDTH;
    static constexpr std::size_t height = Resources::Textures::CELL_HEIGHT;

private:
    sf::Sprite m_sprite;
    sf::Uint8  m_mines_count;
    bool       m_has_mine;
    bool       m_revealed;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Cell();

    void initialize(const sf::Texture& textures);
    void reset();

    void setMine();
    bool hasMine()const;
};

#endif
