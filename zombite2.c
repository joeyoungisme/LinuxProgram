#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    char open_message[] = "Hello World";

    if(fork()) {
        printf("Parent : %s\n", open_message);

        while(1) {
            printf("Parent : Wait Child dead ....\n");

            sleep(2);
        }
    }
    else {
        printf("Child : %s\n", open_message);

        printf("Sleep 5 second to Die ... \n");

        sleep(5);

        exit(0);
    }

    return 0;
}
