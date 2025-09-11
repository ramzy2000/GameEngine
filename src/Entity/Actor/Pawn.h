#ifndef PAWN_H
#define PAWN_H

#include "Actor.h"

class Pawn : public Actor
{
public:
	Pawn(std::shared_ptr<GameData> gameData);
};

#endif // !PAWN_H



