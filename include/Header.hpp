#ifndef MINESWEEPER_HEADER_HPP_INCLUDED
#define MINESWEEPER_HEADER_HPP_INCLUDED

#include "Smiley.hpp"
#include "RectangularObject.hpp"

class Header : public RectangularObject
{
public:
    static constexpr std::size_t HEIGHT = 33;

    Smiley smiley;
private:
    sf::Vector2f m_size;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Header();
    virtual ~Header();

    void initialize(const sf::Texture& textures);
    void setTexture(const sf::Texture& textures);

    void setSize(const sf::Vector2f size);
    void setSize(const float width, const float height);

    virtual sf::Vector2f getSize()const;
};

#endif
