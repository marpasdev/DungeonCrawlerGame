#pragma once

#include <SFML/Graphics.hpp>

class Player {
	sf::Texture texture;
	sf::Sprite sprite;
	float speed = 100.f;

public:
	Player();

	void move(float deltaTime);

	void update(float deltaTime);

	void draw(sf::RenderWindow& window);

	sf::Vector2f getPosition() const;
};