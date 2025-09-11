#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "System.h"

class RenderSystem : public System
{
public:

	void update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime);
};

#endif // !RENDER_SYSTEM


