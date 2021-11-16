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
    m_renderWindow->create(sf::VideoMode(800, 600), "Main Menu", sf::Style::Close);
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
    m_gui.get<tgui::Button>("bt_play")->onPress(&MainMenu::play, this);
    m_gui.get<tgui::Button>("bt_showSolve")->onPress(&MainMenu::solve, this);
    m_gui.get<tgui::CheckBox>("chb_timer")->onChange(&MainMenu::onChbTimerUpdate, this);
}

/** @brief play
  *
  * @todo: document this function
  */
void MainMenu::play()
{
    updateMenuState();
    m_menuState.isPlayMode = true;
    isActive = false;
}

/** @brief solve
  *
  * @todo: document this function
  */
void MainMenu::solve()
{
    updateMenuState();
    m_menuState.isSolveMode = true;
    isActive = false;
}

/** @brief onChbTimerUpdate
  *
  * @todo: document this function
  */
void MainMenu::onChbTimerUpdate(bool checked)
{
    m_gui.get<tgui::EditBox>("eb_countdown")->setEnabled(checked);
}

/** @brief getState
  *
  * @todo: document this function
  */
MainMenu::MenuState MainMenu::getState()
{
    return m_menuState;
}

/** @brief updateMenuState
  *
  * @todo: document this function
  */
void MainMenu::updateMenuState()
{
    m_menuState.hasTimer = m_gui.get<tgui::CheckBox>("chb_timer")->isChecked();
    m_menuState.isCreepyMode = m_gui.get<tgui::CheckBox>("chb_dzone")->isChecked();
    if (m_menuState.hasTimer) {
        m_menuState.timerSVal = m_gui.get<tgui::EditBox>("eb_countdown")->getText().toInt();
    }
    m_menuState.elementsCount = m_gui.get<tgui::EditBox>("eb_elcount")->getText().toInt();
}
