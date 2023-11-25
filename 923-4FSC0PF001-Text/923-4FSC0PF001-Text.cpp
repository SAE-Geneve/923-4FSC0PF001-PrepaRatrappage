

#include <iostream>

#include "GameText.h"
#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    GameText unDeuxTrois("1.. 2.. 3..", window.getSize().x / 2, window.getSize().y / 2);
    GameText quatreCinqSix("4.. 5.. 6..", window.getSize().x / 2, 100 + window.getSize().y / 2);

    while (window.isOpen())
    {

    	sf::Mouse mouse;

        unDeuxTrois.Off();
        quatreCinqSix.Off();

        if (mouse.isButtonPressed(sf::Mouse::Left))
            unDeuxTrois.On();

        if (mouse.isButtonPressed(sf::Mouse::Right))
            quatreCinqSix.On();

        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;

        while (window.pollEvent(event))
        {

            switch (event.type)
            {
                // �v�nement "fermeture demand�e" : on ferme la fen�tre
            case sf::Event::Closed:
                window.close();
                break;

            default:
                break;
            }

        }



        // Graphical Region
        window.clear(sf::Color::Black);

        unDeuxTrois.Draw(window);
        quatreCinqSix.Draw(window);

        // Window Display
        window.display();

    }



}
