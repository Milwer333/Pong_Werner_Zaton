#include "Field.h"
#include <iostream>
#include <windows.h>

using namespace std;

Field::Field()
{
    length = 86;
    width = 36;
}

void Field::showField(int length_, int width_)
{
    for (int i = 0; i < width_; i++)
    {
        for (int j = 0; j < length_; j++)
        {
            if (i >= 3 && i <= width_ - 4)
                if (j<3 || j>length_ - 4)
                    cout << "\xDB";
                else
                    cout << " ";
            else
                cout << "\xDB";
        }
        cout << endl;
    }
}
