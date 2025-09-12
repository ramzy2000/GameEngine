#ifndef ACTORY_H
#define ACTORY_H
#include "Entity/Entity.h"
#include "Entity/Action/Action.h"
#include "Game/GameData.h"

class Actor
{
private:
	Entity entity_id;

	void generateId();
protected:
	std::shared_ptr<GameData> gameData;
public:
	
	Actor(std::shared_ptr<GameData> gameData);

	virtual ~Actor();

	void setPosition(const sf::Vector2f& position);
	void setPosition(const float& x, const float& y);

	Entity GetEntityId() const;

	const sf::Vector2f& GetPosition() const;
};

#endif // !ACTORY_H



