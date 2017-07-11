#include<stdio.h>
#include<stdlib.h>

char *subfunc(int num)
{
    static char message[50];
    snprintf(message, 50, "%s%d", "joeyoung", num);
    return message;
}

int main(int argc, char *argv[])
{
    for(int index = 0; index < 100; ++index)
        printf("%s(%X)\n", subfunc(index), subfunc(index));

    return 0;
}


