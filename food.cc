#include "food.h"
#include <stdlib.h>
#include <random>

unsigned int seed = 100;

Food::Food(int size) : Block::Block(size)
{
    Move();
}

void Food::Move()
{
    seed++;
    int rnd_x = rand_r(&seed) % 20;
    seed++;
    int rnd_y = rand_r(&seed) % 20;

    x = rnd_x * size;
    y = rnd_y * size;
}