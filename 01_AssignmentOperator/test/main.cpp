#include "AssignmentOperator.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");



    return 0;
}

