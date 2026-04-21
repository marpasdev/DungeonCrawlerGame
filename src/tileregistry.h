#pragma once

#include <unordered_map>

#include "tile.h"

class TileRegistry {
    std::unordered_map<TileType, TileData> data;

public:

    void add(TileType type, TileData data);

    const TileData& getData(TileType type) const;
};