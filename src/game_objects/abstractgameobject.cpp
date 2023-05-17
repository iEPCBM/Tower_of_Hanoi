#include "abstractgameobject.h"

AbstractGameObject::~AbstractGameObject()
{
    m_renderWindow = NULL;
}
/** @brief AbstractGameObject
  *
  * @todo: document this function
  */
AbstractGameObject::AbstractGameObject(sf::RenderWindow* renderWindow)
{
    m_renderWindow = renderWindow;
}
