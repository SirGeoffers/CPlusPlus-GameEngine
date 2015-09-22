
#ifndef ECS_COMPONENT_SPRITE_HPP
#define ECS_COMPONENT_SPRITE_HPP

#include "../Component.hpp"

#include <SFML\Graphics\Sprite.hpp>

class ComponentSprite : public Component {

public:

	ComponentSprite();
	ComponentSprite(sf::Sprite* sprite);

	sf::Sprite* getSprite();
	void setSprite(sf::Sprite* sprite);

private:

	void init(sf::Sprite* initialSprite);

	sf::Sprite* mSprite;

};

#endif // ECS_COMPONENT_SPRITE_HPP