#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>
#include<string.h>
#include "mutex.h"

pthread_mutex_t mutex;


char main_thread_text[] =
    "Hello World i am Joeyoung Chen"
    "leven in taichung "
    "i am a boy ....";

char child_thread_text[] =
    "abcd efg hijk lmn opqr"
    "stuv wxyz 111 222 333"
    "1234 1234 5678";

char share_message[] =
    "aaa bbb ccc ddd eee fff ggg"
    "hhh iii jjj kkk lll mmm nnn"
    "ooo ppp qqq rrr sss ttt uuu"
    "vvv www xxx yyy zzz";

char *message = share_message;

int main(int argc, char *argv[])
{

    pthread_mutex_init(&mutex, NULL);

    pthread_t first;

    int res = pthread_create(&first, NULL, first_thread, NULL);
    if(res != 0) {
        printf("Pthread Create Failed !!\n");
        exit(EXIT_FAILURE);
    }

    while(message)
    {
        printf("------ Main Ready ------\n");
        res = pthread_mutex_lock(&mutex);
        if(res != 0) {
            printf("Main : mutex lock failed!\n");
            exit(EXIT_FAILURE);
        }
        printf("------ Main Lock -------\n");

        printf("Main : %s\n", strsep(&message, " "));

        res = pthread_mutex_unlock(&mutex);
        if(res != 0) {
            printf("Main : mutex unlock failed!\n");
            exit(EXIT_FAILURE);
        }
        printf("------ Main Unlock -------\n");
        sleep(1);
    }

    void *child_result;
    pthread_join(first, &child_result);

    printf("Child Joined !! Release Anything...\n");
    pthread_mutex_destroy(&mutex);


}

void *first_thread(void *arg)
{
    int res = 0;

    printf("Child Start Working !!!!!\n");

    while(message)
    {
        printf("------ Child Ready ------\n");
        res = pthread_mutex_lock(&mutex);
        if(res != 0) {
            printf("Child : mutex lock failed!\n");
            pthread_exit("mutex lock failed");
        }
        printf("------ Child Lock ------\n");

        printf("Child : %s\n", strsep(&message, " "));

        res = pthread_mutex_unlock(&mutex);
        if(res != 0) {
            printf("Child : mutex unlock failed!\n");
            pthread_exit("mutex unlock failed");
        }
        printf("------ Child Unlock ------\n");
        sleep(1);
    }

    pthread_exit("Child work complete");
}

