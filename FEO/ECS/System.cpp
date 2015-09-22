
#include "System.hpp"

System::System() {

}

System::~System() {

}

bool System::hasRequiredComponents(Entity* entity) {
	for (auto itr = mRequiredComponents.rbegin(); itr != mRequiredComponents.rend(); ++itr) {
		if (!entity->hasComponent(**itr)) return false;
	}
	return true;
}

void System::addRequiredComponent(Components::ID id) {
	Components::ID* newId = new Components::ID(id);
	mRequiredComponents.push_back(newId);
}

std::vector<Components::ID*> System::getRequiredComponents() {
	return mRequiredComponents;
}

void System::addEntity(Entity* entity) {
	mEntities[entity->getId()] = entity;
}

void System::removeEntity(int id) {

}