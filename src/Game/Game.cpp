#include "Game.h"
#include <iostream>
#include "Game/Managers/SystemManager.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/CameraComponent.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/DepthComponent.h"
#include "Entity/Component/RigidBodyComponent.h"
#include "Entity/Component/CollisionComponent.h"
#include "Entity/Component/TransformComponent.h"
#include "Entity/Actor/Player.h"
#include "Entity/Actor/NPC.h"
#include "Entity/Actor/BackgroundImage.h"
#include <filesystem>
#include "Game/GameData.h"

Game::Game()
{
    // Create game data object
    GameData::instance().systemManager = std::make_shared<SystemManager>(); // Create System Manager

    // setup window
    GameData::instance().window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "2D Engine");
    GameData::instance().window.setFramerateLimit(60);

    // register components
    RegisterComponent<SpriteComponent>();
    RegisterComponent<VelocityComponent>();
    RegisterComponent<CameraComponent>();
    RegisterComponent<InputComponent>();
    RegisterComponent<PlayerInputComponent>();
    RegisterComponent<DepthComponent>();
    RegisterComponent<CollisionComponent>();
    RegisterComponent<RigidBodyComponent>();
    RegisterComponent<TransformComponent>();

    // load textures
    std::string path = std::filesystem::current_path().parent_path().generic_string() + "/Textures/Player.png";
    GameData::instance().assetManager.LoadTexture(path, "player_texture");
    std::string path2 = std::filesystem::current_path().parent_path().generic_string() + "/Textures/background_textures.png";
    GameData::instance().assetManager.LoadTexture(path2, "background_texture");
    std::string path3 = std::filesystem::current_path().parent_path().generic_string() + "/Textures/wood_floor.png";
    GameData::instance().assetManager.LoadTexture(path3, "wood_floor_texture");
    
    std::string path4 = std::filesystem::current_path().parent_path().generic_string() + "/Textures/Assassin.png";
    GameData::instance().assetManager.LoadTexture(path4, "assassin_texture");
}

void Game::processEvents()
{
    while (const std::optional event = GameData::instance().window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            GameData::instance().window.close();
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    GameData::instance().systemManager->Update(deltaTime);
}

void Game::run()
{
    std::shared_ptr<BackgroundImage> backgroundImage = std::make_shared<BackgroundImage>();
    backgroundImage->setPosition(-100.f, 0.f);
    GameData::instance().entities.push_back(backgroundImage->GetEntityId());

    // load entities
    std::shared_ptr<Player> player = std::make_shared<Player>();
    player->setPosition(0.f, 100.f);
    GameData::instance().entities.push_back(player->GetEntityId());

    std::shared_ptr<NPC> npc = std::make_shared<NPC>();
    npc->setPosition(0.0f, 0.f);
    GameData::instance().entities.push_back(npc->GetEntityId());
    
    // start the game loop
    while (GameData::instance().window.isOpen())
    {
        processEvents();

        dt = deltaClock.restart();

        GameData::instance().window.clear();

        update(dt);
        
        GameData::instance().window.display();

        std::cout << "Player Pos : " << player->GetPosition().x << ", " << player->GetPosition().y << "\n";
    }
}