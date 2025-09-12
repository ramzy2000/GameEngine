#ifndef RIGID_BODY_COMPONENT_H
#define RIGID_BODY_COMPONENT_H

#include <SFML/Graphics.hpp>

#include "Component.h"
class RigidBodyComponent : public Component
{
public:
    float mass;
    float restitution;
    sf::Vector2f velocity;
};

#endif //!RIGID_BODY_COMPONENT_H