#include "SpriteComponent.h"

SpriteComponent::SpriteComponent()
{
	
}

SpriteComponent::~SpriteComponent()
{
	sprite.reset();
}

void SpriteComponent::SetTexture(sf::Texture& texture)
{
	sprite.emplace(texture);
	sprite->setOrigin(sf::Vector2f({ texture.getSize().x / 2.0f, texture.getSize().y / 2.0f }));
	sprite->setScale(sf::Vector2f({ 1.0f, 1.0f }));
	sprite->setColor(sf::Color(255, 255, 255, 255)); // Full opacity
}

const sf::Texture& SpriteComponent::GetTexture()
{
	return sprite->getTexture();
}

void SpriteComponent::Move(sf::Vector2f offset)
{
	if (sprite)
	{
		sprite->move(offset);
	}
}

void SpriteComponent::Draw(sf::RenderWindow& window)
{
	if (sprite)
	{
		window.draw(*sprite);
	}
}

const sf::Vector2f& SpriteComponent::GetPosition()
{
	// TODO: insert return statement here
	if (sprite)
	{
		return sprite->getPosition();
	}
	return sf::Vector2f({0.0f, 0.0f});
}

void SpriteComponent::SetPosition(const sf::Vector2f& position)
{
	if (sprite)
	{
		sprite->setPosition(position);
	}
}
