#include "GameManager.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>

using namespace std;
GameManager::GameManager(Paddle &R, Paddle &L, Results &G, Field &F) : Right(R), Left(L), Game(G), Field_(F) {}

void gotoxy__(int x1, int y1)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    _COORD pos;
    pos.X = x1;
    pos.Y = y1;
    SetConsoleCursorPosition(hConsole, pos);
}

void GameManager::play()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
    string player_1, player_2, name;
    int points, difficulty;
    char choose;

    //using these setter you can change the field size without changing the default constructor
    //Field_.setWidth(36);
    //Field_.setLength(150);

    Right.setSize_paddle(7);
    Right.setX(Field_.getLength()-5);
    Right.setY((Field_.getWidth()-6)/2);
    Right.setDirection(0);

    Left.setSize_paddle(7);
    Left.setX(4);
    Left.setY((Field_.getWidth() - 6) / 2);
    Left.setDirection(0);

    cout << "Enter name of the game" << endl;
    getline(cin, name);
    cout << "Enter name of player 1" << endl;
    cin >> player_1;
    cout << "Enter name of player 2" << endl;
    cin >> player_2;
    cout << "Enter speed of the ball" << endl;
    cout << "1 -  easy\t2 - normal\t3 - hard" << endl;
    cin >> difficulty;
    while(cin.fail() || (difficulty <= 0 || difficulty >= 4))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input error" << endl;
        cout << "Try again" << endl;
        cin >> difficulty;
    }
    Ball Ball_((Field_.getLength() - 6) / 2, (Field_.getWidth() - 6) / 2, difficulty);
    cout << "Enter to how many points you want to play" << endl;
    cin >> points;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input error" << endl;
        cout << "Try again" << endl;
        cin >> points;
    }

    Game.setName(name);
    Game.setPlayer1(player_1);
    Game.setPlayer2(player_2);

    system("cls");
    Sleep(1000);
    Field_.showField(Field_.getLength(), Field_.getWidth());
    Right.showPaddle(Right.getX(), Right.getY(), Right.getSize_paddle());
    Left.showPaddle(Left.getX(), Left.getY(), Left.getSize_paddle());
    Sleep(1000);

    while (Game.getScore_1() < points && Game.getScore_2() < points)
    {
        Ball_.showBall(Ball_.getX(), Ball_.getY(), Ball_.getSpeed());
        Ball_.Move(Field_.getLength(), Field_.getWidth());
        if (Ball_.getDirection() == STOP)
            Ball_.randomDirection();

        paddleBounce(Right, Ball_, Game);
        paddleBounce(Left, Ball_, Game);

        gotoxy__(0, Field_.getWidth()+1);
        cout << "W/UP ARROW - move up" << endl;
        cout << "S/DOWN ARROW - move down" << endl << endl << endl;
        cout << "Score " << points << " points to win!" << endl;
        cout << player_1 << ": " << Game.getScore_1() << endl;
        cout << player_2 << ": " << Game.getScore_2();
        if (Ball_.getDirection() == 3 || Ball_.getDirection() == 4)
        {
            Right.setY(Right.movePaddle(Right.getX(), Right.getY(), Ball_.getDirection(), Field_.getWidth()));
            Right.showPaddle(Right.getX(), Right.getY(), Right.getSize_paddle());
        }
        else
        {
            Left.setY(Left.movePaddle(Left.getX(), Left.getY(), Ball_.getDirection(), Field_.getWidth()));
            Left.showPaddle(Left.getX(), Left.getY(), Left.getSize_paddle());
        }
    }
    system("cls");
    if (Game.getScore_1() == points)
        cout << "CONGRATULATIONS, " << player_1 << " WIN!!!" << "\a";
    else
        cout << "CONGRATULATIONS, " << player_2 << " WIN!!!" << "\a";
    Game.addElement();
    cout << endl << endl;

    Game.showFileContent();
    cout << "Do you want to delete file's content? Y/N" << endl;
    cin >> choose;
    if (choose == 'Y' || choose == 'y')
    {
        Game.deleteElement();
        Game.showFileContent();
    }
    cout << "\n\n";
    system("pause");
}

void paddleBounce(Paddle p, Ball& b, Results& result_)
{
    //right paddle
    if (b.getX() == (p.getX() - 1))
    {
        if ((b.getY() <= (p.getY() + (p.getSize_paddle()))) && (b.getY() >= (p.getY()) - 1))
        {
            b.setDirection((b.getDirection()) == UPRIGHT ? UPLEFT : DOWNLEFT);
            Beep(1000, 50);
        }
        else
        {
            result_.addScore_1();
            b.Reset();
            Beep(100, 500);
            Sleep(600);
        }
    }
    //left paddle
    if (b.getX() == (p.getX() + 1))
    {
        if ((b.getY() <= (p.getY() + (p.getSize_paddle()))) && (b.getY() >= (p.getY()) - 1))
        {
            b.setDirection((b.getDirection()) == UPLEFT ? UPRIGHT : DOWNRIGHT);
            Beep(1000, 50);
        }
        else
        {
            result_.addScore_2();
            b.Reset();
            Beep(100, 500);
            Sleep(600);
        }
    }
}

