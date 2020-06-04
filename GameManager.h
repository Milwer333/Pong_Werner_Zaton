#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Paddle.h"
#include "Field.h"
#include "Ball.h"
#include "Results.h"
#include <iostream>

class GameManager
{
private:
    Paddle &Right, &Left;
    Results &Game;
    Field &Field_;
public:
    GameManager(Paddle &R, Paddle &L, Results &G, Field &F);
    void play();
};
#endif
