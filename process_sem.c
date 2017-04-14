#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/sem.h>
//#include<semun.h>

#include"process_sem.h"

static int sem_id;


static int set_semvalue(void) 
{
    union sem_init new_sem;

    new_sem.value = 0;

    if(semctl(sem_id, 0, SETVAL, new_sem) == -1) return 1;

    return 0;
}

static void del_semvalue(void)
{
    union sem_init del_sem;

    if(semctl(sem_id, 0, IPC_RMID, del_sem) == -1)
        fprintf(stderr, "Failed to delete semaphore\n");

}

static int semaphore_p(void)
{
    struct sembuf sem_b;

    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = 0;

    if(semop(sem_id, &sem_b, 1) == -1) {
        printf("Semaphore P Error !\n");
        fprintf(stderr, "semaphore_v failed \n");
        return 1;
    }
    
    return 0;
}

static int semaphore_v(void)
{
    struct sembuf sem_b;

    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = 0;

    if(semop(sem_id, &sem_b, 1) == -1) {
        printf("Semaphore V Error !\n");
        fprintf(stderr, "semaphore_p failed\n");
        return 1;
    }

    return 0;
}


int main(int argc, char *argv[])
{

    sem_id = semget(JOE_SEM_KEY, 1, 0777 | IPC_CREAT);
    
    if(argc == 2) {
        if(set_semvalue()) {
            fprintf(stderr, "Failed to initialize semaphore\n");
            exit(EXIT_FAILURE);
        }
        printf("Semaphore Initial Success : 0\n");

        sleep(60);
        del_semvalue();

        exit(EXIT_SUCCESS);
    }

    if(argc > 2) {
        printf("this process used to semaphore V() only\n");

        semaphore_v();

        exit(EXIT_SUCCESS);
    }

    printf("I am waiting process ... %d\n", getpid());
    if(semaphore_p()) exit(EXIT_FAILURE);
    printf("My PID : %d, Bye!!\n", getpid());

    exit(EXIT_SUCCESS);
}
