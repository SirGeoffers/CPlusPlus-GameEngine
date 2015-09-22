
#include "ComponentSprite.hpp"

ComponentSprite::ComponentSprite() {
	init(nullptr);
}

ComponentSprite::ComponentSprite(sf::Sprite* sprite) {
	init(sprite);
}

sf::Sprite* ComponentSprite::getSprite() {
	return mSprite;
}

void ComponentSprite::setSprite(sf::Sprite* sprite) {
	mSprite = sprite;
}

void ComponentSprite::init(sf::Sprite* initialSprite) {
	setType(Components::Sprite);
	mSprite = initialSprite;
}