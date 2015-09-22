
#include "GameStateTitle.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

TitleState::TitleState(StateStack& stack, Context context)
	:State(stack, context)
	, mText()
	, mShowText(true)
	, mTextEffectTime(sf::Time::Zero)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
}

void TitleState::draw() {
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
}

bool TitleState::update(sf::Time dt) {
	return true;
}

bool TitleState::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyReleased) {
		requestStackPop();
		requestStackPush(States::Game);
	}
	return true;
}