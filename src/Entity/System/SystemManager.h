#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "System.h"
#include "Entity/Entity.h"
#include "Entity/System/InputSystem.h"
#include "Entity/System/RenderSystem.h"
#include "Entity/System/CameraSystem.h"
#include <array>
#include <vector>

class GameData;

// Store a list of pointers to each system.

// I want to process each system in one frame time.
// I dont want to have to itterate over each systems entites.

// will this solve this problem

static const unsigned int MAX_SYSTEMS = 10;

class SystemManager
{
    InputSystem inputSystem;
    RenderSystem renderSystem;
    CameraSystem cameraSystem;
    std::shared_ptr<GameData> gameData;
public:
    SystemManager(std::shared_ptr<GameData> gameData);
    void Update(sf::Time deltaTime);
};



#endif //!SYSTEM_MANAGER_H