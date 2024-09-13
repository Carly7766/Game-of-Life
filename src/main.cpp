#include "./CellularAutomata/CellularAutomata.hpp"
#include "Constants.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

void NextStep(int &currentStep, CellularAutomata &cellularAutomata) {
    std::string logString = std::string("Step: ") + std::to_string(currentStep) + "\n";
    for (int y = 0; y < CHUNK_SIZE; ++y) {
        for (int x = 0; x < CHUNK_SIZE; ++x) {
            Coordinate cellPosition(x, y);
            if (cellularAutomata.getCell(cellPosition)) {
                logString += "X";
            } else {
                logString += ".";
            }
        }
        logString += "\n";
    }

    std::cout << logString << std::endl;

    currentStep++;
    cellularAutomata.Update();
}

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not Initialize SDL! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "SDL initialized");

    window = SDL_CreateWindow("Life of Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Window created");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Renderer created");

    // Initialize
    int step = 0;
    CellularAutomata cellularAutomata{};
    cellularAutomata.generateChunk(Coordinate{0, 0});
    cellularAutomata.setCell(Coordinate{7, 7}, true);
    cellularAutomata.setCell(Coordinate{6, 7}, true);
    cellularAutomata.setCell(Coordinate{8, 7}, true);
    cellularAutomata.setCell(Coordinate{7, 6}, true);
    cellularAutomata.setCell(Coordinate{7, 8}, true);

    NextStep(step, cellularAutomata);

    //Polling events
    SDL_bool isRunning = SDL_TRUE;
    SDL_bool spaceKeyDown = SDL_FALSE;
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = SDL_FALSE;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && event.key.repeat == 0) {
                        spaceKeyDown = SDL_TRUE;
                    }
                    break;
            }
        }

        // Update
        if (spaceKeyDown) {
            NextStep(step, cellularAutomata);
        }

        // Post update
        spaceKeyDown = SDL_FALSE;

        // Render
        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
