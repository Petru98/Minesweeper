#ifndef MINESWEEPER_CELL_HPP_INCLUDED
#define MINESWEEPER_CELL_HPP_INCLUDED

#include "textures.hpp"
#include <SFML/Graphics.hpp>

class Cell : public sf::Drawable, public sf::Transformable
{
public:
    static constexpr std::size_t WIDTH = Resources::Textures::CELL_WIDTH;
    static constexpr std::size_t HEIGHT = Resources::Textures::CELL_HEIGHT;

private:
    sf::Sprite m_sprite;
    sf::Uint8  m_mines_count;
    bool       m_has_mine;
    bool       m_flag;
    bool       m_revealed;

    void M_revealGameOver();
    void M_revealInGame();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Cell();

    void initialize(const sf::Texture& textures);
    void reset();

    void reveal(const bool game_over = false);

    void incrementMinesCount();
    void setMine();
    bool toggleFlag();
    bool press();
    bool release();

    sf::Uint8 getMinesCount()const;
    bool hasMine()const;
    bool hasFlag()const;
    bool isRevealed()const;
};

#endif
