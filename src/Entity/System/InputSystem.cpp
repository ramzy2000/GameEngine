#include "InputSystem.h"
#include "../Component/InputComponent.h"
#include "../Action/Action.h"
#include <SFML/Graphics.hpp>

void InputSystem::update(std::shared_ptr<Entity> entity, sf::Time deltaTime)
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