#include "towersset.h"

TowersSet::TowersSet(sf::RenderWindow* renderWindow, sf::Vector2f towersSize, int blocksCount)
    : AbstractGameObject(renderWindow)
{
    float y = towersSize.y;
    for (int i=0; i<3; i++) {
        m_towers.push_back(HTTowerBase(m_renderWindow, sf::Vector2f((towersSize.x/4)*(i+1), y), i, blocksCount));
    }
    std::vector<HTBlock> blocks_start;
    for (int i=0; i<blocksCount; i++) {
        blocks_start.push_back(HTBlock(m_renderWindow, blocksCount-1-i, blocksCount));
    }
    m_towers.front().setBlocksList(blocks_start);
    //ctor
}

TowersSet::~TowersSet()
{
    //dtor
}

/** @brief draw
  *
  * @todo: document this function
  */
void TowersSet::draw()
{
    for(int i=0; i<m_towers.size(); i++) {
        m_towers[i].draw();
    }
    for(int i=0; i<m_towers.size(); i++) {
        m_towers[i].drawChildren();
    }
}

/** @brief update
  *
  * @todo: document this function
  */
void TowersSet::update()
{
    for(int i=0; i<m_towers.size(); i++) {
        m_towers[i].update();
    }
}

/** @brief eventProcess
  *
  * @todo: document this function
  */
void TowersSet::eventProcess(sf::Event event, sf::Sound* sound)
{
    if (event.type == sf::Event::MouseButtonReleased) {
        for(int i=0; i<m_towers.size(); i++) {
            if (m_towers[i].isPointCollision(sf::Vector2f(event.mouseButton.x,
                                            event.mouseButton.y))) {
                for(int j=0; j<m_towers.size(); j++) {
                    if(m_towers[j].hasAttachedBlock() &&
                       m_towers[i].checkInsertBlockSize(m_towers[j].getBlocksList().back().getBlockSize())) {
                        m_towers[i].pushBlock(m_towers[j].popBlock());
                        sound->play();
                        break;
                    }
                }
                break;
            }
        }
    }
    for(int i=0; i<m_towers.size(); i++) {
        m_towers[i].eventProcess(event);
    }
}
/** @brief isWin
  *
  * @todo: document this function
  */
bool TowersSet::isWin()
{
    bool hasUnstagedBlocks = false;
    for (auto i=0; i<m_towers.size()-1; i++) {
        hasUnstagedBlocks |= m_towers[i].getBlocksList().size()>0;
    }
    return m_towers.back().getBlocksList().size()>0 && !hasUnstagedBlocks;
}

/** @brief moveBlock
  *
  * @todo: document this function
  */
void TowersSet::moveBlock(uint8_t from, uint8_t to)
{
    if (from >= m_towers.size() || to >= m_towers.size())
        return;

    m_towers[to].pushBlock(m_towers[from].popBlock());
}
