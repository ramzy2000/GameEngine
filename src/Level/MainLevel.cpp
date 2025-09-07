#include "MainLevel.h"
#include "../Entity/Actor/Pawn/Player.h"
#include "../Entity/Actor/Pawn/NPC.h"

MainLevel::MainLevel()
{
	this->SpawnEntity(std::make_shared<Player>(), sf::Vector2f({ 0.0f, 0.0f }));
	std::shared_ptr<NPC> npc = std::make_shared<NPC>();
	this->SpawnEntity(npc, sf::Vector2f({ 500.0f, 0.0f }));
}
