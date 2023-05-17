#include "stategame.h"

#include <cstdlib>

StateGame::StateGame(sf::RenderWindow* app, bool isPlayMode, unsigned int elements, bool hasTimer, unsigned int countdown)
    : AbstractState(app)
{
    //ctor
    m_isPlayMode = isPlayMode;
    m_elementsCount = elements;
    m_hasTimer = hasTimer;
    m_countdown = countdown;
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

    m_renderWindow->close();
    m_renderWindow->create(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "Tower of Hanoi", sf::Style::Close|sf::Style::Fullscreen);

    sf::Music music;
    if (!music.openFromFile(std::string(PATH_MUSIC)))
        return false;
    // Load a sprite to display
    sf::Texture tx_bg;
    std::string strBgPath = "";
    if (m_isPlayMode)
        strBgPath = std::string(PATH_BG_PLAYER)+std::to_string(m_elementsCount%9)+".jpg";
    else
        strBgPath = std::string(PATH_BGS)+"ai_solver_bg.jpg";
    if (!tx_bg.loadFromFile(strBgPath))
        return EXIT_FAILURE;
    sf::Sprite sprite_bg(tx_bg);
    sprite_bg.setScale(sf::Vector2f((float)m_renderWindow->getSize().x/tx_bg.getSize().x,
                                   (float)m_renderWindow->getSize().y/tx_bg.getSize().y));

    sf::Text text_timer;
    sf::Font base_font;
    if (!base_font.loadFromFile(PATH_FONT))
        return EXIT_FAILURE;
    text_timer.setFont(base_font);
    text_timer.setCharacterSize(56);
    text_timer.setPosition(24,24);
    text_timer.setFillColor(sf::Color::Red);

    //HTTowerBase tbase(m_renderWindow, m_renderWindow->getSize(), 0);

    //tbase.setBlocksList(blocks_start);
    //HTBlock block(m_renderWindow, m_elementsCount-2, m_elementsCount);


    TowersSet towers_set(m_renderWindow, sf::Vector2f(SCR_WIDTH, SCR_HEIGHT), m_elementsCount);

    music.setLoop(true);
    music.play();
    isActive = true;

    sf::SoundBuffer soundBuf;
    sf::Sound sound;
    if(soundBuf.loadFromFile(PATH_INSRT_SOUND)) {
        sound.setBuffer(soundBuf);
    }

    sf::Clock gameClock;
    AIDriver drvAI(m_elementsCount, 0, 2, 1);
    int strategy_iter = 0;

    bool winDelta = false;
    while (m_renderWindow->isOpen()&&isActive)
    {
        // Process events
        sf::Event event;
        while (m_renderWindow->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                m_renderWindow->close();
                isActive = false;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    isActive = false;
                    m_gotoMenu = true;
                }
            }
            if (m_isPlayMode && (m_countdown>0||!m_hasTimer)) {
                towers_set.eventProcess(event, &sound);
            }
        }
        if (!m_isPlayMode && gameClock.getElapsedTime().asMilliseconds()>500 && strategy_iter<drvAI.getStrategy().size()) {
            uint8_t from = drvAI.getStrategy()[strategy_iter].from;
            uint8_t to = drvAI.getStrategy()[strategy_iter].to;
            towers_set.moveBlock(from, to);
            strategy_iter++;
            gameClock.restart();
        }
        else if (m_isPlayMode && m_hasTimer && gameClock.getElapsedTime().asSeconds()>1 && m_countdown>0) {
            m_countdown--;
            gameClock.restart();
        }

        towers_set.update();
        if (m_hasTimer && m_isPlayMode && !towers_set.isWin()) {
            text_timer.setString(std::to_string(m_countdown));
        }
        if (m_isPlayMode) {
            if (towers_set.isWin()) {
                text_timer.setString(L"Вы выиграли!");
            }
            else if (m_countdown<=0) {
                text_timer.setString(L"Вы проиграли!");
            }
            winDelta = towers_set.isWin();
        }
        // Clear screen
        m_renderWindow->clear();

        // Draw the sprite
        m_renderWindow->draw(sprite_bg);
        towers_set.draw();
        if ((m_hasTimer||towers_set.isWin()) && m_isPlayMode)
            m_renderWindow->draw(text_timer);
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

/** @brief isExitToMainMenu
  *
  * @todo: document this function
  */
bool StateGame::isExitToMainMenu()
{
    return m_gotoMenu;
}
