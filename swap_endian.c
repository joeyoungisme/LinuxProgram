#include<stdio.h>
#include<stdlib.h>

typedef union {
    long lnum;
    unsigned char cnum[4];
}my_type;

unsigned int swap_endian(unsigned int var)
{
    int after = ((var << 8) & 0xFF00FF00) | ((var >> 8) & 0xFF00FF);
    after = (after << 16) | (after >> 16);

    return after;
}

int main(int argc, char *argv[])
{
    my_type joe;

    joe.lnum = 0x12345678;

    for(int index = 0; index < 4; ++index)
        printf("cnum[%d] = %X\n", index, (unsigned int)joe.cnum[index]);

    joe.lnum = swap_endian((unsigned int)joe.lnum);

    for(int index = 0; index < 4; ++index)
        printf("cnum[%d] = %X\n", index, (unsigned int)joe.cnum[index]);

    return 0;
}


