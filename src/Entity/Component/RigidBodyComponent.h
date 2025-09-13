#ifndef RIGID_BODY_COMPONENT_H
#define RIGID_BODY_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "Component.h"

enum class BodyType { Static, Dynamic, Kinematic };

class RigidBodyComponent : public Component
{
public:
    b2Body* body = nullptr;
    BodyType type = BodyType::Dynamic;
    bool initialized = false;
};

#endif //!RIGID_BODY_COMPONENT_H