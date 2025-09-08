#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include "Component.h"
#include <SFML/Graphics.hpp>

class CameraComponent : public Component
{
	sf::View view;
	sf::Vector2f offset = { 270.f, 250.f };
public:
	CameraComponent();

	// Set a new position
	void SetView(sf::View view);

	// Get a position
	sf::View& GetView();

	// Set 
	const sf::Vector2f& GetOffset();
};

#endif //!CAMERA_COMPONENT_H