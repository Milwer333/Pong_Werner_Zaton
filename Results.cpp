#include "Results.h"
#include<fstream>
#include<string>
#include<stdlib.h>
#include<conio.h>

using namespace std;

Results::Results()
{
    name = "unnamed";
    score_1 = 0;
    score_2 = 0;
}

void Results::showFileContent()
{
    fstream file_results;
    file_results.open("results.txt", ios::in);
    if (file_results.good() == false)
    {
        cout << "ERROR" << endl;
        exit(0);
    }
    string line;
    while (getline(file_results, line))
        cout << line << endl;
    file_results.close();
}

void Results::addElement()
{
    fstream file_results;
    file_results.open("results.txt", ios::out | ios::app);
    file_results << name << endl;
    file_results << player_1 << "\t";
    file_results << getScore_1() << endl;
    file_results << player_2 << "\t";
    file_results << getScore_2() << endl << endl;
    file_results.close();
}

void Results::deleteElement()
{
    fstream file_results;
    file_results.open("results.txt", ios::out | ios::trunc );
    if (file_results.good() == false)
    {
        cout << "ERROR" << endl;
        exit(0);
    }
    file_results.close();
    system("cls");
}
