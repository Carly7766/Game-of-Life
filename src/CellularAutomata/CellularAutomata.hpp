#ifndef GAME_OF_LIFE_CELLULARAUTOMATA_HPP
#define GAME_OF_LIFE_CELLULARAUTOMATA_HPP

#include "../Constants.hpp"
#include "Coordinate.hpp"
#include <unordered_map>

class CellularAutomata {
private:
    std::unordered_map<Coordinate, bool> cells;
    std::unordered_map<Coordinate, bool> nextGeneration;

public:
    CellularAutomata() = default;
    void generateChunk(const Coordinate &chunkPosition);
    void Update();
    int CountNeighbors(const Coordinate &position);
    bool getCell(const Coordinate &pos);
    void setCell(const Coordinate &pos, bool value);
};

#endif//GAME_OF_LIFE_CELLULARAUTOMATA_HPP
