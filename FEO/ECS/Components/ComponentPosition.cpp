
#include "ComponentPosition.hpp"

ComponentPosition::ComponentPosition() {
	init(0, 0);
}

ComponentPosition::ComponentPosition(float xi, float yi) {
	init(xi, yi);
}

ComponentPosition::ComponentPosition(sf::Vector2f initialPosition) {
	init(initialPosition.x, initialPosition.y);
}

sf::Vector2f* ComponentPosition::getPosition() {
	return mPosition;
}

void ComponentPosition::setPosition(float newX, float newY) {
	mPosition->x = newX;
	mPosition->y = newY;
}

void ComponentPosition::setPosition(sf::Vector2f newPosition) {
	mPosition->x = newPosition.x;
	mPosition->y = newPosition.y;
}

void ComponentPosition::init(float x, float y) {
	setType(Components::Position);
	mPosition = new sf::Vector2f();
	mPosition->x = x;
	mPosition->y = y;
}