#include <SFML/Graphics.hpp>

#include "player.h"
#include "tileregistry.h"
#include "room.h"

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

    TileRegistry tileReg;

    sf::Texture diamondPlateTexture("textures/diamondplate.png");
    TileData diamondPlateData = TileData(diamondPlateTexture);
    tileReg.add(TileType::DiamondPlate, diamondPlateData);

    Room room = Room(20, 20);
    room.generate();

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

            room.draw(window, tileReg);
            window.draw(prop);
            player.draw(window);

        window.display();
    }
}
