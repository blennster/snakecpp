#pragma once

#include "tail.hh"

class Snake: public Tail
{
private:
    char direction;
    char prev_direction;
    float cumulated_time;
    float speed_factor = 2;
    int dx,dy;
    Tail* Last;
public:
    Snake(int size, int x, int y);
    ~Snake();
    void SetDirection(int direction);
    void Move(double delta_time);
    void AddTail(Tail* tail);
    void Speedup(float amount);
    bool HitTest();
    bool OutOfBounds(int cellcount);
    // These will add up nicely
    static const int UP = 1;
    static const int DOWN = -1;
    static const int LEFT = -2;
    static const int RIGHT = 2;
};
