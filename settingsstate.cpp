#include "settingsstate.h"

#include <iostream>

void SettingsState::Init(sf::RenderWindow *appWindow, std::vector<std::unique_ptr<GameState> > *gameStates, Config *configInfo)
{
    config = configInfo;
    states = gameStates;
    window = appWindow;

    try
    {
        LoadSprite("background");
        LoadSprite("buttons/easy");
        LoadSprite("buttons/easyPressed");
        LoadSprite("buttons/medium");
        LoadSprite("buttons/mediumPressed");
        LoadSprite("buttons/hard");
        LoadSprite("buttons/hardPressed");
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        window->close();
    }

    sprites["buttons/easy"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f - 20.0f));
    sprites["buttons/medium"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 100.0f));
    sprites["buttons/hard"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 220.0f));

    sprites["buttons/easyPressed"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f - 20.0f));
    sprites["buttons/mediumPressed"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 100.0f));
    sprites["buttons/hardPressed"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 220.0f));
}

void SettingsState::Draw()
{
    window->draw(sprites["background"]);

    if (pressed == SettingsButton::Easy) window->draw(sprites["buttons/easyPressed"]);
    else window->draw(sprites["buttons/easy"]);

    if (pressed == SettingsButton::Medium) window->draw(sprites["buttons/mediumPressed"]);
    else window->draw(sprites["buttons/medium"]);

    if (pressed == SettingsButton::Hard) window->draw(sprites["buttons/hardPressed"]);
    else window->draw(sprites["buttons/hard"]);

    window->display();
}

void SettingsState::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        switch (pressed)
        {
        case SettingsButton::Easy:
            config->ballVelocity = 3.5f;
            config->racketVelocity = 7.0f;
            break;

        case SettingsButton::Medium:
            config->ballVelocity = 5.0f;
            config->racketVelocity = 10.0f;
            break;

        case SettingsButton::Hard:
            config->ballVelocity = 10.0f;
            config->racketVelocity = 20.0f;
            break;

        default:
            break;
        }
    }
    else if (keyHelper.wasKeyDown(sf::Keyboard::Up) && static_cast<int>(pressed) > 1)
    {
        int temp = static_cast<int>(pressed);
        temp--;
        pressed = static_cast<SettingsButton>(temp);
    }
    else if (keyHelper.wasKeyDown(sf::Keyboard::Down) && static_cast<int>(pressed) < 3)
    {
        int temp = static_cast<int>(pressed);
        temp++;
        pressed = static_cast<SettingsButton>(temp);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        states->pop_back();
    }
}
