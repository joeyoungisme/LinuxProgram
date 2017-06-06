#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{

    int elenum = 10;
    int elesize = 100;

    int rows = elenum * sizeof(char *);
    int columns = elenum * elesize * sizeof(char);

    char **namelist = (char **)malloc(rows + columns);

    char *data;

    for(int index = 0, data=(char*)(namelist+elenum); index < elenum; ++index, data+=elesize)
        namelist[index] = data;


    printf("namelist addr = %X\n", namelist);
    for(int index = 0; index < elenum; ++index) {
        printf("namelist[%d] -> %X\n", index, namelist[index]);
    }

    return 0;
}
