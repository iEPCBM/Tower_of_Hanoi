#include <SFML/Graphics.hpp>
#include <mainmenu.h>

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600, 8), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/BSOD.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    MainMenu menu(&app);
    menu.exec();
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        //app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
