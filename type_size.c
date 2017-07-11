#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test {
    int *pint;
    char *pchar;
};


int main()
{
    printf("hello world!\n");

    struct test my_str;

    printf("first my_str size = %d\n", sizeof(my_str));

    my_str.pint = (int *)malloc(sizeof(int));
    my_str.pchar = (char *)malloc(sizeof(char) * 10);

    printf("After my_str size = %d\n", sizeof(my_str));

    printf("sizeof int = %d\n", sizeof(int));
    printf("sizeof *int = %d\n", sizeof(int *));

    int *a = (int *)malloc(sizeof(int));

    *a = 100;

    printf("sizeof int point = %d\n", sizeof(a));
    printf("sizeof *int = %d\n", sizeof(*a));

    printf("Sizeof (char *) = %d\n", sizeof(char *));

    return 0;
}
