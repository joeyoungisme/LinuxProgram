#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>
#include <signal.h>
#include "detach_thread.h"

unsigned char Child_Kill = 0;

void signal_func(int sig)
{
    Child_Kill = 1;
}

int main(int argc, char *argv[])
{

    struct sigaction mysig;
    mysig.sa_handler = signal_func;
    sigemptyset(&mysig.sa_mask);
    mysig.sa_flags = 0;

    sigaction(SIGINT, &mysig, NULL);

    pthread_t de_thread;

    pthread_attr_t thread_attr;

    int res = pthread_attr_init(&thread_attr);
    if(res != 0) {
        printf("Pthread Attr Init Failed !\n");
        exit(EXIT_FAILURE);
    }

    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if(res != 0) {
        printf("Pthread Attr Set Detach Failed !\n");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&de_thread, &thread_attr, detach_thread, NULL);
    if(res != 0) {
        printf("Pthread Create Failed!\n");
        exit(EXIT_FAILURE);
    }

    res = pthread_attr_destroy(&thread_attr);
    if(res != 0) {
        printf("Pthread Attr Destroy Failed !\n");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        if(Child_Kill)
            printf("Ha Ha Child Killed!!\n");
        else
            printf("Waiting SIGINT to Kill Child....\n");
        sleep(2);
    }
}

void *detach_thread(void *arg)
{
    printf("Child Thread Start !\n");
    while(1) {
        if(Child_Kill) {
            pthread_exit(NULL);
        }
        
        sleep(1);
    }
}




