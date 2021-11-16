#include "abstractstate.h"

AbstractState::AbstractState(sf::RenderWindow* app)
{
    m_renderWindow = app;
}

AbstractState::~AbstractState()
{
    //dtor
    m_renderWindow = NULL;
}
