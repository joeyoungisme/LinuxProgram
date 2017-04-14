#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <pthread.h>
#include "thread.h"

void *my_thread(void *arg)
{
    printf("thread function runing...\nArgument : %s\n", (char *)arg);

    sleep(3);

    pthread_exit("Thank you for the CPU time");
}


int main(int argc, char *argv[])
{
    char message[] = "Hello I am Joeyoung";
    pthread_t test;
    void *thread_result;

    int rc = pthread_create(&test, NULL, my_thread, (void *)message);
    if (rc != 0) {
        perror("Thread create failed");
        exit(EXIT_FAILURE);
    }

    printf("Used Join waiting for thread to finish...\n");
    rc = pthread_join(test, &thread_result);
    if (rc != 0) {
        perror("Thread Join Failed");
        exit(EXIT_FAILURE);
    }

    printf("Thread Joined,  it returned %s\n", (char *)thread_result);

    exit(EXIT_SUCCESS);
}
