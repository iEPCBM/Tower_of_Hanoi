#include "stategame.h"

StateGame::StateGame(sf::RenderWindow* app, bool isPlayMode, unsigned int elements, bool hasTimer, unsigned int countdown)
    : AbstractState(app)
{
    //ctor
    m_isPlayMode = isPlayMode;
}

StateGame::~StateGame()
{
    //dtor
}

/** @brief exec
  *
  * @todo: document this function
  */
bool StateGame::exec()
{
    isActive = true;
    // Load a sprite to display
    sf::Texture tx_bg;
    if (!tx_bg.loadFromFile(PATH_BG_PLAYER))
        return EXIT_FAILURE;
    sf::Sprite sprite_bg(tx_bg);
    sprite_bg.setScale(sf::Vector2f((float)m_renderWindow->getSize().x/tx_bg.getSize().x,
                                   (float)m_renderWindow->getSize().y/tx_bg.getSize().y));

    m_renderWindow->create(sf::VideoMode(800, 600), "Tower of Hanoi", sf::Style::Close);
    HTTowerBase tbase(m_renderWindow->getSize(), 0);

    while (m_renderWindow->isOpen())
    {
        // Process events
        sf::Event event;
        while (m_renderWindow->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                m_renderWindow->close();
        }

        //sprite.rotate(0.1f);

        // Clear screen
        m_renderWindow->clear();

        // Draw the sprite
        m_renderWindow->draw(sprite_bg);
        m_renderWindow->draw(tbase.getShape());

        // Update the window
        m_renderWindow->display();
    }
    return true;
}

/** @brief errorCode
  *
  * @todo: document this function
  */
int StateGame::errorCode()
{
    return m_errCode;
}
