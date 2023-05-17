#ifndef ABSTRACTGMAEOBJECT_H
#define ABSTRACTGMAEOBJECT_H

#include <SFML/Graphics.hpp>

class AbstractGameObject
{
    public:
        AbstractGameObject(sf::RenderWindow* renderWindow);
        virtual ~AbstractGameObject();
        virtual void draw() = 0;

    protected:
        sf::RenderWindow* m_renderWindow;
    private:
};

#endif // ABSTRACTGMAEOBJECT_H
