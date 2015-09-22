
#ifndef ECS_SYSTEM_RENDER_HPP
#define ECS_SYSTEM_RENDER_HPP

#include "../System.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

class SystemRender : public System {

public:

	SystemRender(sf::RenderWindow* window);

	virtual void update(sf::Time dt);
	virtual void draw();

private:

	sf::RenderWindow* mWindow;

};

#endif // ECS_SYSTEM_RENDER_HPP