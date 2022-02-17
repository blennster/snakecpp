#pragma once

#include <SDL2/SDL.h>

class Block
{
protected:
    int size;
    int x, y;
    int r, g, b;

public:
    Block(int size);
    virtual ~Block() {};
    void Render(SDL_Renderer *renderer);
    virtual void Move(int x, int y);
    int GetX() const;
    int GetY() const;
    bool HitTest(Block *other) const;
    void SetColor(int red, int green, int blue);
};
