#include "CellularAutomata.hpp"
#include "Coordinate.hpp"

void CellularAutomata::generateChunk(const Coordinate &chunkPosition) {
    for (int y = 0; y < CHUNK_SIZE; ++y) {
        for (int x = 0; x < CHUNK_SIZE; ++x) {
            Coordinate cellPosition(chunkPosition.x * CHUNK_SIZE + x, chunkPosition.y * CHUNK_SIZE + y);
            cells[cellPosition] = false;
        }
    }
}

void CellularAutomata::Update() {
    nextGeneration.clear();
    for (const auto &cell: cells) {
        Coordinate position = cell.first;
        int neighbors = CountNeighbors(position);
        nextGeneration[position] = (neighbors == 3 || (neighbors == 2 && cell.second));
    }
    cells.swap(nextGeneration);
}

int CellularAutomata::CountNeighbors(const Coordinate &position) {
    int count = 0;
    for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
            if (x == 0 && y == 0) continue;
            Coordinate neighborPosition(position.x + x, position.y + y);
            if (cells.count(neighborPosition) && cells[neighborPosition]) {
                ++count;
            }
        }
    }
    return count;
}

bool CellularAutomata::getCell(const Coordinate &position) {
    return cells.count(position) != 0 && cells[position];
}

void CellularAutomata::setCell(const Coordinate &position, bool value) {
    if (cells.count(position) != 0) {
        cells[position] = value;
    }
}
