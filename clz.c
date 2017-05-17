#include<unistd.h>
#include<stdio.h>
#include<stdio.h>
#include<time.h>


int my_clz(unsigned int x) {
    int count = 32;
    for(; x != 0; x >>= 1) count--;
    return count;
}

int my_clz2(unsigned int x)
{
    if(x) return my_clz2(x >> 1)+1;
    else return 1;
}

int clz(unsigned int x) {
    int n = 32, c = 16;

    do {
        unsigned int y = x >> c;
        if(y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    }while(c);

    return (n - x);
}

int main(int argc, char *argv[])
{
    unsigned int x = 65536;

    //int y = USED_MACRO(x, 32);

    //printf("y = %d\n", y);


    clock_t clz_start = clock();
    printf("%d = %d\n", x, clz(x));
    clock_t clz_end = clock();
    double time_spent = (double) (clz_end - clz_start) / CLOCKS_PER_SEC;
    printf("clz run time : %f\n", time_spent);

    clz_start = clock();
    printf("%d = %d\n", x, my_clz(x));
    clz_end = clock();
    time_spent = (double) (clz_end - clz_start) / CLOCKS_PER_SEC;
    printf("my clz run time : %f\n", time_spent);

    clz_start = clock();
    printf("%d = %d\n", x, 32 - my_clz2(x));
    clz_end = clock();
    time_spent = (double) (clz_end - clz_start) / CLOCKS_PER_SEC;
    printf("my clz 2 run time : %f\n", time_spent);

    return 0;
}
