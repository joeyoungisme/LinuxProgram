#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>


int main(int argc, char *argv[])
{
    
    char path[256];

    if(argc == 1)
        snprintf(path, 256, ".");
    else
        snprintf(path, 256, "%s", argv[1]);

    struct dirent **dir_list;

    int count = scandir(path, &dir_list, NULL, alphasort);

    if(count < 0) {
        fprintf(stderr, "scandir failed %d\n", count);
        exit(EXIT_FAILURE);
    }

    while(count--) {
        switch(dir_list[count]->d_type) {
        case DT_DIR:
            printf("[d] ");
            break;
        case DT_REG:
            printf("[f] ");
            break;
        default:
            printf("[o] ");
        }

        printf("%s\n", dir_list[count]->d_name);

        free(dir_list[count]);
    }

    free(dir_list);

    exit(EXIT_SUCCESS);
}
    
