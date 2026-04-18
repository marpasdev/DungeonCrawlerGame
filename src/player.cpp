#include "player.h"

#include <SFML/Window/Keyboard.hpp>

Player::Player() : texture("textures/player.png"), sprite(texture) {
    sprite.setPosition({0, 0}); 
}

void Player::move(float deltaTime) {
    sf::Vector2f direction{0, 0};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        --direction.y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        ++direction.y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        --direction.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        ++direction.x;
    }

    if (direction.lengthSquared() > 1) {
        direction = direction.normalized();
    }

    sprite.move(direction * speed * deltaTime);
}

void Player::update(float deltaTime) {
    move(deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}