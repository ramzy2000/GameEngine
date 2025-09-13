#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H
#include <SFML/Graphics.hpp>

#include "Component.h"

class TransformComponent : public Component
{
public:
    sf::Vector2f position = { 0.f, 0.f };  // In pixels
    float rotation = 0.f;                // In degrees
    sf::Vector2f scale = { 1.f, 1.f };     // Optional
};

#endif //! TRANSFORM_COMPONENT_H