
#include "SystemRender.hpp"

#include "../ComponentIdentifiers.hpp"
#include "../Components/ComponentSprite.hpp"
#include "../Components/ComponentPosition.hpp"

SystemRender::SystemRender(sf::RenderWindow* window) {
	addRequiredComponent(Components::Position);
	addRequiredComponent(Components::Sprite);
	mWindow = window;
}

void SystemRender::update(sf::Time dt) {

	std::map<int, Entity*>::iterator itr;
	for (itr = mEntities.begin(); itr != mEntities.end(); ++itr) {
		ComponentPosition* cp = (ComponentPosition*)(*itr).second->getComponent(Components::Position);
		ComponentSprite* cs = (ComponentSprite*)(*itr).second->getComponent(Components::Sprite);
		cs->getSprite()->setPosition(*(cp->getPosition()));
	}

}

void SystemRender::draw() {

	std::map<int, Entity*>::iterator itr;
	for (itr = mEntities.begin(); itr != mEntities.end(); ++itr) {
		ComponentSprite* cs = (ComponentSprite*)(*itr).second->getComponent(Components::Sprite);
		mWindow->draw(*(cs->getSprite()));
	}

}