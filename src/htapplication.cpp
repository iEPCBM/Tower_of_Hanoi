#include "htapplication.h"

HTApplication::HTApplication()
{
    //ctor
}

HTApplication::~HTApplication()
{
    //dtor
}
/** @brief exec
  *
  * @todo: document this function
  */
int HTApplication::exec()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600, 8), "HANOI");

    MainMenu menu(&app);
    std::cout<<menu.getState().elementsCount;

    StateGame game(&app,
                   menu.getState().isPlayMode&(!menu.getState().isSolveMode),
                   menu.getState().elementsCount,
                   menu.getState().hasTimer,
                   menu.getState().timerSVal);
	// Start the game loop
	bool stateMenu = true;
	while (app.isOpen()) {
        if (stateMenu) {
            menu.exec();
            game = StateGame (&app,
                   menu.getState().isPlayMode&(!menu.getState().isSolveMode),
                   menu.getState().elementsCount,
                   menu.getState().hasTimer,
                   menu.getState().timerSVal);
            stateMenu = false;
        }
        else {
            game.exec();
            stateMenu = game.isExitToMainMenu();
        }
	}

    return EXIT_SUCCESS;
}

/** @brief exitCode
  *
  * @todo: document this function
  */
int HTApplication::exitCode()
{
    return m_exitCode;
}
