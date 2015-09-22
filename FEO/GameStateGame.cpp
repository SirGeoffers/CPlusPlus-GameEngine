
#include "GameStateGame.hpp"
#include "ResourceHolder.hpp"

#include "ECS\Entity.hpp"
#include "ECS\Component.hpp"
#include "ECS\System.hpp"

#include "ECS\Components\ComponentPosition.hpp"
#include "ECS\Components\ComponentSprite.hpp"
#include "ECS\Components\ComponentVelocity.hpp"
#include "ECS\Systems\SystemRender.hpp"
#include "ECS\Systems\SystemMovement.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mECSM()
	, clearColor(sf::Color(237,182,31))
{

	initializeSystems();
	createBackground();
	createSwing();
	startMusic();

	// TESTING

	sf::Sprite* personSprite = new sf::Sprite();
	personSprite->setTexture(getContext().textures->get(Textures::Person));
	personSprite->setScale(sf::Vector2f(-4.0f, 4.0f));

	Entity* testPerson = new Entity(2);
	testPerson->addComponent(new ComponentPosition(20, 550));
	testPerson->addComponent(new ComponentVelocity(0.1f, 0));
	testPerson->addComponent(new ComponentSprite(personSprite));

	mECSM.registerEntity(testPerson);

	// DONE TESTING

}

void GameState::draw() {
	sf::RenderWindow& window = *getContext().window;
	window.clear(clearColor);
	mECSM.draw();
}

bool GameState::update(sf::Time dt) {
	mECSM.update(dt);
	return true;
}

bool GameState::handleEvent(const sf::Event& event) {
	return true;
}

void GameState::initializeSystems() {

	SystemRender* sr = new SystemRender(&(*getContext().window));
	SystemMovement* sm = new SystemMovement();

	mECSM.addSystem(sr);
	mECSM.addSystem(sm);

}

void GameState::createBackground() {

	sf::Sprite* backgroundSprite = new sf::Sprite();
	backgroundSprite->setTexture(getContext().textures->get(Textures::GameBackground));
	backgroundSprite->setScale(sf::Vector2f(4.0f, 4.0f));

	Entity* background = new Entity(1);
	background->addComponent(new ComponentPosition(0, 0));
	background->addComponent(new ComponentSprite(backgroundSprite));

	mECSM.registerEntity(background);

}

void GameState::createSwing() {

}

void GameState::startMusic() {

}