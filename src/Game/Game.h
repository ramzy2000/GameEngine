#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "../Entity/Entity.h"
#include "../Entity/System/InputSystem.h"
#include "../Entity/System/RenderSystem.h"
#include "../Level/Level.h"
#include <stack>
#include "../Game/GameData.h"


// Contains everything you need for the game loop
class Game
{
public:
	Game();
	void run();

	void AddLevel(std::shared_ptr<Level> level, bool isReplacing);

	void RemoveLevel();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void handelKeyEvent(sf::Keyboard::Key key, bool isPressed);
	void render();
	void resizeBackground();

	sf::RenderWindow window;
	sf::Texture backgroundTexture;
	std::optional<sf::Sprite> backgroundSprite;

	sf::Clock deltaClock;
	sf::Time dt;

	std::shared_ptr<Entity> player;
	std::shared_ptr<Entity> ball;
	std::shared_ptr<Entity> opponentPaddle;

	std::shared_ptr<GameData> data;
};

#endif //!GAME_H