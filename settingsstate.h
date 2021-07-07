#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "menustate.h"

enum class SettingsButton
{
    Easy = 1,
    Medium = 2,
    Hard = 3
};

class SettingsState : public MenuState
{
public:
    void Init(sf::RenderWindow *appWindow, std::vector<std::unique_ptr<GameState> > *gameStates, Config *configInfo) override;
    void Draw() override;
    void HandleInput() override;

private:
    SettingsButton pressed = SettingsButton::Easy;

    void Back();
};

#endif
