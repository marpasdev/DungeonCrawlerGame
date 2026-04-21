#include "tileregistry.h"

void TileRegistry::add(TileType type, TileData data) {
    this->data.insert_or_assign(type, std::move(data));
}

const TileData& TileRegistry::getData(TileType type) const {
    return data.at(type);
}
