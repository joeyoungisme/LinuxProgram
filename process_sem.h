#ifndef PROCESS_SEM_H
#define PROCESS_SEM_H

#include<sys/types.h>
#include<sys/sem.h>

#define JOE_SEM_KEY      1016


union sem_init {
    int value;
    struct semid_ds *buf;
    unsigned short *array;
};




#endif
