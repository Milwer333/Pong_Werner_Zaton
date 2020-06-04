#include "Paddle.h"
#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

int const W_KEY = 119;
int const S_KEY = 115;
int const UP_ARROW = 72;
int const DOWN_ARROW = 80;
int const PREFIX = 224;

void gotoxy(int x1, int y1)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    _COORD pos;
    pos.X = x1;
    pos.Y = y1;
    SetConsoleCursorPosition(hConsole, pos);
}

Paddle::Paddle()
{
    x = 0;
    y = 0;
    size_paddle = 5;
    direction = 0;
}

int Paddle::movePaddle(int x_, int y_, int ball_direction, int width_)
{
    int key, S_key;
    if (ball_direction == 3 || ball_direction == 4)
    {
        if (kbhit())
        {
            gotoxy(x_, y_);
            key = getch();

            if (key == PREFIX)
                S_key = getch();
            if (key == PREFIX && S_key == DOWN_ARROW && y <  width_-size_paddle-3)
            {
                direction = 1;
                y_++;
                return y_;
            }
            else if (key == PREFIX && S_key == UP_ARROW && y > 3)
            {
                direction = -1;
                y_--;
                return y_;
            }
        }
        return y_;
    }
    else
    {
        if (kbhit())
        {
            gotoxy(x_, y_);
            key = getch();
            if (key == S_KEY && y < width_ - size_paddle - 3)
            {
                direction = 1;
                y_++;
                return y_;
            }
            else if (key == W_KEY && y > 3)
            {
                direction = -1;
                y_--;
                return y_;
            }
        }
        return y_;
    }
}

void Paddle::showPaddle(int x_, int y_, int size_paddle_)
{
    if (direction == 0)
    {
        for (int i = y_; i < y_ + size_paddle_; i++)
        {
            gotoxy(x_, i);
            cout << "\xBA";
        }
        gotoxy(x_, y_ + size_paddle_);
        cout << " ";
    }
    else  if (direction == 1)
    {
        gotoxy(x_, y_ - 1);
        cout << " ";
        gotoxy(x_, y_ + size_paddle_ - 1);
        cout << "\xBA";
    }
    else if (direction == -1)
    {
        gotoxy(x_, y_ + size_paddle_);
        cout << " ";
        gotoxy(x_, y_);
        cout << "\xBA";
    }
}
