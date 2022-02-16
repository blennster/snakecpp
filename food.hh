#pragma once

#include "block.hh"

class Food : public Block
{
private:
    int rnd_limit;
public:
    Food(int size, int rnd_limit);
    ~Food();
    // Move to a random position
    void Move();
};