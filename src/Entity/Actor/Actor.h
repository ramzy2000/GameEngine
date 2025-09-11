#ifndef ACTORY_H
#define ACTORY_H
#include "../Entity.h"
#include "../Action/Action.h"
#include "../../Game/GameData.h"

class Actor
{
private:
	Entity entity_id;

	void generateId();
protected:
	std::shared_ptr<GameData> gameData;
public:
	
	Actor(std::shared_ptr<GameData> gameData);

	~Actor();

	Entity GetEntityId() const;
};

#endif // !ACTORY_H



