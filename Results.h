#ifndef RESULTS_H
#define RESULTS_H
#include<iostream>
#include<string>

class Ball;
class Paddle;
class Results
{
private:
    std::string name;
    std::string player_1;
    std::string player_2;
    int score_1, score_2;
public:
    Results();

    void setScore_1(int score_1_) { score_1 = score_1_; };
    void setScore_2(int score_2_) { score_2 = score_2_; };
    void setName(std::string name_) { name = name_; };
    void setPlayer1(std::string player_1_) { player_1 = player_1_; };
    void setPlayer2(std::string player_2_) { player_2 = player_2_; };

    int getScore_1() const { return score_1; };
    int getScore_2() const { return score_2; };
    std::string getName() const { return name; };
    std::string getPlayer1() const { return player_1; };
    std::string getPlayer2() const { return player_2; };

    void addScore_1() { score_1++; };
    void addScore_2() { score_2++; };

    void addElement();
    void deleteElement();
    void showFileContent();
    friend void paddleBounce(Paddle p, Ball& b, Results& result_);
};
#endif
