#include "snake.hh"

Snake::Snake(int size, int x, int y) : Tail(size) {
    Next = this;
    this->x = x;
    this->y = y;
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
        case Snake::UP:
            dy = -size;
            break;
        case Snake::DOWN:
            dy = size;
            break;
        case Snake::LEFT:
            dx = -size;
            break;
        case Snake::RIGHT:
            dx = size;
            break;
        default:
            return;
    }

    Move(1000);
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

void Snake::Speedup(float amount) {
    speed_factor += amount;
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

bool Snake::OutOfBounds(int cellcount)
{
    if ((x / size + 1) % (cellcount + 1) == 0 || (y / size + 1) % (cellcount + 1) == 0) {
        return true;
    }

    return false;
}