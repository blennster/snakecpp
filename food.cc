#include "food.hh"
#include <stdlib.h>
#include <random>

Food::Food(int size, int rnd_limit) : Block::Block(size)
{
    this->rnd_limit = rnd_limit;
    Move();
    r = 230;
    b = 60;
    g = 60;
}

void Food::Move()
{
    int rnd_x = rand() % rnd_limit;
    int rnd_y = rand() % rnd_limit;

    x = rnd_x * size;
    y = rnd_y * size;
}