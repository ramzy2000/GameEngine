#include "Game.h"
#include <iostream>
#include "../Entity/System/SystemManager.h"
#include "../Entity//Component/SpriteComponent.h"
#include "../Entity//Component/VelocityComponent.h"
#include "../Entity//Component/CameraComponent.h"
#include "../Entity//Component/InputComponent.h"
#include "../Entity//Component/PlayerInputComponent.h"
#include "../Entity/Actor/Actor.h"

Game::Game()
{
    data = std::make_shared<GameData>(); // Create game data object
    data->systemManager = std::make_shared<SystemManager>(data); // Create System Manager

    // setup window
    data->window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "CMake SFML Project");
    data->window.setFramerateLimit(144);

    // register components
    data->componentManager.registerComponent<SpriteComponent>();
    data->componentManager.registerComponent<VelocityComponent>();
    data->componentManager.registerComponent<CameraComponent>();
    data->componentManager.registerComponent<InputComponent>();
    data->componentManager.registerComponent<PlayerInputComponent>();

    Actor actor(data);

    data->entities.push_back(actor.GetEntityId());
}

void Game::processEvents()
{
    while (const std::optional event = data->window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            data->window.close();
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    // get the list of all entities on the top loaded level
    for (Entity entity : data->entities)
    {
        data->systemManager->Update(deltaTime);
    }
}

void Game::run()
{

    // start the game loop
    while (data->window.isOpen())
    {
        processEvents();

        dt = deltaClock.restart();

        data->window.clear();

        update(dt);
        
        data->window.display();
    }
}