#include "reverse_words.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    ReverseWord RW;
    char a[]="hello world!";
    //printf("%s\n",RW.strrevw(a));
    printf("%s\n",RW.reverse_string(a));
    
    return 0;
}

