
#ifndef ECS_MANAGER_HPP
#define ECS_MANAGER_HPP

#include "Entity.hpp"
#include "ComponentIdentifiers.hpp"
#include "System.hpp"

#include <SFML\System\Time.hpp>
#include <vector>

class ECSManager {

public:

	ECSManager();

	void update(sf::Time dt);
	void draw();

	void addSystem(System* system);
	int getNumSystems();

	void registerEntity(Entity* entity);
	void removeEntity(int id);

private:

	std::vector<System*> mSystems;

};

#endif //ECS_MANAGER_HPP