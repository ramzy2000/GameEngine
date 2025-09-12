#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class AssetManager
{
	std::unordered_map <std::string, std::unique_ptr<sf::Texture>> _textures;
public:
	// load a texture
	void LoadTexture(const std::string& filePath, const std::string& name);

	// remove texture
	void UnloadTexture(const std::string& name);

	// get a texture
	sf::Texture& GetTexture(const std::string& name);
};

#endif //!ASSET_MANAGER_H