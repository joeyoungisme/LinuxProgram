#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


#define MAX_LENGTH      32

int main(int argc, char *argv[])
{

    char command[MAX_LENGTH] = "";
    int count = 0;

    do {
        //MAX_LENGTH = 32, fgets 31 char + '\n'
        count = strlen(fgets(command, MAX_LENGTH, stdin));
        printf("fgets(%d) : %s\n", count, command);

        //Remove Extra Characters
        if(!strchr(command, '\n'))
            while(fgetc(stdin) != '\n');

    }while(strncmp(command, "quit", 4) != 0);

    /*      This Method have a issue, segmentation fault
    do {
        printf("Command >> ");

        fscanf(stdin, "%32s", command);

        printf("Execute : %s\n", command);

    }while(strncmp(command, "quit", 4) != 0);

    */


    return 0;
}
