#include<stdio.h>
#include<stdlib.h>


int main()
{
    FILE *fd = fopen("./terminatingfile.txt", "w+");

    char message[] = "hello \0 world\n";

    for(int index = 0; index < 100; ++index)
        fwrite(message, sizeof(char), sizeof(message), fd);

    fclose(fd);
}
        
