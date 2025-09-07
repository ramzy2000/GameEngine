#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "System.h"

class RenderSystem : public System
{
	void update(sf::Time deltaTime) override {};
public:
	void update(sf::RenderWindow* window, sf::Time deltaTime);
};

#endif // !RENDER_SYSTEM


