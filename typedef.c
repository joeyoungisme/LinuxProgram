#include<stdio.h>
#include<stdlib.h>

typedef void (*myfunc)(int num);

typedef void myfunc2(int num);

void joe_print(int num)
{
    printf("This is print function (%d)\n", num);
}

int main(int argc, char *argv[])
{
    myfunc joe = joe_print;

    myfunc2 *joe2 = joe_print;

    joe(100);

    joe2(200);


    return 0;
}
