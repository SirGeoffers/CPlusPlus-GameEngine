
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"
#include "ECS\ECSManager.hpp"

#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\Sprite.hpp>

class GameState : public State {

public:

	GameState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

private:

	void initializeSystems();
	void createBackground();
	void createSwing();
	void startMusic();

	ECSManager mECSM;

	sf::Color clearColor;
	sf::Sprite mBackgroundSprite;

};

#endif // GAME_STATE_HPP