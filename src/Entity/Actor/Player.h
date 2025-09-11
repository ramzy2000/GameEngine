#ifndef PLAYER_H
#define PLAYER_H

#include "Pawn.h"

class Player : public Pawn
{
public:
	Player(std::shared_ptr<GameData> gameData);
};

#endif //!PLAYER_H