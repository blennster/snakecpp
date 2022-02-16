#pragma once

#include <SDL2/SDL.h>

class Block
{
protected:
    int size;
    int x;
    int y;
    Block();
public:
    Block(int size);
    ~Block();
    void Render(SDL_Renderer *renderer);
    virtual void Move(int x, int y);
    int GetX();
    int GetY();
    bool HitTest(Block* other);
};
