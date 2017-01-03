#ifndef MINESWEEPER_MENUBAR_HPP_INCLUDED
#define MINESWEEPER_MENUBAR_HPP_INCLUDED

#include "Scene.hpp"
#include "ResizableRectangularObject.hpp"
#include "SpriteButton.hpp"
#include "Menu.hpp"

class MenuBar : public Scene, public ResizableRectangularObject
{
public:
    static constexpr std::size_t HEIGHT = 19;
    static const sf::Vector2f MENU_BUTTON_OFFSET;

private:
    static constexpr std::size_t N = 2;

    sf::RectangleShape m_background;
    sf::Vector2f       m_next_position;
    std::size_t        m_menus_count;
    Menu*              m_menus[N];
    Menu*              m_open_menu;
    Menu*              m_pressed_menu;

    void M_forwardEvent(const sf::Event& event);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:

    MenuBar();
    virtual ~MenuBar();

    void addMenu(Menu& menu);

    void  closeMenu();
    Menu* openMenu(Menu* menu);
    Menu* openMenu(const float x, const float y);

    Menu* getMenu(const float x, const float y)const;
    Menu* getOpenMenu()const;

    virtual void setSize(const float width, const float height);
    virtual void setSize(const sf::Vector2f size);

    virtual sf::Vector2f getSize()const;

    void handleEvent(const sf::Event& event);

    virtual void onClosed();
    virtual void onResized(const sf::Event::SizeEvent&);
    virtual void onLostFocus();
    virtual void onGainedFocus();
    virtual void onTextEntered(const sf::Event::TextEvent&);
    virtual void onKeyPressed(const sf::Event::KeyEvent&);
    virtual void onKeyReleased(const sf::Event::KeyEvent&);
    virtual void onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent&);
    virtual void onMouseButtonPressed(const sf::Event::MouseButtonEvent&);
    virtual void onMouseButtonReleased(const sf::Event::MouseButtonEvent&);
    virtual void onMouseMoved(const sf::Event::MouseMoveEvent&);
    virtual void onMouseEntered();
    virtual void onMouseLeft();
};

#endif
