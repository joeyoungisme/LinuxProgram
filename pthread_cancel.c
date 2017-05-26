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

int thread_call_function(void)
{
    sleep(1);

    pthread_exit(NULL);
}

void *scend_thread(void *arg)
{
    printf("In Second Thread!!\n");

    thread_call_function();

    printf("second thread printf Before Exit!!\n");

    return NULL;
}



int main(int argc, char *argv[])
{
    pthread_t mythread;

    int res = pthread_create(&mythread, NULL, my_thread, NULL);

    sleep(3);

    pthread_cancel(mythread);

    sleep(3);

    pthread_join(mythread, NULL);

    pthread_t second_thread;

    res = pthread_create(&second_thread, NULL, scend_thread, NULL);

    pthread_join(second_thread, NULL);

    printf("Main Function Printf!\n");

    exit(EXIT_SUCCESS);
}

