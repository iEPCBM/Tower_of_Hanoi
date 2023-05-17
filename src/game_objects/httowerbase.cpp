#include "httowerbase.h"

HTTowerBase::HTTowerBase(sf::RenderWindow* renderWindow, sf::Vector2f pos, char index, uint32_t elCount)
    : AbstractGameObject(renderWindow)
{
    uint32_t height;
    if ((elCount+2)*HT_BLOCK_HEIGHT>HT_TOWER_BASE_HEIGHT) {
        height = (elCount+2)*HT_BLOCK_HEIGHT;
    }
    else {
        height = HT_TOWER_BASE_HEIGHT;
    }
    m_shape.setSize(sf::Vector2f(HT_TOWER_BASE_WIDTH, height));
    m_shape.setFillColor(sf::Color(HT_TOWER_BASE_COLOR));
    m_shape.setOrigin((float)HT_TOWER_BASE_WIDTH/2, height);
    m_shape.setPosition(pos);
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
/** @brief getBlocksList
  *
  * @todo: document this function
  */
std::vector<HTBlock> HTTowerBase::getBlocksList()
{
    return m_blocks;
}

/** @brief setBlocksList
  *
  * @todo: document this function
  */
void HTTowerBase::setBlocksList(std::vector<HTBlock>blocks)
{
    m_blocks = blocks;
}

/** @brief popBlock
  *
  * @todo: document this function
  */
HTBlock HTTowerBase::popBlock()
{
    HTBlock popped = m_blocks.back();
    m_blocks.pop_back();
    return popped;
}

/** @brief pushBlock
  *
  * @todo: document this function
  */
bool HTTowerBase::pushBlock(HTBlock block)
{
    m_blocks.push_back(block);
}

void HTTowerBase::draw() {
    m_renderWindow->draw(m_shape);
}

/** @brief update
  *
  * @todo: document this function
  */
void HTTowerBase::update()
{
    for (int i=0; i<m_blocks.size(); i++) {
        m_blocks[i].update(m_shape.getPosition(), i);
    }
}
/** @brief eventProcess
  *
  * @todo: document this function
  */
void HTTowerBase::eventProcess(sf::Event event)
{
    if(m_blocks.size()>0) {
        m_blocks.at(m_blocks.size()-1).eventProcess(event);
    }
}
/** @brief drawChildren
  *
  * @todo: document this function
  */
void HTTowerBase::drawChildren()
{
    for (int i=0; i<m_blocks.size(); i++) {
        m_blocks[i].draw();
    }
}
/** @brief checkInsertBlockSize
  *
  * @todo: document this function
  */
bool HTTowerBase::checkInsertBlockSize(uint16_t blockSize)
{
    return !(m_blocks.size()>0 && m_blocks.at(m_blocks.size()-1).getBlockSize()<blockSize);
}
/** @brief isPointCollision
  *
  * @todo: document this function
  */
bool HTTowerBase::isPointCollision(sf::Vector2f point)
{
    sf::Vector2f sz = m_shape.getSize();
    sf::Vector2f pos = m_shape.getPosition()-m_shape.getOrigin();
    return (point.x>=pos.x && point.x<pos.x+sz.x &&
        point.y>=pos.y && point.y<pos.y+sz.y);
}

/** @brief hasAttachedBlock
  *
  * @todo: document this function
  */
bool HTTowerBase::hasAttachedBlock()
{
    if(m_blocks.size()>0) {
        return m_blocks.at(m_blocks.size()-1).isMouseAttached();
    }
    return false;
}
