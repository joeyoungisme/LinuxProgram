#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{

    char writemessage[] = "hello world";

    FILE *fd = fopen("./tempfile.txt", "w+");
    if(!fd) {
        fprintf(stderr, "fopen failed!\n");
    }

    printf("Write Count : %d\n", fwrite(writemessage, strlen(writemessage), 1, fd));

    fseek(fd, strlen(writemessage) - 2, SEEK_SET);

    char insertmessage[] = "___omg___";

    fwrite(insertmessage, strlen(insertmessage), 1, fd);

    fclose(fd);
            

    return 0;
}
