#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
    

    char prev[50], last[50];

    char test[100];


    while(1) {
        fgets(test, 100, stdin);

        int count = sscanf(test, "%s %s", test, last);

        printf("Count = %d, s1 = %s, s2 = %s\n", count, test, last);

        memset(test, 0, 100);
        memset(prev, 0, 50);
        memset(last, 0, 50);
    }

    return 0;
}
