#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/shm.h>

int main(int argc, char *argv[])
{
    void *share_point = NULL;
    MY_STRUCT *my_struct;

    int shmid;

    //Create share memeory space
    shmid = shmget(SHARE_KEY, sizeof(MY_STRUCT), 0770 | IPC_CREAT);
    if(shmid == -1) {
        fprintf(stderr, "Shmget Failed !!\n");
        exit(EXIT_FAILURE);
    }

    share_point = shmat(shmid, NULL, 0);
    if(share_point == (void *)-1) {
        fprinf(stderr, "Shmat Failed !!\n");
        exit(EXIT_FAILURE);
    }

    printf("Share Point : %X\n", share_point);

    //Share Memory Initial
    my_struct = (MY_STRUCT *)share_point;
    my_struct.lock = 0;
    memset(my_struct.buffer, 0, MEM_SIZE);

    printf("I am Producer , Try to Read Message Every 1 second Start..\n");

    while(1) {
        if(my_struct.lock == 0) {
            printf("Read Share Memory Message : \n");
            printf("%s\n", my_struct.buffer);

            if(strncmp(my_struct.buffer, "end", 3) == 3) {
                break;
            }
        }

        sleep(1);
    }

    int res = shmdt(share_point);
    if(res == -1) {
        fprintf(stderr, "SHM detach Failed!\n");
        exit(EXIT_FAILURE);
    }

    res = shmctl(shmid, IPC_RMID, 0);
    if(res == -1) {
        fprintf(stderr, "SHM Remove ID Failed!\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}




