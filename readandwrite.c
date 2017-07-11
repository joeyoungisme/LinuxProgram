#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define BUFFSIZE                256

int main(int argc, char *argv[])
{
    /*
    FILE *readfd = fopen("./readfile.txt", "r");
    FILE *writefd = fopen("./writefile.txt", "w+");
    */

    FILE *readfd = fopen("/home/joeyoung/copyfile.tar", "r");
    FILE *writefd = fopen("/home/joeyoung/writefile.tar", "w+");

    char buffer[BUFFSIZE];
    while(1) {
        memset(buffer, 0, BUFFSIZE);

        int rc = fread((void*)buffer, sizeof(char), BUFFSIZE, readfd);
        int wc = fwrite((void*)buffer, sizeof(char), rc, writefd);

        if(rc == 0 || wc == 0)
            break;
    }

    fclose(readfd);
    fclose(writefd);
}
