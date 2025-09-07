#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "System.h"
#include "../../Game/GameData.h"
#include "../Entity.h"
#include <array>
#include <vector>

// Store a list of pointers to each system.

// I want to process each system in one frame time.
// I dont want to have to itterate over each systems entites.

// will this solve this problem

static const unsigned int MAX_SYSTEMS = 10;

class SystemManager
{
    std::vector<std::shared_ptr<System>> systems;
    std::shared_ptr<GameData> gameData;
public:
    SystemManager(std::shared_ptr<GameData> gameData);
    void Update(std::shared_ptr<Entity> entity, sf::Time deltaTime);
};

#endif //!SYSTEM_MANAGER_H