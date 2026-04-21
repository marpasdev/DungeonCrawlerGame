#include "room.h"

Room::Room(size_t width, size_t height) : width(width), height(height), floorGrid(width, height) {

}

size_t Room::getWidth() const {
    return width;
}

size_t Room::getHeight() const {
    return height;
}

void Room::generate() {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            floorGrid(x, y) = TileType::DiamondPlate;
        }
    }
}

void Room::draw(sf::RenderWindow& window, const TileRegistry& tileReg) {
    size_t width = getWidth();
    size_t height = getHeight();
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            sf::Sprite tile = sf::Sprite(tileReg.getData(floorGrid(x, y)).texture);
            tile.setPosition({static_cast<float>(x) * 16, static_cast<float>(y) * 16});
            window.draw(tile);
        }
    }
}