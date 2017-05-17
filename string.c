#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    char gloden_str[] = "Hello world, i am joeyoung";

    char *cpy_str = strndup(gloden_str, strlen(gloden_str));

    printf("Gloden String = %s\n", gloden_str);

    printf("Copy String = %s\n", cpy_str);

    printf("Copy String length = %d\n", strlen(cpy_str));

    free(cpy_str);

    char my_str[256];
    
    int res = snprintf(my_str, 256, "%s _ %s _ %s", "Hello", "world", "joeyoung");
    printf("snprintf res = %d\n", res);
    printf("my_str : %s\n", my_str);
    printf("my_str len : %d\n", strlen(my_str));

    char test[] = "hello world";

    char *position = strchr(test, 'o');

    snprintf(position, 2, "\n");

    printf("snprintf : %s\n", test);

    printf("test address : %X\n", test);

    printf("Search \\0 : %X\n", strchr(test, '\0'));

    return 0;
}

