#include <stdio.h>
#include <iostream>
#include <vector>
#include<SDL2/SDL.h>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

void drawRedPoint(SDL_Renderer* renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void drawColorPoint(SDL_Renderer* renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, random(0, 255), random(0, 255), random(0, 255), 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void drawColorRect(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, random(0, 255), random(0, 255), random(0, 255), 255);

    SDL_Rect rect = {
        x: random(0, SCREEN_WIDTH),
        y : random(0, SCREEN_HEIGHT),
        w : random(0, 20),
        h : random(0, 20),
    };
    SDL_RenderDrawRect(renderer, &rect);
}

std::vector <std::vector<int>> randomMap(std::vector <std::vector<int>>& map) {
    for (int h = 0; h < SCREEN_HEIGHT; h++) {
        for (int w = 0; w < SCREEN_HEIGHT; w++) {
            map[h][w] = random(0, 1);
        }
    }
}


int main(int argc, char** argv) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    std::vector <std::vector<int>> map;
    // [h][w]    



    window = SDL_CreateWindow(
        "Visualisation",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    while (true) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

        for (int h = 0; h < SCREEN_HEIGHT; h++) {
            for (int w = 0; w < SCREEN_HEIGHT; w++) {
                drawColorPoint(renderer, h, w);
            }
        }

        //drawColorRect(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}