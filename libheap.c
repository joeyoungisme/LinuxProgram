#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include "heapsort.h"


int data_arr[] = {1,2,3,4,5,6,7};

int my_cmp(const void *arg1, const void *arg2)
{
    int i1 = *(int *)arg1;
    int i2 = *(int *)arg2;

    if(i1 == i2)
        return 0;
    if(i1 > i2)
        return 1;

    return -1;
}

void my_swap(void *arg1, void *arg2, int size)
{
    int tmp = *(int *)arg1;

    *(int *)arg1 = *(int *)arg2;
    *(int *)arg2 = tmp;
}

int main(int argc, char *argv[])
{

    for(int index = 0; index < DIM(data_arr); ++index)
        printf("%d ", data_arr[index]);

    printf("\n");

    heapify((void *)data_arr, DIM(data_arr), sizeof(int), my_cmp, my_swap);

    heapsorting((void *)data_arr, DIM(data_arr), sizeof(int), my_cmp, my_swap);


    for(int index = 0; index < DIM(data_arr); ++index)
        printf("%d ", data_arr[index]);

    printf("\n");

    return 0;
}
