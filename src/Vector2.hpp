#ifndef GAME_OF_LIFE_VECTOR2_HPP
#define GAME_OF_LIFE_VECTOR2_HPP

#include <functional>

struct Vector2 {
    int x, y;
    explicit Vector2(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Vector2 &other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template<>
    struct hash<Vector2> {
        size_t operator()(const Vector2 &v) const {
            std::uint64_t hash = 5381;

            hash = ((hash << 5) + hash) + v.x;
            hash = ((hash << 5) + hash) + v.y;

            return static_cast<std::size_t>(hash);
        }
    };
}// namespace std

#endif//GAME_OF_LIFE_VECTOR2_HPP
