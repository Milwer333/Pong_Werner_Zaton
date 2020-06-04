#ifndef BALL_H
#define BALL_H
#include<iostream>

class Paddle;
class Results;
enum enumDirection { STOP = 0, UPLEFT = 1, DOWNLEFT = 2, UPRIGHT = 3, DOWNRIGHT = 4 };
class Ball
{
private:
	int x, y, speed;
	int startx, starty;
	enumDirection direction;
public:
	Ball(int, int, int);

	void setDirection(enumDirection dir) { direction = dir; };
	void setX(int x_) { x = x_; };
	void setY(int y_) { y = y_; };
	void setStartx(int startx_) { startx = startx_; };
	void setStarty(int starty_) { starty = starty_; };

	int getX() const { return x; };
	int getY() const { return y; };
	int getSpeed() const { return speed; };
	enumDirection getDirection() { return direction; };

	void randomDirection();
	void showBall(int, int, int);
	void Move(int, int);
	void Reset();

	//ball coordinate tester
	friend std::ostream& operator<<(std::ostream& o, Ball b)
	{
		o << "Ball [" << b.x << "," << b.y << "][" << b.direction << "]";
		return o;
	}
	friend void paddleBounce(Paddle p, Ball& b, Results& result_);
};
#endif
