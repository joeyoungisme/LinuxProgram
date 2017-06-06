#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    char test99[] = "hello world";
    char test999[] = "joeyoung";
    char longmessage[] = "abcdefghijklmnopqrstuvwxyzasdflkasdf";

    
    strncpy(test99, longmessage, strlen(longmessage));
    strncpy(test999, longmessage, strlen(longmessage));


    printf("99 : %s, 999 : %s\n", test99, test999);

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

