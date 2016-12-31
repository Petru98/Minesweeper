#ifndef MINESWEEPER_MENU_HPP_INCLUDED
#define MINESWEEPER_MENU_HPP_INCLUDED

#include "PushButton.hpp"

class Menu : public sf::Drawable, public sf::Transformable
{
public:
    static constexpr std::size_t HEIGHT = 19;
    static const sf::Vector2f ITEM_OFFSET;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    sf::RectangleShape m_background;
public:
    PushButton game_button;

    Menu();
    ~Menu();

    void initialize(const sf::Texture& textures);

    template<typename T> void setSize(const T width, const T height)
    {
        m_background.setSize(sf::Vector2f(width, height));
    }
    template<typename T> void setSize(const sf::Vector2<T> size)
    {
        m_background.setSize(sf::Vector2f(size.x, size.y));
    }

    sf::Vector2f getSize()const;
};

#endif
