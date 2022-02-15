#include "game.h"
#include "SDL2/SDL.h"
#include "snake.h"
#include "food.h"
#include "constants.h"
#include <iostream>

void Game::Run()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    SDL_Window *window;
    SDL_Renderer *renderer;

    window = SDL_CreateWindow("Snakegame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE, SIZE, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    double dt = 1;
    uint64_t last_time = SDL_GetTicks64();
    uint64_t now;
    Snake *snake = new Snake(BLOCK_SIZE);
    Food *food = new Food(BLOCK_SIZE);
    bool game_over = false;
    int score = 0;

    while (!game_over)
    {
        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    snake->SetDirection(DIR_UP);
                    break;
                case SDLK_DOWN:
                    snake->SetDirection(DIR_DOWN);
                    break;
                case SDLK_LEFT:
                    snake->SetDirection(DIR_LEFT);
                    break;
                case SDLK_RIGHT:
                    snake->SetDirection(DIR_RIGHT);
                    break;
                default:
                    break;
                }
            }
        }

        now = SDL_GetTicks64();
        dt = now - last_time;
        last_time = now;
        snake->Move(dt);

        if (food->HitTest(snake))
        {
            food->Move();
            snake->AddTail(new Tail(BLOCK_SIZE));
            snake->Speedup(0.4);
            score++;
        }

        if (score == SIZE * SIZE - 1)
        {
            game_over = true;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderClear(renderer);
        }

        if (snake->HitTest())
        {
            game_over = true;
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderClear(renderer);
        }

        // render code goes here.....
        snake->Render(renderer);
        food->Render(renderer);

        // Move buffer to front
        SDL_RenderPresent(renderer);
        // Our frames will be so fast that this is rougly 60fps
        SDL_Delay(16);
    }

    while (1)
    {
        SDL_Delay(10);
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }
    }
    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
