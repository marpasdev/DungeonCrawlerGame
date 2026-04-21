#pragma once

#include <SFML/Graphics.hpp>

enum class TileType {
    Void,
    DiamondPlate
};

struct TileData {
    sf::Texture texture;

    TileData();

    TileData(sf::Texture texture);
};