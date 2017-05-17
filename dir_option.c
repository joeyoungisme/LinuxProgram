#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include<dirent.h>
#include<sys/stat.h>


int main(int argc ,char *argv[])
{
    char dir_path[] = "/home/joeyoung/";

    DIR *mydir = opendir(dir_path);

    if(!mydir) {
        printf("open dir failed !\n");
        exit(EXIT_FAILURE);
    }

    system("clear");
    printf("ls implemented myself, used opendir & readdir\n");
    sleep(3);

    struct dirent *ptr;
    while((ptr = readdir(mydir)) != NULL) {

        struct stat currstat;
        char new_path[256];
        snprintf(new_path, 256, "%s/%s", dir_path, ptr->d_name);

        if(stat(new_path, &currstat)) {
            fprintf(stderr, "stat failed!\n");
            break;
        }

        if(S_ISDIR(currstat.st_mode)) {
            printf("Directory : %s\n", ptr->d_name);
        }
        else if(S_ISREG(currstat.st_mode)) {
            printf("File : %s\n", ptr->d_name);
        }
        else
            printf("Other : %s\n", ptr->d_name);

    }

    closedir(mydir);

    sleep(3);
    system("clear");
    printf("ls implemented myself, used scandir .... \n");


    struct dirent **dir_list;

    int count = scandir(dir_path, &dir_list, NULL, alphasort);
    if(count < 0) {
        fprintf(stderr, "scandir failed !\n");
        exit(EXIT_FAILURE);
    }

    printf("DT_REG : %X\n", DT_REG);
    printf("DT_DIR : %X\n", DT_DIR);
    while(count--) {
        switch(dir_list[count]->d_type) {
        case DT_REG :
            printf("File -- ");
            break;
        case DT_DIR :
            printf("Dir  -- ");
            break;
        default :
            printf("Oth  -- ");
        }

        printf("%s\n", dir_list[count]->d_name);

        free(dir_list[count]);
    }
    free(dir_list);

    exit(EXIT_SUCCESS);
}
