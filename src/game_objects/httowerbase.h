#ifndef HTTOWERBASE_H
#define HTTOWERBASE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <conf.h>
#include <vector>
#include <htblock.h>

class HTTowerBase : AbstractGameObject
{
    public:
        HTTowerBase(sf::RenderWindow* renderWindow, sf::Vector2f pos, char index, uint32_t elCount);
        ~HTTowerBase();

        sf::RectangleShape getShape();
        std::vector<HTBlock> getBlocksList();
        void setBlocksList(std::vector<HTBlock> blocks);
        HTBlock popBlock();
        bool pushBlock(HTBlock block);
        void draw();
        void drawChildren();
        void update();
        void eventProcess(sf::Event event);
        bool checkInsertBlockSize(uint16_t blockSize);
        bool isPointCollision(sf::Vector2f point);
        bool hasAttachedBlock();
    private:
        sf::RectangleShape m_shape;
        std::vector<HTBlock> m_blocks;
};

#endif // HTTOWERBASE_H
