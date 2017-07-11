#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    printf("Current Name = %s\n", argv[0]);

    char backup[256];

    memset(backup, 0, sizeof(backup));
    strncpy(backup, argv[0], 256);

    strncpy(argv[0], "testchange", 11);
    printf("argv [0] = %s\n", argv[0]);

    return 0;
}
