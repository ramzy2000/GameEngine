#include "CameraComponent.h"

CameraComponent::CameraComponent()
{
	view.setSize({1920.f, 1080.f });
}

// Set a new position
void CameraComponent::SetView(sf::View view)
{
	this->view = view;
}

// Get a position
sf::View& CameraComponent::GetView()
{
	return view;
}

const sf::Vector2f& CameraComponent::GetOffset()
{
	return offset;
}
