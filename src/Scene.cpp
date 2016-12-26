#include "Scene.hpp"

Game* Scene::game = nullptr;

Scene::Scene() : onClosed(nullptr), onResized(nullptr),
                 onLostFocus(nullptr), onGainedFocus(nullptr),
                 onTextEntered(nullptr), onKeyPressed(nullptr), onKeyReleased(nullptr),
                 onMouseWheelScrolled(nullptr), onMouseButtonPressed(nullptr), onMouseButtonReleased(nullptr),
                 onMouseMoved(nullptr), onMouseEntered(nullptr), onMouseLeft(nullptr)
{
}

