#include "Game.h"
#include <iostream>
#include "../Level/MainLevel.h"

Game::Game()
{
    data = std::make_shared<GameData>();
    window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "CMake SFML Project");
    window.setFramerateLimit(144);
}

void Game::processEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    // loading and unloading levels
    if (data->isAdding || data->isRemoveing)
    {
        // clear the systems
        data->inputSystem.clearEntities();
        data->renderSystem.clearEntities();

        // process the top most level entites into systems
        auto entites = data->levels.top()->GetList();
        for (auto& entity : entites)
        {
            data->inputSystem.addEntity(entity);
            data->renderSystem.addEntity(entity);
        }

        if (data->isAdding)
        {
            data->isAdding = false;
        }

        if (data->isRemoveing)
        {
            data->isRemoveing = false;
        }
    }
    

    // process systems
    data->inputSystem.update(deltaTime);
    data->renderSystem.update(&window, deltaTime);
}

void Game::handelKeyEvent(sf::Keyboard::Key key, bool isPressed)
{

}

void Game::render()
{

}

void Game::resizeBackground()
{

}

void Game::run()
{
    // load level
    this->AddLevel(std::make_shared<MainLevel>(), false);

    while (window.isOpen())
    {
        processEvents();

        dt = deltaClock.restart();

        window.clear();

        update(dt);
        
        window.display();
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
