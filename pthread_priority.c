#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

int main(int argc, char *argv[])
{
    pthread_t oth_thread;

    pthread_attr_t thread_attr;
    pthread_attr_init(&thread_attr);

    int priority_min = 0, priority_max = 0;
    struct sched_param sched_value;

    pthread_attr_setschedpolicy(&thread_attr, SCHED_OTHER);

    priority_min = sched_get_priority_min(SCHED_OTHER);
    priority_max = sched_get_priority_max(SCHED_OTHER);

    printf("Priority Max (%d) / Min (%d) \n", priority_max, priority_min);

}
