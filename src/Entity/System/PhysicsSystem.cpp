#include "PhysicsSystem.h"
#include "Entity/Component/RigidBodyComponent.h"
#include "Entity/Component/CollisionComponent.h"
#include "Entity/Component/TransformComponent.h"
#include <SFML/Graphics.hpp>

constexpr float PIXELS_PER_METER = 100.0f;


void PhysicsSystem::update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime)
{
	physicsWorld.Step(deltaTime.asSeconds());

	for (Entity entity : entities)
	{
        RigidBodyComponent& rigidBodyComponent = componentManager.getComponent<RigidBodyComponent>(entity);
        TransformComponent& transformComponent = componentManager.getComponent<TransformComponent>(entity);

        if (rigidBodyComponent.body)
        {
            // apply all physics
            b2Vec2 pos = rigidBodyComponent.body->GetPosition();
            float angle = rigidBodyComponent.body->GetAngle();
            transformComponent.position.x = pos.x * PIXELS_PER_METER;
            transformComponent.position.y = (-1)*pos.y * PIXELS_PER_METER;
            //transformComponent.rotation = angle * 180.f / b2_pi;
        }
	}
}

void PhysicsSystem::createBody(ComponentManager& componentManager, Entity entity)
{
    RigidBodyComponent& rigidBody = componentManager.getComponent<RigidBodyComponent>(entity);
    CollisionComponent& collision = componentManager.getComponent<CollisionComponent>(entity);
    TransformComponent& transform = componentManager.getComponent<TransformComponent>(entity);

    b2BodyDef bodyDef;

    // Set body type
    switch (rigidBody.type) {
    case BodyType::Static:    bodyDef.type = b2_staticBody; break;
    case BodyType::Dynamic:   bodyDef.type = b2_dynamicBody; break;
    case BodyType::Kinematic: bodyDef.type = b2_kinematicBody; break;
    }

    // Convert pixel position to Box2D meters
    constexpr float METERS_PER_PIXEL = 1.0f / 100.0f;
    bodyDef.position.Set(transform.position.x * METERS_PER_PIXEL,
        transform.position.y * METERS_PER_PIXEL);
    bodyDef.angle = transform.rotation * b2_pi / 180.0f;

    // Create the body
    rigidBody.body = physicsWorld.GetWorld().CreateBody(&bodyDef);

    // Define fixture
    b2FixtureDef fixtureDef;
    fixtureDef.density = collision.density;
    fixtureDef.friction = collision.friction;
    fixtureDef.isSensor = collision.isSensor;

    if (collision.shape == ColliderShape::Box) {
        b2PolygonShape boxShape;
        boxShape.SetAsBox(collision.size.x * 0.5f * METERS_PER_PIXEL,
            collision.size.y * 0.5f * METERS_PER_PIXEL);
        fixtureDef.shape = &boxShape;
        rigidBody.body->CreateFixture(&fixtureDef);
    }
    else if (collision.shape == ColliderShape::Circle) {
        b2CircleShape circleShape;
        circleShape.m_radius = collision.radius * METERS_PER_PIXEL;
        fixtureDef.shape = &circleShape;
        rigidBody.body->CreateFixture(&fixtureDef);
    }

    rigidBody.initialized = true;
}

void PhysicsSystem::destroyBody(ComponentManager& componentManager, Entity entity)
{
    RigidBodyComponent& rigidBody = componentManager.getComponent<RigidBodyComponent>(entity);

    physicsWorld.GetWorld().DestroyBody(rigidBody.body);
    rigidBody.body = nullptr;
}
