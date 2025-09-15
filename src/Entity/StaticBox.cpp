#include "StaticBox.h"
#include "Entity/Component/RigidBodyComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/CollisionComponent.h"

StaticBox::StaticBox() : Actor()
{
	GameData::instance().componentManager.addComponent<VelocityComponent>(GetEntityId(), VelocityComponent());
	GameData::instance().componentManager.addComponent<RigidBodyComponent>(GetEntityId(), RigidBodyComponent());
	GameData::instance().componentManager.addComponent<CollisionComponent>(GetEntityId(), CollisionComponent());
	RigidBodyComponent& rb = GameData::instance().componentManager.getComponent<RigidBodyComponent>(GetEntityId());
	rb.type = BodyType::Static;
	GameData::instance().systemManager->physicsSystem.createBody(GameData::instance().componentManager, GetEntityId());

	RigidBodyComponent& rigidBodyComponent = GameData::instance().componentManager.getComponent<RigidBodyComponent>(GetEntityId());
	rigidBodyComponent.body->SetLinearDamping(100.f);
}

StaticBox::~StaticBox()
{
	GameData::instance().systemManager->physicsSystem.destroyBody(GameData::instance().componentManager, GetEntityId());
}

void StaticBox::SetBoxSize(b2Vec2 size)
{
	// get the collision component
	CollisionComponent& collisionComponent = GameData::instance().componentManager.getComponent<CollisionComponent>(GetEntityId());

	// set the size of the box in the collision component
	collisionComponent.size = size;

	// unload body
	GameData::instance().systemManager->physicsSystem.destroyBody(GameData::instance().componentManager, GetEntityId());

	// reload body
	GameData::instance().systemManager->physicsSystem.createBody(GameData::instance().componentManager, GetEntityId());
}
