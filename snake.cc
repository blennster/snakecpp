#include "snake.h"
#include "constants.h"

Snake::Snake(int size) : Tail(size) {
    Next = this;
    x = size*10;
    y = size*10;
    SetDirection(DIR_LEFT);
}

void Snake::SetDirection(int direction)
{
    this->direction = direction;

    if ((direction + prev_direction) == 0 || direction == prev_direction) {
        return;
    }

    dy = 0;
    dx = 0;

    switch (direction)
    {
        case DIR_UP:
            dy = -BLOCK_SIZE;
            break;
        case DIR_DOWN:
            dy = BLOCK_SIZE;
            break;
        case DIR_LEFT:
            dx = -BLOCK_SIZE;
            break;
        case DIR_RIGHT:
            dx = BLOCK_SIZE;
            break;
        default:
            return;
    }

}

void Snake::Move(double delta_time)
{
    cumulated_time += delta_time;

    if (cumulated_time * speed_factor < 1000) {
        return;
    }

    Tail::Move(x + dx, y + dy);

    prev_direction = direction;

    cumulated_time = 0;
}

void Snake::AddTail(Tail* tail) {
    if (Next == this) {
        Next = tail;
    } else {
        Last->Next = tail;
    }

    Last = tail;
}

void Snake::Speedup(float factor) {
    speed_factor += factor;
}

bool Snake::HitTest() {
    if (Next == this) {
        return false;
    }

    Tail* cur = Next;
    while (nullptr != cur) {
        if (cur->HitTest(this)) {
            return true;
        }
        cur = cur->Next;
    }

    return false;
}