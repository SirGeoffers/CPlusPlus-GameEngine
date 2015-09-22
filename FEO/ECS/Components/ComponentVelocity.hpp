
#ifndef ECS_COMPONENT_VELOCITY_HPP
#define ECS_COMPONENT_VELOCITY_HPP

#include "../Component.hpp"

#include "SFML\System\Vector2.hpp"

class ComponentVelocity : public Component {

public:

	ComponentVelocity();
	ComponentVelocity(float xi, float yi);
	ComponentVelocity(sf::Vector2f initialVelocity);
	
	sf::Vector2f* getVelocity();
	void setVelocity(float newX, float newY);
	void setVelocity(sf::Vector2f newVelocity);

private:

	void init(float xi, float yi);

	sf::Vector2f* mVelocity;

};

#endif // ECS_COMPONENT_VELOCITY_HPP