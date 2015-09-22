
#include "SystemMovement.hpp"

#include "../ComponentIdentifiers.hpp"
#include "../Components/ComponentPosition.hpp"
#include "../Components/ComponentVelocity.hpp"

SystemMovement::SystemMovement() {
	addRequiredComponent(Components::Position);
	addRequiredComponent(Components::Velocity);
}

void SystemMovement::update(sf::Time dt) {

	std::map<int, Entity*>::iterator itr;
	for (itr = mEntities.begin(); itr != mEntities.end(); ++itr) {
		ComponentPosition* cp = (ComponentPosition*)(*itr).second->getComponent(Components::Position);
		ComponentVelocity* cv = (ComponentVelocity*)(*itr).second->getComponent(Components::Velocity);
		sf::Vector2f* position = cp->getPosition();
		position->x += (cv->getVelocity()->x * dt.asMilliseconds());
		position->y += (cv->getVelocity()->y * dt.asMilliseconds());
	}

}