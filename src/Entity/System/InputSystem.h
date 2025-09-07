#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include "System.h"

#include <SFML/Graphics.hpp>

class InputSystem : public System
{
public:
	void update(std::shared_ptr<Entity> entity, sf::Time deltaTime) override;
};

#endif //!INPUT_SYSTEM_H