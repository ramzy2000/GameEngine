#include "InputSystem.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Action/Action.h"
#include <SFML/Graphics.hpp>

void InputSystem::update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime)
{
	for (auto& entity : entities)
	{
		if (componentManager.hasComponent<PlayerInputComponent>(entity))
		{
			PlayerInputComponent& inputComponent = componentManager.getComponent<PlayerInputComponent>(entity);
			auto actions = inputComponent.HandleInput();
			for (std::shared_ptr<Action> action : actions)
			{
				if (action)
				{
					action->perform(componentManager, entity, deltaTime);
				}
			}
		}
	}
}