#ifndef VELOCITY_COMPONENT_H
#define VELOCITY_COMPONENT_H
#include "Component.h"
#include <SFML/Graphics.hpp>

class VelocityComponent
{
	float velocity = 800.f;
public:
	const float& GetVelocity();

	void SetVelocity(float velocity);
};

#endif // !VELOCITY_COMPONENT_H



