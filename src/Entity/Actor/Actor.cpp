#include "Actor.h"
#include "../Component/SpriteComponent.h"
#include "../Component/InputComponent.h"
#include "../Component/VelocityComponent.h"

Actor::Actor()
{
	std::shared_ptr<SpriteComponent> spriteComponent = std::make_shared<SpriteComponent>();
	if (spriteComponent)
	{
		spriteComponent->SetTexture("../Textures/Player.png");
	}
	
	this->addComponent(spriteComponent);
	this->addComponent(std::make_shared<VelocityComponent>());
}
