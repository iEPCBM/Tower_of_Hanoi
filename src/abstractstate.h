#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <SFML/Graphics.hpp>

class AbstractState
{
    public:
        explicit AbstractState(sf::RenderWindow*);
        virtual ~AbstractState();
        virtual bool exec() = 0;
        virtual int errorCode() = 0;
    protected:
        sf::RenderWindow* m_renderWindow;
    private:
};

#endif // ABSTRACTSTATE_H
