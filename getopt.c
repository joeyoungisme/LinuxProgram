#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char usage[] =
    "Usage : ./getopt [option]\n"
    " -a : Please Key Something ... \n"
    " -b : Please Key Something ... \n"
    " -c : Please Key Something ... \n"
    " -d : Please Key Something ... \n"
    " -e : Have Not Get Argument , Only option \n"
    " -f : Have Not Get Argument , Only option \n"
    " -g : Have Not Get Argument , Only option \n";

void call_help(void)
{
    fprintf(stderr, "%s", usage);
}

int main(int argc, char *argv[])
{
    int opt = 0;

    printf("Try to getopt()!!\n");

    if(argc < 2) call_help();

    while((opt = getopt(argc, argv, "a:b:c:d:efg")) != -1) {
        switch(opt) {
        case 'a':
            printf("Have -a\n");
            printf("Input Arg = %s\n", optarg);
            break;
        case 'b':
            printf("Have -b\n");
            printf("Input Arg = %s\n", optarg);
            break;
        case 'c':
            printf("Have -c\n");
            printf("Input Arg = %s\n", optarg);
            break;
        case 'd':
            printf("Have -d\n");
            printf("Input Arg = %s\n", optarg);
            break;
        case 'e':
            printf("Have -e\n");
            printf("Input Arg = %s\n", optarg);
            break;
        case 'f':
            printf("Have -f\n");
            printf("Input Arg = %s\n", optarg);
            break;
        case 'g':
            printf("Have -g\n");
            printf("Input Arg = %s\n", optarg);
            break;

        default:
            call_help();
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
