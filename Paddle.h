#if !defined (PALETKA_H)
#define PALETKA_H
#include<iostream>

class Ball;
class Results;
class Paddle
{
private:
    int x, y, size_paddle, direction;
public:
    Paddle();

    int getSize_paddle() const { return size_paddle; };
    int getX() const { return x; };
    int getY() const { return y; };
    int getDirection() const { return direction; };

    void setSize_paddle(int size_paddle_) { size_paddle = size_paddle_; };
    void setX(int x_) { x = x_; };
    void setY(int y_) { y = y_; };
    void setDirection(int direction_) { direction = direction_; };

    void showPaddle(int, int, int);
    int movePaddle(int, int, int, int);
    friend void paddleBounce(Paddle p, Ball& b, Results& result_);
};
#endif
