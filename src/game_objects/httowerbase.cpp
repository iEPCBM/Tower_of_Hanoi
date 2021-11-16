#include "httowerbase.h"

HTTowerBase::HTTowerBase(sf::Vector2u winSize, char index) : m_shape(sf::Vector2f(HT_TOWER_BASE_WIDTH, HT_TOWER_BASE_HEIGHT))
{
    m_shape.setFillColor(sf::Color(HT_TOWER_BASE_COLOR));
}

HTTowerBase::~HTTowerBase()
{
    //dtor
}
/** @brief getShape
  *
  * @todo: document this function
  */
sf::RectangleShape HTTowerBase::getShape()
{
    return m_shape;
}
