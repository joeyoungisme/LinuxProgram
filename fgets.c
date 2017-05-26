#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{

    char test[100];
    char *ptest = fgets(test, 100, stdin);

    printf("test : %s\n", test);
    printf("ptest : %X\n", ptest);

    if(test[0] == '\0')
        printf("\\0");

    if(test[0] == '\n')
        printf("\\n");

    return 0;
}
