#ifndef ACTION_H
#define ACTION_H

#include "../Entity.h"
#include <memory>
#include <SFML/Graphics.hpp>

#include "../Component/ComponentManager.h"

class Action
{
public:
	virtual ~Action() = default;
	virtual void perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime) = 0;
};

#endif // !ACTION_H



