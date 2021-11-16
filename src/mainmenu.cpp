#include "mainmenu.h"

MainMenu::MainMenu(sf::RenderWindow* app) : AbstractState(app)
{
    //ctor
}

MainMenu::~MainMenu()
{
    //dtor
}

/** @brief exec
  *
  * @todo: document this function
  */
bool MainMenu::exec()
{
    isActive = true;
    m_renderWindow->create(sf::VideoMode(800, 600), "Main Menu");
    m_gui.setWindow(*m_renderWindow);
    m_gui.loadWidgetsFromFile("./assets/form.txt");
    initEventHandler();
    bool feedback = loop();
    return feedback;
}

/** @brief errorCode
  *
  * @todo: document this function
  */
int MainMenu::errorCode()
{
    return m_errCode;

}

/** @brief loop
  *
  * @todo: document this function
  */
bool MainMenu::loop()
{
    while (m_renderWindow->isOpen()&&isActive)
    {
        sf::Event event;
        while (m_renderWindow->pollEvent(event))
        {
            m_gui.handleEvent(event);
            if (event.type == sf::Event::Closed) {
                m_renderWindow->close();
                isActive = false;
            }
        }
        m_renderWindow->clear();
        m_gui.draw();
        m_renderWindow->display();
    }
    return true;
}
/**
@brief initEventHandler
  *
  * @todo: document this function
  */
void MainMenu::initEventHandler()
{
    m_gui.get<tgui::Button>("bt_play")->onPress([&]{play();});
    m_gui.get<tgui::Button>("bt_play")->onPress([&]{});
}

/** @brief play
  *
  * @todo: document this function
  */
void MainMenu::play()
{

}

/** @brief getState
  *
  * @todo: document this function
  */
MenuState MainMenu::getState()
{
    return m_menuState;
}
