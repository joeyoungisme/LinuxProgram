#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include<string.h>

#define FIRST_CHR(x)            x[0]


int main(int argc, char *argv[])
{
    char s1[256];
    char s2[256];

    while(1) {
        memset(s1, 0, 256);
        memset(s2, 0, 256);

        if(!fgets(s1, 256, stdin)) {
            fprintf(stderr, "fgets return null\n");
            break;
        }
        if(!strchr(s1, '\n'))
            while(fgetc(stdin) != '\n');

        if(!fgets(s2, 256, stdin)) {
            fprintf(stderr, "fgets return null\n");
            break;
        }
        if(!strchr(s1, '\n'))
            while(fgetc(stdin) != '\n');

        /* Compare Point Address
        if(s1 == s2)
            printf("equal\n");
        if(s1 > s2)
            printf("bigger\n");
        if(s1 < s2)
            printf("smaller\n");
        */
    
        if(FIRST_CHR(s1) == FIRST_CHR(s2))
            printf("equal!\n");
        if(FIRST_CHR(s1) > FIRST_CHR(s2))
            printf("Greater!\n");
        if(FIRST_CHR(s1) < FIRST_CHR(s2))
            printf("Smaller!\n");

        if(!strncmp(s1, "quit", 4) || !strncmp(s2, "quit", 4))
            break;
    }


    return 0;
}
