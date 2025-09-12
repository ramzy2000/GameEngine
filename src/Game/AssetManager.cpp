#include "AssetManager.h"

void AssetManager::LoadTexture(const std::string& filePath, const std::string& name)
{
    std::shared_ptr<sf::Texture> texture;
    _textures[name] = std::make_unique<sf::Texture>(filePath);
}

void AssetManager::UnloadTexture(const std::string& name)
{
    _textures.erase(name);
}

sf::Texture& AssetManager::GetTexture(const std::string& name)
{
    return *_textures[name];
}
