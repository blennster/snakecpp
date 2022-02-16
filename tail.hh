#pragma once
#include "block.hh"

class Tail : public Block
{
private:
public:
    Tail(int size) : Block(size) {};
    ~Tail();
    void Render(SDL_Renderer *renderer);
    virtual void Move(int x, int y);
    Tail* Next = nullptr;
};