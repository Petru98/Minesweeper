#include "Scene.hpp"
#include "function.hpp"

Game* Scene::game = nullptr;

Scene::Scene() : onClosed            (nullptr), onResized           (nullptr),
                 onLostFocus         (nullptr), onGainedFocus       (nullptr),
                 onTextEntered       (nullptr), onKeyPressed        (nullptr), onKeyReleased(nullptr),
                 onMouseWheelScrolled(nullptr), onMouseButtonPressed(nullptr), onMouseButtonReleased(nullptr),
                 onMouseMoved        (nullptr), onMouseEntered      (nullptr), onMouseLeft(nullptr)
{
}

void Scene::handleEvent(const sf::Event& event)
{
    switch(event.type)
    {
    case sf::Event::Closed:              callHandle(onClosed); break;
    case sf::Event::Resized:             callHandle(onResized, event.size); break;
    case sf::Event::LostFocus:           callHandle(onLostFocus); break;
    case sf::Event::GainedFocus:         callHandle(onGainedFocus); break;
    case sf::Event::TextEntered:         callHandle(onTextEntered, event.text); break;
    case sf::Event::KeyPressed:          callHandle(onKeyPressed, event.key); break;
    case sf::Event::KeyReleased:         callHandle(onKeyReleased, event.key); break;
    case sf::Event::MouseWheelScrolled:  callHandle(onMouseWheelScrolled, event.mouseWheelScroll); break;
    case sf::Event::MouseButtonPressed:  callHandle(onMouseButtonPressed, event.mouseButton); break;
    case sf::Event::MouseButtonReleased: callHandle(onMouseButtonReleased, event.mouseButton); break;
    case sf::Event::MouseMoved:          callHandle(onMouseMoved, event.mouseMove); break;
    case sf::Event::MouseEntered:        callHandle(onMouseEntered); break;
    case sf::Event::MouseLeft:           callHandle(onMouseLeft); break;
    default: break;
    }
}
