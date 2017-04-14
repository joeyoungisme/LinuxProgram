#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char *argv[])
{

    printf("Hello World\n");

    pid_t child;

    child = fork();

    switch(child) {
        case 0:
            printf("i am child!!\n");

            sleep(1);

            break;
        case -1:
            printf("Fork Error !! (%d)\n", child);

            break;
        default:
            printf("I am parenet process !!\n");
            printf("I am Waiting for child finish\n");

            int child_result = 0;
            pid_t finished_child = wait(&child_result);
            printf("Child (%d) Finished!!\n", (int)finished_child);

    }

    return 0;
}
