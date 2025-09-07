#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "System.h"

class RenderSystem : public System
{
	void update(std::shared_ptr<Entity> entity, sf::Time deltaTime) override {};
public:
	void update(sf::RenderWindow* window, std::shared_ptr<Entity> entity, sf::Time deltaTime);
};

#endif // !RENDER_SYSTEM


