#ifndef CAMERA_SYSTEM_H
#define CAMERA_SYSTEM_H

#include "System.h"

class CameraSystem : public System
{
public:
	void update(std::shared_ptr<Entity> entity, sf::Time deltaTime) override {};
public:
	void update(sf::RenderWindow* window, std::shared_ptr<Entity> entity, sf::Time deltaTime);
};

#endif //!CAMERA_SYSTEM_H