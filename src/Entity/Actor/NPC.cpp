#include "NPC.h"
#include <iostream>
#include "Entity/Component/RigidBodyComponent.h"



NPC::NPC() : Pawn()
{
	RigidBodyComponent& ridgetBodyComponent = GameData::instance().componentManager.getComponent<RigidBodyComponent>(GetEntityId());
	ridgetBodyComponent.type = BodyType::Static;
}
