#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *my_thread(void *arg)
{
    int res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    
    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    int index = 0;
    for(index = 0; index < 10; ++index)
    {
        printf("Thread is Running ... (%d)\n", index);

        sleep(1);
    }

    pthread_exit(NULL);
}
        

int main(int argc, char *argv[])
{
    pthread_t mythread;

    int res = pthread_create(&mythread, NULL, my_thread, NULL);

    sleep(3);

    pthread_cancel(mythread);

    sleep(3);

    pthread_join(mythread, NULL);

    exit(EXIT_SUCCESS);
}

