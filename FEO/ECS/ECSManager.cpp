
#include "ECSManager.hpp"

ECSManager::ECSManager() {

}

void ECSManager::update(sf::Time dt) {
	std::vector<System*>::iterator itr;
	for (itr = mSystems.begin(); itr != mSystems.end(); ++itr) {
		(*itr)->update(dt);
	}
}

void ECSManager::draw() {
	std::vector<System*>::iterator itr;
	for (itr = mSystems.begin(); itr != mSystems.end(); ++itr) {
		(*itr)->draw();
	}
}

void ECSManager::addSystem(System* system) {
	mSystems.push_back(system);
}

int ECSManager::getNumSystems() {
	return (int) mSystems.size();
}

void ECSManager::registerEntity(Entity* entity) {

	// Loop over each system
	std::vector<System*>::iterator sysItr;
	for (sysItr = mSystems.begin(); sysItr != mSystems.end(); ++sysItr) {

		// Loop over all required components of system
		std::vector<Components::ID*> requiredComponents = (*sysItr)->getRequiredComponents();
		std::vector<Components::ID*>::iterator typeItr;
		bool validSystem = true;
		for (typeItr = requiredComponents.begin(); typeItr != requiredComponents.end(); ++typeItr) {

			if (!entity->hasComponent((**typeItr))) {
				validSystem = false;
				break;
			}

		}

		// If valid for the system, add entity to system
		if (validSystem) {
			(*sysItr)->addEntity(entity);
		}

	}

}

void ECSManager::removeEntity(int id) {

}