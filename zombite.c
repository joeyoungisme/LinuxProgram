#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <signal.h>

unsigned char close_flag = 0;

void set_flag(int sig)
{
    close_flag = 1;
}

void seg_fault(int sig)
{
    *(&close_flag + 999999999) = 1;
}


int main(int argc, char *argv[])
{
    printf("Zombite Test Start !!\n");

    pid_t child_pid = fork();

    switch(child_pid) {
        case 0:
            printf("I am Child Waing Signal to Close!!\n");

            struct sigaction csig;

            csig.sa_handler = set_flag;
            sigemptyset(&csig.sa_mask);
            csig.sa_flags = 0;

            sigaction(SIGINT, &csig, 0);

            while(1) {
                pause();
                if(close_flag != 0) {
                    printf("Child : Bye!!\n");
                    exit(0);
                }
            }

            break;

        case -1:
            printf("fork failure...\n");
            break;

        default:

            printf("I am Parent Waing Signal to Close!!\n");

            struct sigaction psig;
            struct sigaction oldsig;

            psig.sa_handler = seg_fault;
            sigemptyset(&psig.sa_mask);
            psig.sa_flags = 0;

            sigaction(SIGINT, &psig, &oldsig);

            while(1) {
                pause();
                if(close_flag != 0) {
                    printf("Parent : Bye!!\n");

                    exit(0);
                }
            }
    }
}



