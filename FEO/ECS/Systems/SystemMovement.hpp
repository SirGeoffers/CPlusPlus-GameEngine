
#ifndef ECS_SYSTEM_MOVEMENT_HPP
#define ECS_SYSTEM_MOVEMENT_HPP

#include "../System.hpp"

class SystemMovement : public System {

public:

	SystemMovement();

	virtual void update(sf::Time dt);

};

#endif // ECS_SYSTEM_MOVEMENT_HPP