
#include "Entity.hpp"

Entity::Entity() {
	mId = 0;
}

Entity::Entity(int id) {
	mId = id;
}

int Entity::getId() {
	return mId;
}

void Entity::addComponent(Component* component) {
	if (component->getParent() != nullptr) {
		component->getParent()->removeComponent(component->getType());
	}
	component->setParent(this);
	mComponents[component->getType()] = component;
}

void Entity::removeComponent(Components::ID id) {
	mComponents[id] = new Component();
}

Component* Entity::getComponent(Components::ID id) {
	return mComponents[id];
}

bool Entity::hasComponent(Components::ID id) {
	if (mComponents[id] != nullptr) {
		if (mComponents[id]->getType() != Components::None) return true;
	}
	return false;
}

int Entity::numComponents() {
	return (int)mComponents.size();
}