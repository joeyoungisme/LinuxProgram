#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*

Memory alloc void space like below
__________________________________________________
| char ** | int ** | char * | int * | char | int |
| x 5     | x 5    | x 5    | x 5   | x 5  | x 5 |
--------------------------------------------------

Assign Value :
char **  -> char * -> char
int ** -> int * -> int

Note : Calculation Address to assign value

*/

char space[] = 
"__________________________________________________\n"
"| char ** | int ** | char * | int * | char | int |\n"
"| x 5     | x 5    | x 5    | x 5   | x 5  | x 5 |\n"
"--------------------------------------------------\n";

int main(int argc, char *argv[])
{
    printf("--------------------------------------\n");
    printf("sizeof char %lu, char * %lu, char ** %lu\n",
            sizeof(char), sizeof(char*), sizeof(char**));

    printf("sizeof int %lu, int * %lu, int ** %lu\n",
            sizeof(int), sizeof(int*), sizeof(int**));
    printf("--------------------------------------\n");

    int arr[3] = {1,2,3};
    int *pi = arr;
    void *vpi = arr;

    for(int i = 0; i < 3; ++i)
        printf("*(pi + i) = %d\n", *(pi+i));

    for(int i = 0; i < 3; ++i)
        printf("*((int*)vpi + i) = %d\n", *((int*)vpi+i));


    int chr_space = sizeof(char **) * 5 + sizeof(char *) * 5 + sizeof(char) * 5;
    int int_space = sizeof(int **) * 5 + sizeof(int *) * 5 + sizeof(int) * 5;

    void *base = malloc(chr_space + int_space);

    printf("%s", space);

    printf("Base Space : %X - %X\n", base, (char *)base + chr_space + int_space);
    printf("Char ** Space : %X - %X\n", base, (char **)base + 5);
    printf("int ** Space : %X - %X\n", ((char ***)base+5), (int **)((char ***)base+5) + 5);
    printf("Char * Space : %X - %X\n", (char**)((int***)((char ***)base+5)+5)+0, (char**)((int***)((char ***)base+5)+5)+5);
    printf("int * Space : %X - %X\n", (int**)((char**)((int***)((char ***)base+5)+5)+5)+0, (int**)((char**)((int***)((char ***)base+5)+5)+5)+5);


    //char point assign
    for(int index = 0; index < 5; index++) {
        //*(char**)(base + index) = base + (sizeof(char**) * 5) + (sizeof(int**) * 5) + (sizeof(char*) * index);

        //*(char**)(base + index) = ((char*)((int**)((char **)base + 5) + 5) + index);
        
        *((char***)base + index)= (char**)((int***)((char ***)base+5)+5)+index;

        //**((char ***)base + index) = (char*)((int**)((char**)((int***)((char ***)base+5)+5)+5)+5)+index;
        *((char **)base + index) = (char*)((int**)((char**)((int***)((char ***)base+5)+5)+5)+5)+index;

        **((char **)base + index) = 'a' + index;
    }


    for(int index = 0; index < 5; index++) 
        printf("**((char **)base + index) = %c [%X]\n", **(char **)base + index, &**(char **)base + index);

    //int point assign
    for(int index = 0; index < 5; ++index) {
        *((int ***)((char ***)base+5)+index) = (int **)((char **)((int ***)((char ***)base + 5)+5)+5)+index;
        //*((int ***)base +index) = (int **)((char **)((int ***)((char ***)base + 5)+5)+5)+index;

        *((int **)((char ***)base+5) +index) = (int*)((char *)((int **)((char **)((int ***)((char ***)base + 5)+5)+5)+5)+5)+index;

        **((int **)((char ***)base + 5) +index) = index;
    }

    for(int index = 0; index < 5; ++index)
        printf("**(int **)base+index = %d [%X]\n", **(int **)((char ***)base+5)+index, &**(int **)((char ***)base+5)+index);

    int aaaa = 100;
    int *paaaa = &aaaa;

    printf("&aaa = %X, paaa= %X, &(*paaaa) = %X\n", &aaaa, paaaa, &(*paaaa));


    free(base);

    return 0;
}

