#include "InputSystem.h"
#include "InputComponent.h"
#include "Action.h"
#include <SFML/Graphics.hpp>

void InputSystem::update(sf::Time deltaTime)
{
	// process entites inputs
	for (std::shared_ptr<Entity> entity : entities)
	{
		std::shared_ptr<InputComponent> inputComponent = entity->getComponent<InputComponent>();
		if (inputComponent)
		{
			auto actions = inputComponent->HandleInput();
			for (std::shared_ptr<Action> action : actions)
			{
				if (action)
				{
					action->perform(entity, deltaTime);
				}
			}
		}
	}
}