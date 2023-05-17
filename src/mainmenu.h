#ifndef MAINMENU_H
#define MAINMENU_H

#include <abstractstate.h>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <cstdint>
#include <conf.h>

class MainMenu : AbstractState
{
    public:
        explicit MainMenu(sf::RenderWindow*);
        virtual ~MainMenu();
        bool exec();
        int errorCode();

        struct MenuState {
            bool isPlayMode = false;
            bool isSolveMode = false;
            bool hasTimer = false;
            uint16_t timerSVal = 0;
            bool isCreepyMode = false;
            uint16_t elementsCount = 0;
        };

        MenuState getState();
    private:
        int m_errCode = 0;
        tgui::Gui m_gui;
        bool loop();
        void play();
        void solve();
        void onChbTimerUpdate(bool);
        void updateMenuState();
        void initEventHandler();
        bool isActive = false;
        MenuState m_menuState;
};

#endif // MAINMENU_H
