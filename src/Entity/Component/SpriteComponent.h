#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"

#include <SFML/Graphics.hpp>

class SpriteComponent : public Component
{
	std::optional<sf::Sprite> sprite;
	sf::Texture texture;
public:
	SpriteComponent();
	void SetTexture(const char* filePath);
	const sf::Texture& GetTexture();
	void Move(sf::Vector2f offset);
	void Draw(sf::RenderWindow& window);

	const sf::Vector2f& GetPosition();

	void SetPosition(const sf::Vector2f& position);
};


#endif // !SPRITE_COMPONENT_H


