#ifndef ACTORY_H
#define ACTORY_H
#include "Entity/Entity.h"
#include "Entity/Action/Action.h"
#include "Entity/EntityBase.h"
#include "Game/GameData.h"

class Actor : public EntityBase
{
public:
	
	Actor();

	void setPosition(const sf::Vector2f& position);
	void setPosition(const float& x, const float& y);

	const sf::Vector2f& GetPosition() const;
};

#endif // !ACTORY_H



