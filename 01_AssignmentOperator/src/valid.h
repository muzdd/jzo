#ifndef _VALID_H
#define _VALID_H
#include <stdio.h>
class A
{
public:
    A(int n);
    A(const A& other);
    void Print();
private:
    int value;
};
#endif //VALID_H
