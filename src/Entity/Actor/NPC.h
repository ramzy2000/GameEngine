#ifndef NPC_H
#define NPC_H

#include "Pawn.h"

class NPC : public Pawn
{
public:
	NPC(std::shared_ptr<GameData> gameData);
};

#endif //!NPC_H