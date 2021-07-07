#include "menustate.h"
#include "playingstate.h"
#include "settingsstate.h"

#include <stdexcept>
#include <iostream>

void MenuState::Init(sf::RenderWindow *appWindow, std::vector<std::unique_ptr<GameState> > *gameStates, Config *configInfo)
{
    config = configInfo;
    states = gameStates;
    window = appWindow;

    try
    {
        LoadSprite("background");
        LoadSprite("buttons/play");
        LoadSprite("buttons/playPressed");
        LoadSprite("buttons/exit");
        LoadSprite("buttons/exitPressed");
        LoadSprite("buttons/settings");
        LoadSprite("buttons/settingsPressed");
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        window->close();
    }

    sprites["buttons/play"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f - 20.0f));
    sprites["buttons/settings"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 100.0f));
    sprites["buttons/exit"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 220.0f));

    sprites["buttons/playPressed"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f - 20.0f));
    sprites["buttons/settingsPressed"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 100.0f));
    sprites["buttons/exitPressed"].setPosition(sf::Vector2f(window->getSize().x / 2.0f - 50.0f, window->getSize().y / 2.0f + 220.0f));
}

void MenuState::Update()
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void MenuState::Draw()
{
    window->draw(sprites["background"]);

    if (pressed == MenuButton::Play) window->draw(sprites["buttons/playPressed"]);
    else window->draw(sprites["buttons/play"]);

    if (pressed == MenuButton::Settings) window->draw(sprites["buttons/settingsPressed"]);
    else window->draw(sprites["buttons/settings"]);

    if (pressed == MenuButton::Exit) window->draw(sprites["buttons/exitPressed"]);
    else window->draw(sprites["buttons/exit"]);

    window->display();
}

void MenuState::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        switch (pressed)
        {
        case MenuButton::Play:
            states->push_back(std::make_unique<PlayingState>());
            states->back()->Init(window, states, config);
            break;

        case MenuButton::Settings:
            states->push_back(std::make_unique<SettingsState>());
            states->back()->Init(window, states, config);
            break;

        case MenuButton::Exit:
            window->close();
            break;

        default:
            break;
        }
    }
    else if (keyHelper.wasKeyDown(sf::Keyboard::Up) && static_cast<int>(pressed) > 1)
    {
        int temp = static_cast<int>(pressed);
        temp--;
        pressed = static_cast<MenuButton>(temp);
    }
    else if (keyHelper.wasKeyDown(sf::Keyboard::Down) && static_cast<int>(pressed) < 3)
    {
        int temp = static_cast<int>(pressed);
        temp++;
        pressed = static_cast<MenuButton>(temp);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window->close();
    }
}

void MenuState::LoadSprite(std::string name)
{
    sf::Sprite tempSprite;

    textures.push_back(std::make_unique<sf::Texture>());

    if(!textures.back()->loadFromFile(name + ".png"))
    {
        throw std::runtime_error("Couldn't load image data for the image " + name + "!");
    }

    tempSprite.setTexture(*textures.back());
    sprites[name] = tempSprite;
}
