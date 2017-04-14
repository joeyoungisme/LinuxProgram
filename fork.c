#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Hello i am parent \n");

    pid_t mychild = fork();

    printf("Fork Complete!!\n");

    if(mychild)
    {
        int result_val = 0;
        pid_t child_pid = wait(&result_val);

        printf("Child is Back(%d)!! Return %d\n", child_pid, result_val);

    }
    else 
    {
        printf("I am Child!\n");

        sleep(1);

        exit(10);
    }
}
