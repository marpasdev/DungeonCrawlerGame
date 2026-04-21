#pragma once

#include <vector>

#include "tile.h"
#include "grid.h"
#include "tileregistry.h"

class Room {
    size_t width;
    size_t height;
    Grid<TileType> floorGrid;
    //Grid<TileType> wallGrid;
    //std::vector<WorldObject> objects;
    //std::Grid<bool> occupiedGrid; // change to something else not using bools

public:

    Room(size_t width, size_t height);

    size_t getWidth() const;

    size_t getHeight() const;

    // placeholder function
    void generate();

    void draw(sf::RenderWindow& window, const TileRegistry& tileReg);
};