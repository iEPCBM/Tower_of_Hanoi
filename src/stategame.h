#ifndef STATEGAME_H
#define STATEGAME_H

#include <abstractstate.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <htblock.h>
#include <httowerbase.h>
#include <towersset.h>
#include <cstdint>
#include <conf.h>

#include <iostream>

#include "ai/aidriver.h"


class StateGame : AbstractState
{
    public:
        StateGame(sf::RenderWindow* app, bool isPlayMode, unsigned int elements, bool hasTimer, unsigned int countdown = 0);
        virtual ~StateGame();
        bool exec();
        bool isExitToMainMenu();
        int errorCode();

    private:
        int m_errCode;
        bool isActive = false;
        bool m_isPlayMode;
        bool m_gotoMenu = false;
        unsigned int m_elementsCount;
        bool m_hasTimer;
        unsigned int m_countdown;
};

#endif // STATEGAME_H
