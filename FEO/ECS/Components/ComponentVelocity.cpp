
#include "ComponentVelocity.hpp"

ComponentVelocity::ComponentVelocity() {
	init(0, 0);
}

ComponentVelocity::ComponentVelocity(float xi, float yi) {
	init(xi, yi);
}

ComponentVelocity::ComponentVelocity(sf::Vector2f initialVelocity) {
	init(initialVelocity.x, initialVelocity.y);
}

sf::Vector2f* ComponentVelocity::getVelocity() {
	return mVelocity;
}

void ComponentVelocity::setVelocity(float newX, float newY) {
	mVelocity->x = newX;
	mVelocity->y = newY;
}

void ComponentVelocity::setVelocity(sf::Vector2f newVelocity) {
	mVelocity->x = newVelocity.x;
	mVelocity->y = newVelocity.y;
}

void ComponentVelocity::init(float xi, float yi) {
	setType(Components::Velocity);
	mVelocity = new sf::Vector2f();
	mVelocity->x = xi;
	mVelocity->y = yi;
}