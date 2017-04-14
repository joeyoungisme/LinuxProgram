#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void set_value(int sig);
void second_value(int sig);

typedef struct sigaction SIGACT;

int global_var = 0;

SIGACT global_sig = {
    .sa_handler = set_value,
    .sa_mask = 0,
    .sa_flags = 0
};

void set_value(int sig)
{
    global_var = 100;
}

void second_value(int sig)
{
    global_var = 200;
}


int main(int argc, char *argv[])
{
    sigaction(SIGINT, &global_sig, 0);


    pause();
    printf("Global Var = %d\n", global_var);

    printf("Reset Signal Action to Second\n");

    global_sig.sa_handler = second_value;
    SIGACT old_act;

    sigaction(SIGINT, &global_sig, &old_act);

    pause();
    printf("Global Var = %d\n", global_var);

    sigaction(SIGINT, &old_act, 0);
    pause();
    printf("Global Var = %d\n", global_var);

    exit(0);

}
