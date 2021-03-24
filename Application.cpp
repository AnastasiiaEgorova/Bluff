#include "Application.h"

#include "State.h"
#include "StateIdentifiers.h"

//#include "GameState.h"
#include "TitleState.h"
#include "PauseState.h"
#include "MenuState.h"
#include "GameOverState.h"
#include "ChooseOpponentsState.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application()
    : window(sf::VideoMode(1278, 720), "Bluff")
    , textures()
    , fonts()
    , player()
    , music()
    , sounds()
    , stateStack(State::Context(window, textures, fonts, player, music, sounds))
    , statsUpdateTime()
    , statsNumFrames(0)
{
    window.setKeyRepeatEnabled(false);

    fonts.load(FontID::Main, "Media/Sansation.ttf");
    //textures.load(TextureID::TitleScreen, "Media/Textures/TitleScreen.png");	
   
    registerStates();
    stateStack.pushState(StateID::Opponents);

    music.setVolume(25.f);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        // time has gone by in that loop
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processInput();
            update(TimePerFrame);

            if (stateStack.isEmpty())
                window.close();
        }

        updateStatistics(elapsedTime);
        render();
    }
}

void Application::processInput()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        stateStack.handleEvent(event);

        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Application::update(sf::Time dt)
{
    stateStack.update(dt);
}

void Application::render()
{
    window.clear();
    stateStack.draw();

    window.setView(window.getDefaultView());
    window.display();
}

void Application::updateStatistics(sf::Time et)
{
    statsUpdateTime += et;
    statsNumFrames += 1;

    if (statsUpdateTime >= sf::seconds(1.0f)) {
        statsUpdateTime -= sf::seconds(1.0f);
        statsNumFrames = 0;
    }
}

void Application::registerStates()
{
    stateStack.registerState<TitleState>(StateID::Title);
    //TO DO
    // add instruction state
    stateStack.registerState<MenuState>(StateID::Menu);
    stateStack.registerState<ChooseOpponentsState>(StateID::Opponents);
    //stateStack.registerState<GameState>(StateID::Game);
    stateStack.registerState<PauseState>(StateID::Pause);
    stateStack.registerState<GameOverState>(StateID::GameOver);
}
