#ifndef STATIC_BOX_ENTITY_H
#define STATIC_BOX_ENTITY_H

#include "Entity/Actor/Actor.h"

class StaticBox : public Actor
{
public:
	StaticBox();

	~StaticBox();

	// SetBoxSize
	void SetBoxSize(b2Vec2 size);
};

#endif // !STATIC_BOX_ENTITY_H