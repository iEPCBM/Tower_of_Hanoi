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
    menu.exec();
    std::cout<<menu.getState().elementsCount;
	// Start the game loop
	if (app.isOpen()) {
        StateGame game(&app,
                       menu.getState().isPlayMode&(!menu.getState().isSolveMode),
                       menu.getState().elementsCount,
                       menu.getState().hasTimer,
                       menu.getState().timerSVal);
        game.exec();
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
