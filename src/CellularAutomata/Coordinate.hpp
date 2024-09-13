#ifndef GAME_OF_LIFE_COORDINATE_HPP
#define GAME_OF_LIFE_COORDINATE_HPP

#include <functional>

struct Coordinate {
    int x, y;

    explicit Coordinate(int x, int y) : x(x), y(y) {}

    Coordinate &operator=(const Coordinate &v) = default;

    bool operator==(const Coordinate &v) const {
        return (x == v.x && y == v.y);
    }

    bool operator!=(const Coordinate &v) const {
        return (x != v.x || y != v.y);
    }

    Coordinate operator+(const Coordinate &v) const {
        return Coordinate(x + v.x, y + v.y);
    }
};

namespace std {
    template<>
    struct hash<Coordinate> {
        size_t operator()(const Coordinate &v) const {
            std::uint64_t hash = 5381;

            hash = ((hash << 5) + hash) + v.x;
            hash = ((hash << 5) + hash) + v.y;

            return static_cast<std::size_t>(hash);
        }
    };
}// namespace std

#endif//GAME_OF_LIFE_COORDINATE_HPP
