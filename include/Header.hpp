#ifndef MINESWEEPER_HEADER_HPP_INCLUDED
#define MINESWEEPER_HEADER_HPP_INCLUDED

#include "ResizableRectangularObject.hpp"
#include "Smiley.hpp"

class Header : public ResizableRectangularObject
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

    virtual void setSize(const float width, const float height);
    virtual void setSize(const sf::Vector2f size);

    virtual sf::Vector2f getSize()const;
};

#endif
