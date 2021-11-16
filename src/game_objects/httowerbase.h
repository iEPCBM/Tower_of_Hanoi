#ifndef HTTOWERBASE_H
#define HTTOWERBASE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <conf.h>

class HTTowerBase
{
    public:
        HTTowerBase(sf::Vector2u winSize, char index);
        ~HTTowerBase();

        sf::RectangleShape getShape();
    private:
        sf::RectangleShape m_shape;
};

#endif // HTTOWERBASE_H
