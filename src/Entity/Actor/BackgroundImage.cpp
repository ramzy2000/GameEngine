#include "BackgroundImage.h"
#include "Entity/Component/SpriteComponent.h"

BackgroundImage::BackgroundImage() : Actor()
{
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetTexture(GameData::instance().assetManager.GetTexture("background_texture"));
}
