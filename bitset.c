#include<stdio.h>
#include<stdlib.h>

#define SETBIT(x, p, v)         ((x & ~(1 << p)) | (v << p))

int main(int argc, char *argv[])
{
    unsigned char num = 0xFF;

    unsigned int inum = 0;

    fscanf(stdin, "%d", &inum);

    printf("inum = %d\n", inum);

    num = SETBIT(num, 5, 0); 

    printf("Set Bit 5 to 0 : %X\n", num);

    for(int index = 0; num>>index; ++index) {
        if((num >> index) & 0x01)
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    return 0;
}
