#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Entity/Entity.h"
#include <stack>
#include "Game/GameData.h"


// Contains everything you need for the game loop
class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);

	sf::Texture backgroundTexture;
	std::optional<sf::Sprite> backgroundSprite;

	sf::Clock deltaClock;
	sf::Time dt;

	std::shared_ptr<GameData> data;
};

#endif //!GAME_H