#include "Ball.h"
#include <time.h>
#include<stdlib.h>
#include<iostream>
#include<windows.h>

using namespace std;

void gotoxy_(int x1, int y1)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x1;
	pos.Y = y1;
	SetConsoleCursorPosition(hConsole, pos);
}

Ball::Ball(int startx_, int starty_, int speed_)
{

    speed = (4 - speed_) * 25;
	startx = startx_;
	starty = starty_;
	x = startx_;
	y = starty_;
	direction = STOP;
}

void Ball::Reset()
{
	x = startx;
	y = starty;
	direction = STOP;
}

void Ball::randomDirection()
{
	srand(time(NULL));
	direction = (enumDirection((rand() % 4) + 1));
}

void Ball::showBall(int x_, int y_, int speed_)
{
	gotoxy_(x_, y_);
	cout << "0";
	Sleep(speed_);
	cout << "\b ";
}
void Ball::Move(int length, int width)
{
	switch (direction)
	{
	case STOP:
		break;
	case UPLEFT:
		x--;
		y--;
		break;
	case DOWNLEFT:
		x--;
		y++;
		break;
	case UPRIGHT:
		x++;
		y--;
		break;
	case DOWNRIGHT:
		x++;
		y++;
		break;
	default:
		break;
	}
	int y_topwall = 3;
	int y_bottomwall = (width - 4);
	if (y == y_topwall)
		setDirection((getDirection()) == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	if (y == y_bottomwall)
		setDirection((getDirection()) == DOWNRIGHT ? UPRIGHT : UPLEFT);
}
