#include "Game.h"
#include <iostream>
#include "../Level/MainLevel.h"
#include "../Entity/System/SystemManager.h"

Game::Game()
{
    data = std::make_shared<GameData>(); // Create game data object
    data->systemManager = std::make_shared<SystemManager>(data); // Create System Manager

    // setup window
    data->window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "CMake SFML Project");
    data->window.setFramerateLimit(144);
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
    std::list<std::shared_ptr<Entity>> entites = data->levels.top()->GetList();
    for (std::shared_ptr<Entity> entity : entites)
    {
        data->systemManager->Update(entity, deltaTime);
    }
}

void Game::run()
{
    // load level
    this->AddLevel(std::make_shared<MainLevel>(), false);

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

void Game::AddLevel(std::shared_ptr<Level> level, bool isReplacing)
{
    if (isReplacing)
    {
        data->levels.pop();
        data->levels.push(level);

        return;
    }
    data->levels.push(level);
    data->isAdding = true;
}

void Game::RemoveLevel()
{
    data->levels.pop();;
    data->isRemoveing = false;
}
