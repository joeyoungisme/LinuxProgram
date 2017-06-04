#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<dirent.h>
#include<sys/stat.h>

struct name_list {
    char *name;
    struct name_list *next;
};


int main(int argc ,char *argv[])
{
    char dir_path[] = "/home/joeyoung/";

    DIR *mydir = opendir(dir_path);

    if(!mydir) {
        printf("open dir failed !\n");
        exit(EXIT_FAILURE);
    }

    /* 
    system("clear");
    printf("ls implemented myself, used opendir & readdir\n");

    printf("dir_operator %s ...\n", dir_path);
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
    */
    system("clear");
    printf("ls implemented myself, used scandir .... \n");

    printf("dir_operator %s ...\n", dir_path);

    struct dirent **dir_list;

    int count = scandir(dir_path, &dir_list, NULL, alphasort);
    if(count < 0) {
        fprintf(stderr, "scandir failed !\n");
        exit(EXIT_FAILURE);
    }

    char *buffer = (char *)malloc(256 * count);
    memset(buffer, 0, 256 * count);

    char *index = buffer;
    while(count--) {
        
        switch(dir_list[count]->d_type) {
        case DT_REG :
            snprintf(index, 256, "File -- %s\n", dir_list[count]->d_name);
            break;
        case DT_DIR :
            snprintf(index, 256, "Dir -- %s\n", dir_list[count]->d_name);
            break;
        default :
            snprintf(index, 256, "Oth -- %s\n", dir_list[count]->d_name);
            break;
        }

        index = index + strlen(index);

    }

    printf("%s", buffer);
    free(buffer);

    /* 
    struct name_list *list = NULL, *curr = NULL;
    char buffer[256];

    while(count--) {

        memset(buffer, 0, 256);

        switch(dir_list[count]->d_type) {
        case DT_REG :
            snprintf(buffer, 256, "File -- %s\n", dir_list[count]->d_name);
            break;
        case DT_DIR :
            snprintf(buffer, 256, "Dir -- %s\n", dir_list[count]->d_name);
            break;
        default :
            snprintf(buffer, 256, "Oth -- %s\n", dir_list[count]->d_name);
            break;
        }

        struct name_list *tmp = (struct name_list *)malloc(sizeof(struct name_list));
        tmp->name = strndup(buffer, 256);
        tmp->next = NULL;
        if(!list) {
            list = tmp;
            curr = tmp;
        }
        else {
            curr->next = tmp;
            curr = tmp;
        }

        free(dir_list[count]);
    }
    free(dir_list);

    struct name_list *search = list;

    //sort
    while(search->next != NULL) {
        if(strncmp(search->next->name, "Dir", 3) == 0) {
            struct name_lits *tmp = (search->next)->next;
            (search->next)->next = list;
            list = search->next;
            search->next = tmp;
        }
        else 
            search = search->next;
    }
            

    //Print & free
    struct name_list *index = list;
    while(index->next != NULL) {
        printf("%s", index->name);
        free(index->name);
        struct name_list *tmp = index->next;
        free(index);
        index = tmp;
    }
    */


    /*
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
    */

    exit(EXIT_SUCCESS);
}
