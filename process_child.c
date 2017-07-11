#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fd = fopen("./Test_File.txt", "a+");

    if(!fd) {
        printf("Open File Failed !\n");

        sleep(5);

        return -1;
    }
    
    pid_t parent = getpid();
    pid_t child = fork();

    if(child) {
        printf("Parent : My Pid = %d\n", (int)parent);
        char message[] = "hello world\n";
        int res = fwrite(message, sizeof(message), 1, fd);
        if(res <= 0)
            fprintf(stderr, "fwrite Error !!\n");

        fclose(fd);
    }
    //Child
    else {
        printf("I am child process!!\n");

        char ch_message[] = "i am joeyoung\n";
        printf("Waiting parent write ...\n");
        sleep(2);

        int ch_res = fwrite(ch_message, sizeof(ch_message), 1, fd);
        if(ch_res <= 0)
            fprintf(stderr, "fwrite Error in child!!\n");

        printf("Child : Write complete!\n");

        fclose(fd);
    }

    return 0;
}


   
