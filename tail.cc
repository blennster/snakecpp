#include "tail.hh"

void Tail::Render(SDL_Renderer *renderer) {
    if (nullptr != Next && this != Next)
    {
        Next->Render(renderer);
    }

    Block::Render(renderer);
}

void Tail::Move(int x, int y)
{
    if (nullptr != Next && this != Next)
    {
        Next->Move(this->x, this->y);
    }

    Block::Move(x, y);
}

Tail::~Tail() {
    if (nullptr != Next && this != Next)
    {
        delete Next;
    }
}