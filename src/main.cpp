#include <SFML/Graphics.hpp>

#include "player.h"

int main()
{
    // TODO: check if this resolution is enough
    sf::VideoMode nativeResolution{{1280, 720}};

    sf::RenderWindow window(sf::VideoMode(nativeResolution), "SFML Game");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::View view(window.getDefaultView());
    // gets scaled up
    view.setSize({320, 180});

    sf::Texture playerTexture("textures/player.png");
    sf::Sprite prop(playerTexture);
    prop.setPosition({100, 100});

    Player player = Player();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        window.clear();
            player.update(deltaTime);
            view.setCenter(player.getPosition());   // TODO: add half texture offset to center the player correctly
            window.setView(view);
            player.draw(window);
            
            window.draw(prop);

        window.display();
    }
}
