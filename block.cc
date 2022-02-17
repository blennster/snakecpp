#include <SDL2/SDL.h>
#include "block.hh"

Block::Block(int size)
{
    this->size = size;
    this->x = -100;
    this->y = -100;
    r = 255;
    g = 255;
    b = 255;
}

void Block::Render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect = {x, y, size, size};
    SDL_RenderFillRect(renderer, &rect);
}

void Block::Move(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Block::GetX() const
{
    return x;
}

int Block::GetY() const
{
    return y;
}

bool Block::HitTest(Block *other) const
{
    bool isHit = other->GetX() == x && other->GetY() == y;

    return isHit;
}

void Block::SetColor(int red, int green, int blue)
{
    r = red;
    g = green;
    b = blue;
}
