#ifndef ACTION_H
#define ACTION_H

#include "../Entity.h"
#include <memory>
#include <SFML/Graphics.hpp>

class Action
{
public:
	virtual ~Action() = default;
	virtual void perform(std::shared_ptr<Entity> entity, sf::Time deltaTime) = 0;
};

#endif // !ACTION_H



