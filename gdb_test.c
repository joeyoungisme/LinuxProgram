#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    char message[] = "hello world";

    a = 10;
    b = 20;
    c = 30;

    a += b;
    b += c;
    a -= c - b;

    return 0;
}
