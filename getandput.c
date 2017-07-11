#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define BUFFERSIZE              25

int main(int argc, char *argv[])
{
    char buffer[BUFFERSIZE];
    int buflen = sizeof(buffer);

    /*
    FILE *readfd = fopen("/home/joeyoung/copyfile.tar", "rb");
    FILE *writefd = fopen("/home/joeyoung/writefile.tar", "w+b");
    */


    /*
    FILE *readfd = fopen("./readfile.txt", "rb");
    FILE *writefd = fopen("./writefile.txt", "w+b");
    */
    
    FILE *readfd = fopen("./terminatingfile.txt", "r");
    FILE *writefd = fopen("./writefile.txt", "w+b");

    while(fgets(buffer, buflen, readfd) != NULL) {
        printf("%s", buffer);
        fputs(buffer, writefd);
    }

    fclose(readfd);
    fclose(writefd);
}
