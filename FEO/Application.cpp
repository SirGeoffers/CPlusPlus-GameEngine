
#include "Application.hpp"
#include "Utility.hpp"
#include "State.hpp"
#include "StateIdentifiers.hpp"

#include "GameStateTitle.hpp"
#include "GameStateGame.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application() 
: mWindow(sf::VideoMode(250*4, 171*4), "Swing Simulator 20XX", sf::Style::Close)
, mTextures()
, mFonts()
, mStateStack(State::Context(mWindow, mTextures, mFonts))
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{

	mWindow.setKeyRepeatEnabled(false);
	mWindow.setVerticalSyncEnabled(true);

	mFonts.load(Fonts::Main, "Res/Fonts/Sansation.ttf");

	mTextures.load(Textures::TitleScreen, "Res/Textures/TitleBackground.png");
	mTextures.load(Textures::GameBackground, "Res/Textures/GameBackground.png");
	mTextures.load(Textures::Person, "Res/Textures/TestPerson.png");

	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10u);

	registerStates();
	mStateStack.pushState(States::Title);

}

void Application::run() {

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen()) {

		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame) {

			timeSinceLastUpdate -= TimePerFrame;
			processInput();
			update(TimePerFrame);

			if (mStateStack.isEmpty()) {
				mWindow.close();
			}

		}

		updateStatistics(dt);
		render();

	}

}

void Application::processInput() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		mStateStack.handleEvent(event);
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}

void Application::update(sf::Time dt) {
	mStateStack.update(dt);
}

void Application::render() {
	mWindow.clear();
	mStateStack.draw();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Application::updateStatistics(sf::Time dt) {
	mStatisticsUpdateTime += dt;
	mStatisticsNumFrames += 1;
	if (mStatisticsUpdateTime >= sf::seconds(1.0f)) {
		mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Application::registerStates() {
	mStateStack.registerState<TitleState>(States::Title);
	mStateStack.registerState<TitleState>(States::Menu);
	mStateStack.registerState<GameState>(States::Game);
	mStateStack.registerState<TitleState>(States::Loading);
	mStateStack.registerState<TitleState>(States::Pause);
	mStateStack.registerState<TitleState>(States::Settings);
	mStateStack.registerState<TitleState>(States::GameOver);
}