
#ifndef ECS_COMPONENT_HPP
#define ECS_COMPONENT_HPP

#include "Entity.hpp"
#include "ComponentIdentifiers.hpp"

class Entity;

class Component {

public:

	Component();

	void setType(Components::ID id);
	Components::ID getType();
	void setParent(Entity* e);
	Entity* getParent();

private:

	Components::ID mType = Components::None;
	Entity* mParent;

};

#endif // ECS_COMPONENT_HPP