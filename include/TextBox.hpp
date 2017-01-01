#ifndef MINESWEEPER_TEXTBOX_HPP_INCLUDED
#define MINESWEEPER_TEXTBOX_HPP_INCLUDED

#include "Scene.hpp"
#include "textures.hpp"

template <std::size_t N>
class TextBox : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape m_background;
    sf::Sprite         m_sprites[N];
    LineShape          m_cursor;
    std::size_t        m_index_current;
    char               m_text[N];
    bool               m_cursor_visible;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    TextBox();
    virtual ~TextBox();

    void initialize(const sf::Texture& textures);

    void showCursor();
    void hideCursor();
    bool isCursorVisible()const;

    const char* getText()const;
    std::size_t getTextLength()const;

    void onTextEntered(const sf::Event::TextEvent& event);
};

/* Implementation */
template<std::size_t N> void TextBox<N>::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    target.draw(m_background, states);
    for(std::size_t i = 0; i < m_index_current; ++i)
        target.draw(m_sprites[i], states);
    target.draw(m_cursor, states);
}

template<std::size_t N> TextBox<N>::TextBox() : m_background(), m_cursor(), m_index_current(0), m_cursor_visible(false)
{
    using namespace Resources::Textures;

    m_background.setSize(sf::Vector2f(N * DIGIT_WIDTH + 2*3, DIGIT_HEIGHT + 2*3));
    m_background.setOutlineThickness(-1.0f);
    m_background.setOutlineColor(sf::Color::Black);
    m_cursor.points[0].position = sf::Vector2f(1.0f, 0.0f);
    m_cursor.points[1].position = sf::Vector2f(1.0f, DIGIT_HEIGHT);
}

template<std::size_t N> TextBox<N>::~TextBox()
{}

template<std::size_t N> void TextBox<N>::initialize(const sf::Texture& textures)
{
    using namespace Resources::Textures::Rectangles;

    for(std::size_t i = 0; i < N; ++i)
    {
        m_sprites[i].setTexture(textures);
        m_sprites[i].setTextureRect(digit[Indexes::DigitNone]);
        m_text[i] = 0;
    }
}

template<std::size_t N> void TextBox<N>::showCursor()
{
    m_cursor_visible = true;
}
template<std::size_t N> void TextBox<N>::hideCursor()
{
    m_cursor_visible = false;
}
template<std::size_t N> bool TextBox<N>::isCursorVisible()const
{
    return m_cursor_visible;
}

template<std::size_t N> const char* TextBox<N>::getText()const
{
    return m_text;
}
template<std::size_t N> std::size_t TextBox<N>::getTextLength()const
{
    return m_index_current;
}

template<std::size_t N> void TextBox<N>::onTextEntered(const sf::Event::TextEvent& event);
{
    using namespace Resources::Textures::Rectangles;

    if(m_index_current < N && event.unicode >= '0' && event.unicode <= '9')
    {
        m_text[m_index_current] = static_cast<char>(event.unicode);
        m_sprites[m_index_current].setTextureRect(digit[event.unicode - '0']);
        ++m_index_current;
        m_cursor.move(DIGIT_WIDTH, 0.0f);
    }
    else if(m_index_current > 0 && event.unicode == '\b')
    {
        m_text[m_index_current] = 0;
        m_sprites[m_index_current].setTextureRect(digit[Indexes::DigitNone]);
        --m_index_current;
        m_cursor.move(-DIGIT_WIDTH, 0.0f);
    }
}

#endif
