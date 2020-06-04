#include "Paddle.h"
#include "Field.h"
#include "Ball.h"
#include "Results.h"
#include "GameManager.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
	Paddle Right, Left;
	Results Game_;
	Field F1;
	GameManager  Game(Right, Left, Game_, F1);
	Game.play();
	return 0;
}
