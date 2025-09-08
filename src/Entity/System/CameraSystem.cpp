#include "CameraSystem.h"
#include "../Component/CameraComponent.h"
#include "../Component/SpriteComponent.h"

void CameraSystem::update(sf::RenderWindow* window, std::shared_ptr<Entity> entity, sf::Time deltaTime)
{
	std::shared_ptr<CameraComponent> cameraComponent = entity->getComponent<CameraComponent>();
	std::shared_ptr<SpriteComponent> spriteComponent = entity->getComponent<SpriteComponent>();
	if (cameraComponent && spriteComponent)
	{
		cameraComponent->GetView().setCenter(spriteComponent->GetPosition() + cameraComponent->GetOffset());
		window->setView(cameraComponent->GetView());
	}
}