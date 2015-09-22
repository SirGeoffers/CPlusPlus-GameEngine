
#ifndef ECS_SYSTEM_HPP
#define ECS_SYSTEM_HPP

#include "Entity.hpp"
#include "ComponentIdentifiers.hpp"

#include <SFML\System\Time.hpp>
#include <vector>
#include <map>

class System {

public:

	System();
	virtual ~System();

	bool hasRequiredComponents(Entity* entity);
	void addRequiredComponent(Components::ID id);
	std::vector<Components::ID*> getRequiredComponents();

	void addEntity(Entity* entity);
	void removeEntity(int id);

	virtual void update(sf::Time dt) {};
	virtual void draw() {};

protected:

	std::map<int, Entity*> mEntities;

private:

	std::vector<Components::ID*> mRequiredComponents;

};

#endif // ECS_SYSTEM_HPP