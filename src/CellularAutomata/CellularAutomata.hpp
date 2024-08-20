#ifndef GAME_OF_LIFE_CELLULARAUTOMATA_HPP
#define GAME_OF_LIFE_CELLULARAUTOMATA_HPP

#include "../Vector2.hpp"
#include <unordered_map>

const int CHUNK_SIZE = 16;

class CellularAutomata {
private:
    std::unordered_map<Vector2, bool> cells;
    std::unordered_map<Vector2, bool> nextGeneration;

public:
    CellularAutomata() = default;
    void generateChunk(const Vector2 &chunkPosition);
    void Update();
    int CountNeighbors(const Vector2 &position);
    bool getCell(const Vector2 &pos);
    void setCell(const Vector2 &pos, bool value);
};

#endif//GAME_OF_LIFE_CELLULARAUTOMATA_HPP
