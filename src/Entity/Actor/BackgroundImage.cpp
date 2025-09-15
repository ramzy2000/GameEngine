#include "BackgroundImage.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/DepthComponent.h"

BackgroundImage::BackgroundImage() : Actor()
{
	GameData::instance().componentManager.addComponent<SpriteComponent>(GetEntityId(), SpriteComponent());
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetTexture(GameData::instance().assetManager.GetTexture("background_texture"));

	DepthComponent& depthComponent = GameData::instance().componentManager.getComponent<DepthComponent>(GetEntityId());
	depthComponent.depth = -100;
}
