#include <SDL2/SDL.h>
#include "block.hh"

Block::Block(int size)
{
    this->size = size;
    this->x = -100;
    this->y = -100;
}

void Block::Render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = {x, y, size, size};
    SDL_RenderFillRect(renderer, &rect);
}

void Block::Move(int x, int y) {
    this->x = x;
    this->y = y;
}

int Block::GetX() {
    return x;
}

int Block::GetY() {
    return y;
}

bool Block::HitTest(Block *other)
{
    bool isHit = other->GetX() == x && other->GetY() == y;

    return isHit;
}