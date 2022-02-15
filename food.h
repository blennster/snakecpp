#pragma once

#include "block.h"

class Food : public Block
{
private:
    /* data */
public:
    Food(int size);
    ~Food();
    // Move to a random position
    void Move();
};