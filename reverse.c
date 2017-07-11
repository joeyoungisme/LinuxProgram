#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define MYDEBUG

#undef DBPRINT
#ifdef MYDEBUG
    #define DBPRINT(fmt, args...)      printf(fmt, ## args)
#else
    #define DBPRINT(fmt, args...)
#endif


void reverse(char *pstr)
{
    int index, middle = strlen(pstr) / 2;
    char *p;
    
    for(index = strlen(pstr) - 1, p = pstr; index >= middle; --index, ++p)
    {
        DBPRINT("index = %d, *p = %c, pstr[index] = %c\n", index, *p, pstr[index]);
        char temp = pstr[index];
        DBPRINT("assign temp\n");
        pstr[index] = *p;
        DBPRINT("*p assign pstr[index]\n");
        *p = temp;
    }
}


int main()
{
    /*
    char message[256];
    if(!fgets(message, 256, stdin)) {
        fprintf(stderr, "fget error\n");
        return -1;
    }
    */

    char message[] = "abcdefg!!";

    DBPRINT("Message len = %d\n", strlen(message));

    reverse(message);

    printf("Input String reverse : %s\n", message);

    return 0;
}

