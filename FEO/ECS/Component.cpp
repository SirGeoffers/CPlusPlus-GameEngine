
#include "Component.hpp"

Component::Component() {
	mParent = nullptr;
	mType = Components::None;
}

void Component::setType(Components::ID type) {
	mType = type;
}

Components::ID Component::getType() {
	return mType;
}

void Component::setParent(Entity* entity) {
	mParent = entity;
}

Entity* Component::getParent() {
	return mParent;
}