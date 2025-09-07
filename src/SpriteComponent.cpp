#include "SpriteComponent.h"

SpriteComponent::SpriteComponent()
{
	
}

void SpriteComponent::SetTexture(const char* filePath)
{
	if (this->texture.loadFromFile(filePath))
	{
		sprite.emplace(this->texture);
		sprite->setOrigin(sf::Vector2f({ 0.0f, 0.0f }));
		sprite->setScale(sf::Vector2f({ 1.0f, 1.0f }));
		sprite->setColor(sf::Color(255, 255, 255, 255)); // Full opacity
	}
}

const sf::Texture& SpriteComponent::GetTexture()
{
	return texture;
}

void SpriteComponent::Move(sf::Vector2f offset)
{
	if (sprite.has_value())
	{
		sprite->move(offset);
	}
}

void SpriteComponent::Draw(sf::RenderWindow& window)
{
	if (sprite.has_value())
	{
		window.draw(sprite.value());
	}
}

const sf::Vector2f& SpriteComponent::GetPosition()
{
	// TODO: insert return statement here
	if (sprite.has_value())
	{
		return sprite->getPosition();
	}
	return sf::Vector2f({0.0f, 0.0f});
}

void SpriteComponent::SetPosition(const sf::Vector2f& position)
{
	if (sprite.has_value())
	{
		sprite->setPosition(position);
	}
}
