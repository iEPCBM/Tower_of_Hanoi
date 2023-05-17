#ifndef HTBLOCK_H
#define HTBLOCK_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <conf.h>
#include <stdint.h>
#include <abstractgameobject.h>
#include <iostream>
#include <SFML/Audio.hpp>


class HTBlock : AbstractGameObject
{
    public:
        HTBlock(sf::RenderWindow* renderWindow, uint16_t blockSize, uint16_t maxSize);
        ~HTBlock();
        uint16_t getBlockSize();
        void update(sf::Vector2f towerPos, int queueNum);
        void eventProcess(sf::Event event);
        void draw();
        bool isMouseAttached();
    private:
        uint16_t m_blockSize;
        uint16_t m_maxSize;
        bool m_isMouseAttached = false;
        sf::RectangleShape m_shape;
        sf::Color generateColor();
        sf::Vector2f getSize();
};

#endif // HTBLOCK_H
