#ifndef COLLISION_COMPOENT_H
#define COLLISION_COMPOENT_H
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class SpriteComponent;

enum class ColliderShape { Box, Circle };

#include "Component.h"
class CollisionComponent : public Component
{
public:
    ColliderShape shape = ColliderShape::Box;
    b2Vec2 size = { 100.0f, 100.0f }; // For box
    float radius = 0.5f;        // For circle
    float density = 1.0f;
    float friction = 1.3f;
    bool isSensor = false;
};

#endif //!COLLISION_COMPOENT_H
