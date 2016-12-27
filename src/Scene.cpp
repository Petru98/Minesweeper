#include "Scene.hpp"

void Scene::handleEvent(const sf::Event& event)
{
    switch(event.type)
    {
    case sf::Event::Closed:              onClosed(); break;
    case sf::Event::Resized:             onResized(event.size); break;
    case sf::Event::LostFocus:           onLostFocus(); break;
    case sf::Event::GainedFocus:         onGainedFocus(); break;
    case sf::Event::TextEntered:         onTextEntered(event.text); break;
    case sf::Event::KeyPressed:          onKeyPressed(event.key); break;
    case sf::Event::KeyReleased:         onKeyReleased(event.key); break;
    case sf::Event::MouseWheelScrolled:  onMouseWheelScrolled(event.mouseWheelScroll); break;
    case sf::Event::MouseButtonPressed:  onMouseButtonPressed(event.mouseButton); break;
    case sf::Event::MouseButtonReleased: onMouseButtonReleased(event.mouseButton); break;
    case sf::Event::MouseMoved:          onMouseMoved(event.mouseMove); break;
    case sf::Event::MouseEntered:        onMouseEntered(); break;
    case sf::Event::MouseLeft:           onMouseLeft(); break;
    default: break;
    }
}
