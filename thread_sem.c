#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <semaphore.h>

#include "sem.h"

sem_t my_sem;

unsigned char run_thread = 1;

int main(int argc, char *argv[])
{
    int res = 0;
    res = sem_init(&my_sem, 0, 0);
    if(res != 0) {
        printf("Semaphore init failed !\n");
        exit(EXIT_FAILURE);
    }

    pthread_t first;
    void *thread_result;
    char message[] = "i am message";

    res = pthread_create(&first, NULL, first_thread, (void *)message);
    if(res != 0) {
        printf("Pthread Create Failed !\n");
        exit(EXIT_FAILURE);
    }

    printf("if you press any key, thread print message!!\n");

    while(fgetc(stdin) != EOF) {
        sem_post(&my_sem);
    }

    //set run_thread to 0
    run_thread = 0;
    // Because Thread still wait sem_t +1 .... 
    sem_post(&my_sem);

    printf("Waiting Thread Close ...\n");
    res = pthread_join(first, &thread_result);
    if(res != 0) {
        printf("Pthread Join Failed !\n");
        exit(EXIT_FAILURE);
    }
    printf("Thread Joined : %s\n", (char *)thread_result);

    printf("Semaphore Destory ... \n");
    sem_destroy(&my_sem);
    exit(EXIT_SUCCESS);
}

void *first_thread(void *arg)
{
    while(run_thread) {
        sem_wait(&my_sem);
        printf((char *)arg);
    }

    pthread_exit("run thread flag is set!!");
}





    
