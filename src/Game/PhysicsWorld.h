#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <box2d/box2d.h>

class PhysicsWorld
{
public:
public:
    PhysicsWorld() : world(b2Vec2(0.0f, -9.8f)) {}
    void Step(float dt) { world.Step(dt, 8, 3); }
    b2World& GetWorld() { return world; }

private:
    b2World world;
};

#endif //!PHYSICS_WORLD_H