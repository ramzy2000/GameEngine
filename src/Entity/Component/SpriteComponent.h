#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"

#include <SFML/Graphics.hpp>
#include <memory>

class SpriteComponent : public Component
{
public:
	std::optional<sf::Sprite> sprite;
	SpriteComponent();
	~SpriteComponent();
	void SetTexture(sf::Texture& texture);
	const sf::Texture& GetTexture();
	void Move(sf::Vector2f offset);
	void Draw(sf::RenderWindow& window);

	const sf::Vector2f& GetPosition();

	void SetPosition(const sf::Vector2f& position);
};


#endif // !SPRITE_COMPONENT_H


