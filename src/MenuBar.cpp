#include "MenuBar.hpp"
#include "textures.hpp"

const sf::Vector2f MenuBar::MENU_BUTTON_OFFSET = {6.0f, 4.0f};

void MenuBar::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_background, states);

    for(std::size_t i = 0; i < m_menus_count; ++i)
        target.draw(m_menus[i]->button, states);
    if(m_open_menu != nullptr)
        target.draw(*m_open_menu, states);
}

MenuBar::MenuBar() : m_background(), m_next_position(this->MENU_BUTTON_OFFSET), m_menus_count(0),
                     m_open_menu(nullptr), m_pressed_menu(nullptr)
{
    m_background.setFillColor(sf::Color(236, 233, 216));
    m_background.setOutlineThickness(-1.0f);
    m_background.setOutlineColor(sf::Color(192, 192, 192));
}
MenuBar::~MenuBar()
{}

void MenuBar::addMenu(Menu& menu)
{
    m_menus[m_menus_count] = &menu;
    ++m_menus_count;

    menu.setPosition(0.0f, this->HEIGHT);

    menu.button.setPosition(m_next_position);
    m_next_position += menu.button.getSize() + this->MENU_BUTTON_OFFSET;
}

void MenuBar::closeMenu()
{
    if(m_open_menu != nullptr)
    {
        m_open_menu->close();
        m_open_menu = nullptr;
    }
}
Menu* MenuBar::openMenu(Menu* menu)
{
    this->closeMenu();
    m_open_menu = menu;

    if(m_open_menu != nullptr)
        m_open_menu->open();

    return m_open_menu;
}
Menu* MenuBar::openMenu(const float x, const float y)
{
    Menu* menu = getMenu(x,y);
    return this->openMenu(menu);
}

Menu* MenuBar::getMenu(const float x, const float y)const
{
    if(m_menus_count == 0 || x < this->MENU_BUTTON_OFFSET.x || x >= m_next_position.x ||
                             y < this->MENU_BUTTON_OFFSET.y || y >= this->MENU_BUTTON_OFFSET.y + (*m_menus)->getSize().y)
        return nullptr;

    for(std::size_t i = 0; i < m_menus_count; ++i)
    {
        const float current_position_x = m_menus[i]->button.getPosition().x;

        if(current_position_x > x)
            break;
        if(current_position_x + m_menus[i]->button.getSize().x > x)
            return m_menus[i];
    }

    return nullptr;
}
Menu* MenuBar::getOpenMenu()const
{
    return m_open_menu;
}

void MenuBar::setSize(const float width, const float height)
{
    m_background.setSize(sf::Vector2f(width, height));
}
void MenuBar::setSize(const sf::Vector2f size)
{
    m_background.setSize(size);
}

sf::Vector2f MenuBar::getSize()const
{
    return m_background.getSize();
}

/* Events */
void MenuBar::handleEvent(const sf::Event& event)
{
    if(m_open_menu == nullptr)
        Scene::handleEvent(event);
    else
    {
        if(event.type != sf::Event::MouseButtonPressed && event.type != sf::Event::MouseButtonReleased)
            M_forwardEvent(event);
        else
        {
            if(m_open_menu->contains(event.mouseButton.x, event.mouseButton.y) == true)
                M_forwardEvent(event);
            else if(this->contains(event.mouseButton.x, event.mouseButton.y) == true)
                Scene::handleEvent(event);
            else
                this->closeMenu();
        }
    }
}
void MenuBar::M_forwardEvent(const sf::Event& event)
{
    m_open_menu->handleEvent(event);

    if(m_open_menu->isOpen() == false)
        m_open_menu = nullptr;
}

void MenuBar::onClosed() {}
void MenuBar::onResized(const sf::Event::SizeEvent& event) {}
void MenuBar::onLostFocus() {}
void MenuBar::onGainedFocus() {}
void MenuBar::onTextEntered(const sf::Event::TextEvent& event) {}
void MenuBar::onKeyPressed(const sf::Event::KeyEvent& event) {}
void MenuBar::onKeyReleased(const sf::Event::KeyEvent& event) {}
void MenuBar::onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event) {}

void MenuBar::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event)
{
    Menu* menu = getMenu(event.x, event.y);

    if(menu != nullptr)
    {
        m_pressed_menu = menu;
        m_pressed_menu->button.press();
    }
}

void MenuBar::onMouseButtonReleased(const sf::Event::MouseButtonEvent& event)
{
    if(m_pressed_menu == nullptr)
        this->closeMenu();
    else
    {
        m_pressed_menu->button.release();

        if(m_pressed_menu != m_open_menu)
            this->openMenu(m_pressed_menu);
        else
            this->closeMenu();
        m_pressed_menu = nullptr;
    }
}

void MenuBar::onMouseMoved(const sf::Event::MouseMoveEvent& event)
{
    if(m_pressed_menu != nullptr && m_pressed_menu->button.contains(event.x, event.y) == false)
        m_pressed_menu = nullptr;
}

void MenuBar::onMouseEntered() {}
void MenuBar::onMouseLeft() {}
