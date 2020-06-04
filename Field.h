#ifndef FIELD_H
#define FIELD_H
#include<iostream>

class Field
{
private:
    int length, width;
public:
    Field();

    int getLength() const { return length; };
    int getWidth() const { return width; };

    void setLength(int length_) { length = length_; };
    void setWidth(int width_) { width = width_; };
    void showField(int, int);
};
#endif
