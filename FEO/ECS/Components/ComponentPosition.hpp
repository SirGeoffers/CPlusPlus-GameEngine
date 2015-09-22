
#ifndef ECS_COMPONENT_POSITION_HPP
#define ECS_COMPONENT_POSITION_HPP

#include "../Component.hpp"

#include <SFML\System\Vector2.hpp>

class ComponentPosition : public Component {

public:

	ComponentPosition();
	ComponentPosition(float xi, float yi);
	ComponentPosition(sf::Vector2f initialPosition);

	sf::Vector2f* getPosition();
	void setPosition(float newX, float newY);
	void setPosition(sf::Vector2f newPosition);

private:

	void init(float x, float y);

	sf::Vector2f* mPosition;

};

#endif // ECS_COMPONENT_POSITION_HPP