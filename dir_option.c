#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<dirent.h>
#include<sys/stat.h>

#include "heapsort.h"

#define FIRST_CHR(x)                ((char *)x)[0]

unsigned long space_head;
unsigned long space_tail;
void *data;
int total_elenum;


void name_swap(void *arg1, void *arg2, int size)
{
    char *temp = *(char **)arg1;

    *(char **)arg1 = *(char **)arg2;
    *(char **)arg2 = temp;
}

int name_cmp(const void *arg1, const void *arg2)
{
    char *s1 = *(char **)arg1;
    char *s2 = *(char **)arg2;

    //Compare First Charator
    if(FIRST_CHR(s1) == FIRST_CHR(s2)) {
        
        //Compare String Length
        if(strlen(s1) == strlen(s2))
            return 0;
        if(strlen(s1) > strlen(s2))
            return 1;
        if(strlen(s1) < strlen(s2))
            return -1;
    }
 
    if(FIRST_CHR(s1) > FIRST_CHR(s2))
        return 1;
 
    if(FIRST_CHR(s1) < FIRST_CHR(s2))
        return -1;

    return 0;
}


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

    int count = scandir(dir_path, &dir_list, NULL, NULL);
    if(count < 0) {
        fprintf(stderr, "scandir failed !\n");
        exit(EXIT_FAILURE);
    }


    int elenum = count;
    total_elenum = elenum;
    int total_space = (elenum * sizeof(char *) + elenum * sizeof(char) * NAME_MAX);
    void *base = malloc(total_space);

    data = base;

    //space_head = base;
    //space_tail = base + total_space;

    for(int index = 0; index < elenum; ++index) {
        *((char **)base + index) = (char *)((char **)base + elenum) + (index * NAME_MAX);
    }
    char **namelist = (char **)base;

    for(int index = elenum - 1; index >= 0; --index) {

        strncpy(namelist[index], dir_list[index]->d_name, strlen(dir_list[index]->d_name));
        //memcpy((void *)namelist[index], (void*)dir_list[index]->d_name, strlen(dir_list[index]->d_name));
        //strncpy(namelist[index], dir_list[index]->d_name, NAME_MAX);
        //snprintf(namelist[index], strlen(dir_list[index]->d_name)+1, "%s ", dir_list[index]->d_name);
        printf("Cpy : %s(%lu) -> %s\n", dir_list[index]->d_name, strlen(dir_list[index]->d_name), namelist[index]);

        free(dir_list[index]);
    }
    free(dir_list);

    printf("Cpy Free Success!\n");


    heapify((void *)namelist, elenum, sizeof(char *), name_cmp, name_swap);

    printf("============ After Heapify ===============\n");
    for(int index = 0; index < elenum; ++index)
        printf("%s\n", namelist[index]);
    
    heapsorting((void *)namelist, count, sizeof(char *), name_cmp, name_swap);

    printf("============ After Sorting ===============\n");
    for(int index = 0; index < elenum; ++index)
        printf("%s\n", namelist[index]);

    free(base);
    
    /*
    printf("list addr = %X\n", dir_list);

    printf("DNAME = %s\n", dir_list[0]->d_name);

    for(int i = count - 1; i >= 0; --i) {
        printf("Name : %s\n", dir_list[i]->d_name);
        free(dir_list[i]);
    }
    free(dir_list);
    */

    /*
    char *buffer = (char *)malloc(NAME_MAX * count);
    memset(buffer, 0, NAME_MAX * count);

    char *index = buffer;
    for(int i = count - 1; i >= 0; --i) {

        switch(dir_list[i]->d_type) {
        case DT_REG :
            snprintf(index, NAME_MAX, "File -- %s\n", dir_list[i]->d_name);
            break;
        case DT_DIR :
            snprintf(index, NAME_MAX, "Dir -- %s\n", dir_list[i]->d_name);
            break;
        default :
            snprintf(index, NAME_MAX, "Oth -- %s\n", dir_list[i]->d_name);
            break;
        }

        index = index + strlen(index);

    }

    //printf("%s", buffer);
    free(buffer);
    */

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
