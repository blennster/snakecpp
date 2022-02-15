#ifndef Snake_H
#define Snake_H

#include "tail.h"

#define DIR_UP 1
#define DIR_DOWN -1
#define DIR_LEFT -2
#define DIR_RIGHT 2

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
    Snake(int size);
    ~Snake();
    void SetDirection(int direction);
    void Move(double delta_time);
    void AddTail(Tail* tail);
    void Speedup(float factor);
    bool HitTest();
};

#endif