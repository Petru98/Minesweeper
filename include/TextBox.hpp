#ifndef MINESWEEPER_TEXTBOX_HPP_INCLUDED
#define MINESWEEPER_TEXTBOX_HPP_INCLUDED

#include "TextBoxBase.hpp"
#include "LineShape.hpp"
#include "textures.hpp"

template <std::size_t N>
class TextBox : public TextBoxBase
{
private:
    static const sf::Vector2f TEXT_OFFSET;
    static const sf::Vector2f CURSOR_START_POSITION;

    sf::RectangleShape m_background;
    sf::Sprite         m_sprites[N];
    LineShape          m_cursor;
    std::size_t        m_index_current;
    char               m_text[N + 1];
    bool               m_cursor_visible;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    TextBox();
    virtual ~TextBox();

    void initialize(const sf::Texture& textures);

    virtual void showCursor();
    virtual void hideCursor();
    virtual bool isCursorVisible()const;

    virtual sf::Vector2f getSize()const;

    virtual void clear();
    virtual void setText(const char* str);

    virtual const char* getText()const;
    virtual std::size_t getTextLength()const;

    virtual void onTextEntered(const sf::Event::TextEvent& event);

    template<typename T> bool contains(const T x, const T y)const
    {
        const sf::Vector2f position = this->getPosition();
        const sf::Vector2f size = m_background.getSize();
        return (x >= position.x) && (x < position.x + size.x) && (y >= position.y) && (y < position.y + size.y);
    }
};

/* Implementation */
template<std::size_t N> const sf::Vector2f TextBox<N>::TEXT_OFFSET = {4.0f, 3.0f};
template<std::size_t N> const sf::Vector2f TextBox<N>::CURSOR_START_POSITION = TextBox<N>::TEXT_OFFSET - sf::Vector2f(0.0f, 1.0f);

template<std::size_t N> void TextBox<N>::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    target.draw(m_background, states);
    for(std::size_t i = 0; i < m_index_current; ++i)
        target.draw(m_sprites[i], states);
    if(m_cursor_visible == true)
        target.draw(m_cursor, states);
}

template<std::size_t N> TextBox<N>::TextBox() : m_background(), m_cursor(), m_index_current(0), m_cursor_visible(false)
{
    using namespace Resources::Textures;

    m_background.setSize(sf::Vector2f(N * DIGIT_WIDTH + 2*this->TEXT_OFFSET.x, DIGIT_HEIGHT + 2*this->TEXT_OFFSET.y));
    m_background.setOutlineThickness(-1.0f);
    m_background.setOutlineColor(sf::Color::Black);
    m_cursor.points[0].position = sf::Vector2f(0.0f, 0.0f);
    m_cursor.points[1].position = sf::Vector2f(0.0f, DIGIT_HEIGHT + 2.0f);
    m_cursor.points[0].color = sf::Color::Black;
    m_cursor.points[1].color = sf::Color::Black;
    m_cursor.setPosition(this->CURSOR_START_POSITION);

    for(std::size_t i = 0; i < N; ++i)
    {
        m_sprites[i].setPosition(this->TEXT_OFFSET + sf::Vector2f(i * DIGIT_WIDTH, 0.0f));
        m_text[i] = 0;
    }
    m_text[N] = 0;
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

template<std::size_t N> sf::Vector2f TextBox<N>::getSize()const
{
    return m_background.getSize();
}

template<std::size_t N> void TextBox<N>::clear()
{
    using namespace Resources::Textures::Rectangles;

    for(std::size_t i = 0; i < m_index_current; ++i)
    {
        m_sprites[i].setTextureRect(digit[Indexes::DigitNone]);
        m_text[i] = 0;
    }
    m_index_current = 0;
    m_cursor.setPosition(this->CURSOR_START_POSITION);
}
template<std::size_t N> void TextBox<N>::setText(const char* str)
{
    using namespace Resources::Textures::Rectangles;
    using namespace Resources::Textures;

    m_index_current = 0;
    while(str[m_index_current] != 0)
    {
        const std::size_t value = str[m_index_current] - '0';
        m_text[m_index_current] = str[m_index_current];

        m_sprites[m_index_current].setTextureRect(digit[value]);
        ++m_index_current;
    }
    m_text[m_index_current] = 0;
    m_cursor.setPosition(this->CURSOR_START_POSITION + sf::Vector2f(m_index_current * DIGIT_WIDTH, 0.0f));
}

template<std::size_t N> const char* TextBox<N>::getText()const
{
    return m_text;
}
template<std::size_t N> std::size_t TextBox<N>::getTextLength()const
{
    return m_index_current;
}

template<std::size_t N> void TextBox<N>::onTextEntered(const sf::Event::TextEvent& event)
{
    using namespace Resources::Textures::Rectangles;
    using namespace Resources::Textures;

    if(m_index_current < N && event.unicode >= '0' && event.unicode <= '9')
    {
        m_text[m_index_current] = static_cast<char>(event.unicode);
        m_sprites[m_index_current].setTextureRect(digit[event.unicode - '0']);
        ++m_index_current;
        m_cursor.move(DIGIT_WIDTH, 0.0f);
    }
    else if(m_index_current > 0 && event.unicode == '\b')
    {
        --m_index_current;
        m_text[m_index_current] = 0;
        m_sprites[m_index_current].setTextureRect(digit[Indexes::DigitNone]);
        m_cursor.move(-DIGIT_WIDTH, 0.0f);
    }
}

#endif
