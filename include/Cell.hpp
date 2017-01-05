#ifndef MINESWEEPER_CELL_HPP_INCLUDED
#define MINESWEEPER_CELL_HPP_INCLUDED

#include "textures.hpp"
#include "Button.hpp"
#include "Flags.hpp"

class Cell : public Button
{
public:
    static constexpr std::size_t WIDTH = Resources::Textures::CELL_WIDTH;
    static constexpr std::size_t HEIGHT = Resources::Textures::CELL_HEIGHT;

private:
    struct Flags
    {
        enum
        {
            HasMine    = 1 << 0,
            HasFlag    = 1 << 1,
            IsRevealed = 1 << 2,
            IsPressed  = 1 << 3
        };
    };

    sf::Sprite m_sprite;
    sf::Uint8  m_mines_count;
    Flags8     m_state;

    bool M_revealGameOver();
    bool M_revealInGame();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Cell();
    virtual ~Cell();

    void initialize(const sf::Texture& textures);
    void setTexture(const sf::Texture& textures);

    void reset();

    bool reveal(const bool game_over = false);

    void setMine();
    bool toggleFlag();
    void incrementMinesCount();
    void setMinesCount(const sf::Uint8 count);
    void setState(Flags8 state);
    void setTextureRect(const sf::IntRect& rect);

    bool hasMine()const;
    bool hasFlag()const;
    bool isRevealed()const;
    bool canPress()const;
    bool canRelease()const;
    bool canReveal()const;

    sf::Uint8          getMinesCount()const;
    Flags8             getState()const;
    const sf::IntRect& getTextureRect()const;

    virtual bool press();
    virtual bool release();
    virtual bool isPressed()const;

    virtual sf::Vector2f getSize()const;
};

#endif
