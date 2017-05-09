#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>

#define SHIFT(start,length)                 (start - length + 1)
#define GEN_MASK(start, length)             (((0x1<<length)-1) << SHIFT(start,length))
#define SETBIT(x, start, length, data)      ((x & ~(GEN_MASK(start,length))) | ((data << SHIFT(start,length)) & GEN_MASK(start,length)))


int main(int argc, char *argv[])
{
    unsigned char base = 0xAB;

    unsigned char data = 0x7;

    printf("Gen Mask 6 3 = %X\n", GEN_MASK(6,3));

    printf("base & ~(mask) = %X\n", base & ~(GEN_MASK(6,3)));

    printf("After Calculator : %X\n", SETBIT(base, 6, 3, data));

    unsigned char base2 = 0xFF;

    printf("base 2 set bit 5 to '0' : %X\n", SETBIT(base2, 4, 1, 0));


    return 0;
}
