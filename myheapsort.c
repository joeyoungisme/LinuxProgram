#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DIM(x)                              (sizeof(x)/sizeof(x[0]))

//Heapify Used Macro
//#define GET_ADDR(base, elesize, num)        (base + (num * elesize))
#define MEDIUM_OFF(num, elesize)            ((num/2-1) * elesize)
#define LCHILD_OFF(num, elesize)            ((num*2-1) * elesize)
#define RCHILD_OFF(num, elesize)            ((num*2) * elesize)
#define NUM_OFF(num, elesize)               ((num-1) * elesize)

typedef enum {
    RIGHT_CHILD,
    LEFT_CHILD,
    UNKNOWN_CHILD
}BIG_CHILD;

//int data_arr[] = {45,20,33,17,6,99,128,43,66,72,84,13,69,75,36};
int data_arr[] = {1,2,3,4,5,6,7};
#define STR_LEN                             256
char str_arr[][STR_LEN] = {
    "abdcslfjg",
    "adkjfsadljhfasg",
    "ssdfww",
    "saf",
    "salfjslfghsljfgsdlfgjhslfgj",
    "asdfkasfgjslfg",
    "asdfjlasdlf",
    "sfss", 
    "zzzzzzzzzzzzzzzzzzzzz",
    "aaaaaaaaaaaaaaaaa"
};

/*
 * Implement Heap Sort 
 * Create Heap Tree First (Heapfiy) , Max Heap or Min Heap
 * Sort ! Switch Root and End Node, Then Heapfiy again.
*/

int chr_cmp(const void *arg1, const void *arg2)
{
    int len1 = strlen((char *)arg1);
    int len2 = strlen((char *)arg2);

    if(len1 == len2)
        return 0;
    if(len1 > len2)
        return 1;
    if(len1 < len2)
        return -1;

    return 0;
}

int int_cmp(const void *arg1, const void *arg2)
{
    int i1 = *(int *)arg1;
    int i2 = *(int *)arg2;

    if(i1 == i2)
        return 0;
    if(i1 > i2)
        return 1;
    if(i1 < i2)
        return -1;

    return 0;
}

void chr_swap(void *arg1, void *arg2, int size)
{
    char *temp = (char *)malloc(sizeof(char) * size);
    memset(temp, 0, size);

    strncpy(temp, arg1, size);
    strncpy(arg1, arg2, size);
    strncpy(arg2, temp, size);

    free(temp);
}

void int_swap(void *arg1, void *arg2, int size)
{
   int tmp = *(int *)arg1;
   *(int *)arg1 = *(int *)arg2;
   *(int *)arg2 = tmp;

   return;
}

void datashow(int *data, int len)
{
    for(int index = 0; index < len; ++index)
        printf("%d ", data[index]);

    printf("\n");
}


int my_heapify(void *base, size_t num, size_t ele_size, 
               int (*cmp_fun)(const void *, const void*),
               void (*swap_fun)(void *, void *, int))
{
    for(int index = num/2;
        index > 0;
        index -= 1)
    {
        int bigchild = 0;
        for(int sub_index = index; sub_index * 2 <= num; sub_index = bigchild) {
            //Cmp & Swap
            //if only left child or left child > right child
            //  bigchild = left
            //else 
            //  bigchild = right
            
            if((sub_index * 2 + 1 > num) || cmp_fun(base+LCHILD_OFF(sub_index, ele_size), base+RCHILD_OFF(sub_index, ele_size)) > 0)
                bigchild = sub_index * 2;
            else
                bigchild = sub_index * 2 + 1;
         
            if(cmp_fun(base+NUM_OFF(bigchild, ele_size), base+NUM_OFF(sub_index, ele_size)) > 0)
                swap_fun(base+NUM_OFF(bigchild, ele_size), base+NUM_OFF(sub_index, ele_size), ele_size);
            else
                break;
        }

    }
    
    return 0;
}

int my_sorting(void *base, size_t num, size_t ele_size, 
               int (*cmp_fun)(const void *, const void *),
               void (*swap_fun)(void *, void *, int))
{
    for(int index = num; index > 0; --index) {
        swap_fun(base+NUM_OFF(1, ele_size), base+NUM_OFF(index, ele_size), ele_size);
        my_heapify(base, index - 1, ele_size, cmp_fun, swap_fun);
    }

    return 0;
}


int data_arr_heap(void)
{

    datashow(data_arr, DIM(data_arr));

/*    
int my_heapify(void *base, size_t num, size_t ele_size, 
               int (*cmp_fun)(void *, void*),
               void (*swap_fun)(void *, void *, int))
*/
    int res = my_heapify((void *)data_arr, DIM(data_arr), sizeof(int),
                         int_cmp, int_swap);
    if(res == 0)
        printf("heapify success!\n");

    datashow(data_arr, DIM(data_arr));

    //sort
    res = my_sorting((void *)data_arr, DIM(data_arr), sizeof(int),
                     int_cmp, int_swap);
    /*
    printf("Sort Step : \n");
    for(int index = DIM(data_arr); index > 0; --index) {
        //swap
        int_swap((void *)&data_arr[0], (void *)&data_arr[index - 1], sizeof(int));

        my_heapify((void *)data_arr, index - 1, sizeof(int),
                   int_cmp, int_swap);

        datashow(data_arr, DIM(data_arr));
    }
    */

    printf("Sort Success!\n");

    datashow(data_arr, DIM(data_arr));

    return 0;
}


int str_arr_heap(void)
{
    for(int index = 0; index < DIM(str_arr); ++index)
        printf("(%d): %s\n", strlen(str_arr[index]), str_arr[index]);

    int res = my_heapify((void *)str_arr, DIM(str_arr), STR_LEN, chr_cmp, chr_swap);
    if(res == 0)
        printf("heapify success!\n");

    res = my_sorting((void *)str_arr, DIM(str_arr), STR_LEN, chr_cmp, chr_swap);


    for(int index = 0; index < DIM(str_arr); ++index)
        printf("(%d): %s\n", strlen(str_arr[index]), str_arr[index]);

    return 0;
}

int main(int argc, char *argv[])
{

    data_arr_heap();
    str_arr_heap();

    return 0;
}
