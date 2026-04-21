#pragma once

#include <vector>

template<typename T>
class Grid {
    size_t width;
    size_t height;
    std::vector<T> data;
        
public:
    Grid(size_t width, size_t height) : width(width), height(height),
        data(width * height) {}

    size_t getWidth() const {
        return width;
    }

    size_t getHeight() const {
        return height;
    }

    T& operator()(size_t x, size_t y) {
        return data[y * width + x];
    }

    const T& operator()(size_t x, size_t y) const {
        return data[y * width + x];
    }
};