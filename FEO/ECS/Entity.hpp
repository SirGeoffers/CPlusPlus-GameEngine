
#ifndef ECS_ENTITY_HPP
#define ECS_ENTITY_HPP

#include "Component.hpp"
#include "ComponentIdentifiers.hpp"

#include <map>

class Component;

class Entity {

public:

	Entity();
	Entity(int id);

	int getId();

	void addComponent(Component* component);
	void removeComponent(Components::ID id);

	Component* getComponent(Components::ID id);
	bool hasComponent(Components::ID id);
	int numComponents();

private:

	int mId;
	std::map<Components::ID, Component*> mComponents;

};

#endif //ECS_ENTITY_HPP