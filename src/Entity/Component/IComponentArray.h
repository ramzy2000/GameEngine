#ifndef ICOMPONENT_ARRAY_H
#define ICOMPONENT_ARRAY_H

#include "Entity/Entity.h"

class IComponentArray
{
public:
	virtual ~IComponentArray() = default;
	virtual void remove(Entity entity) = 0;
};

#endif //!ICOMPONENT_ARRAY_H