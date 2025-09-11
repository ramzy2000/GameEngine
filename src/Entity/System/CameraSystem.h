#ifndef CAMERA_SYSTEM_H
#define CAMERA_SYSTEM_H

#include "System.h"

class CameraSystem : public System
{
public:
	void update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime);
};

#endif //!CAMERA_SYSTEM_H