#ifndef TOWERSSET_H
#define TOWERSSET_H

#include <httowerbase.h>
#include <vector>

class TowersSet : AbstractGameObject
{
    public:
        TowersSet(sf::RenderWindow* renderWindow, sf::Vector2f towersSize, int blocksCount);
        virtual ~TowersSet();
        void draw();
        void update();
        void eventProcess(sf::Event event, sf::Sound* sound);
        bool isWin();
        void moveBlock(uint8_t from, uint8_t to);
    private:
        std::vector<HTTowerBase> m_towers;
        uint32_t m_blocksCount;
};

#endif // TOWERSSET_H
