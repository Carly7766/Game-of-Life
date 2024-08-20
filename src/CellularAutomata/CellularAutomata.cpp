#include "CellularAutomata.hpp"

void CellularAutomata::generateChunk(const Vector2 &chunkPosition) {
    for (int y = 0; y < CHUNK_SIZE; ++y) {
        for (int x = 0; x < CHUNK_SIZE; ++x) {
            Vector2 cellPosition(chunkPosition.x * CHUNK_SIZE + x, chunkPosition.y * CHUNK_SIZE + y);
            cells[cellPosition] = false;
        }
    }
}

void CellularAutomata::Update() {
    nextGeneration.clear();
    for (const auto &cell: cells) {
        Vector2 position = cell.first;
        int neighbors = CountNeighbors(position);
        nextGeneration[position] = (neighbors == 3 || (neighbors == 2 && cell.second));
    }
    cells.swap(nextGeneration);
}

int CellularAutomata::CountNeighbors(const Vector2 &position) {
    int count = 0;
    for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
            if (x == 0 && y == 0) continue;
            Vector2 neighborPosition(position.x + x, position.y + y);
            if (cells.count(neighborPosition) && cells[neighborPosition]) {
                ++count;
            }
        }
    }
    return count;
}

bool CellularAutomata::getCell(const Vector2 &position) {
    return cells.count(position) != 0 && cells[position];
}

void CellularAutomata::setCell(const Vector2 &position, bool value) {
    if (cells.count(position) != 0) {
        cells[position] = value;
    }
}
