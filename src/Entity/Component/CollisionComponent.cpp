#include "CollisionComponent.h"
#include "SpriteComponent.h"

CollisionComponent::CollisionComponent()
{

}

bool CollisionComponent::checkCollision(const CollisionComponent& other) const
{
	std::optional<sf::FloatRect> floatRect = bounds.findIntersection(other.bounds);
	return floatRect.has_value();
}

void CollisionComponent::updateBounds(SpriteComponent& spriteComponent)
{
	bounds.size.x = spriteComponent.GetPosition().x;
	bounds.size.y = spriteComponent.GetPosition().y;
}

const sf::FloatRect& CollisionComponent::getBounds() const
{
	return bounds;
}
