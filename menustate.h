#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "gamestate.h"

#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include <memory>

enum class MenuButton
{
    Play = 1,
    Settings = 2,
    Exit = 3
};

struct Keys
{
    bool wasKeyDown(sf::Keyboard::Key key)
    {
        if (sf::Keyboard::isKeyPressed(key))
        {
            if (keyCodes.find(key) == keyCodes.end())
            {
                keyCodes.insert(key);
                return true;
            }
        }
        else if (keyCodes.find(key) != keyCodes.end())
        {
            keyCodes.erase(key);
        }

        return false;
    }

    std::unordered_set<sf::Keyboard::Key> keyCodes;
};

class MenuState : public GameState
{
public:
    virtual void Init(sf::RenderWindow *appWindow, std::vector<std::unique_ptr<GameState> > *gameStates, Config *configInfo) override;
    void Update() override;
    virtual void Draw() override;
    virtual void HandleInput() override;

protected:
    void LoadSprite(std::string name);

    std::vector<std::unique_ptr<sf::Texture> > textures;
    std::map<std::string, sf::Sprite> sprites;

    Keys keyHelper;

private:
    MenuButton pressed = MenuButton::Play;
};

#endif
