#include "htblock.h"

HTBlock::HTBlock(sf::RenderWindow* renderWindow, uint16_t blockSize, uint16_t maxSize) :
    AbstractGameObject(renderWindow)
{
    m_blockSize = blockSize;
    m_maxSize = maxSize;
    m_shape.setSize(getSize());
    //m_shape.setOrigin(getSize()/2.0f);
    m_shape.setFillColor(generateColor());
    m_shape.setOrigin(getSize().x/2, HT_BLOCK_HEIGHT);
}

HTBlock::~HTBlock()
{
    //dtor
}
/** @brief getBlockSize
  *
  * @todo: document this function
  */
uint16_t HTBlock::getBlockSize()
{
    return m_blockSize;
}

/** @brief draw
  *
  * @todo: document this function
  */
void HTBlock::draw()
{
    m_renderWindow->draw(m_shape);
}

/** @brief generateColor
  *
  * @todo: document this function
  */
sf::Color HTBlock::generateColor()
{
    char alpha = 0xFF;
    char r, g, b;
    r = (0x1F * m_blockSize*m_maxSize)%0xAF+0x30;
    g = (0x20 * (m_blockSize+1)*m_maxSize)%0xAF+0x30;
    b = (0xFA * (m_blockSize+2)*m_maxSize)%0xAF+0x30;
    return sf::Color(r,g,b);
}

/** @brief getSize
  *
  * @todo: document this function
  */
sf::Vector2f HTBlock::getSize()
{
    float k = ((float)HT_BLOCK_MAX_WIDTH-HT_BLOCK_MIN_WIDTH)/m_maxSize;
    float width = k * m_blockSize + HT_BLOCK_MIN_WIDTH;
    return sf::Vector2f(width, HT_BLOCK_HEIGHT);
}
/** @brief update
  *
  * @todo: document this function
  */
void HTBlock::update(sf::Vector2f towerPos, int queueNum)
{
    if (m_isMouseAttached) {
        m_shape.setPosition(sf::Mouse::getPosition(*m_renderWindow).x,
                            sf::Mouse::getPosition(*m_renderWindow).y+HT_BLOCK_HEIGHT/2);
    }
    else {
        m_shape.setPosition(towerPos.x, towerPos.y-(queueNum*HT_BLOCK_HEIGHT));
    }
}
/** @brief eventProcess
  *
  * @todo: document this function
  */
void HTBlock::eventProcess(sf::Event event)
{
    sf::Vector2f sz = m_shape.getSize();
    sf::Vector2f pos = m_shape.getPosition()-m_shape.getOrigin();
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.x>=pos.x && event.mouseButton.x<pos.x+sz.x &&
            event.mouseButton.y>=pos.y && event.mouseButton.y<pos.y+sz.y) {
            m_isMouseAttached = true;
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.x>=pos.x && event.mouseButton.x<pos.x+sz.x &&
            event.mouseButton.y>=pos.y && event.mouseButton.y<pos.y+sz.y) {
            m_isMouseAttached = false;

            sf::SoundBuffer soundBuf;
            if(soundBuf.loadFromFile(PATH_INSRT_SOUND)) {
                sf::Sound sound;
                sound.setBuffer(soundBuf);
                sound.play();
            }
            else {
                exit(0);
            }
        }
    }
}
/** @brief isMouseAttached
  *
  * @todo: document this function
  */
bool HTBlock::isMouseAttached()
{
    return m_isMouseAttached;
}

