#ifndef STATEGAME_H
#define STATEGAME_H

#include <abstractstate.h>
#include <SFML/Graphics.hpp>
#include <htblock.h>
#include <httowerbase.h>
#include <cstdint>
#include <conf.h>

class StateGame : AbstractState
{
    public:
        StateGame(sf::RenderWindow* app, bool isPlayMode, unsigned int elements, bool hasTimer, unsigned int countdown = 0);
        virtual ~StateGame();
        bool exec();
        int errorCode();

    private:
        int m_errCode;
        bool isActive = false;
        bool m_isPlayMode;
};

#endif // STATEGAME_H
