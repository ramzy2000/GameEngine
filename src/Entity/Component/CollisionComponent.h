#ifndef COLLISION_COMPOENT_H
#define COLLISION_COMPOENT_H
#include <SFML/Graphics.hpp>

class SpriteComponent;

#include "Component.h"
class CollisionComponent : public Component
{
	sf::FloatRect bounds;
public:
	CollisionComponent();

	bool checkCollision(const CollisionComponent& other) const;

	void updateBounds(SpriteComponent& spriteComponent);

	const sf::FloatRect& getBounds() const;
};

#endif //!COLLISION_COMPOENT_H
