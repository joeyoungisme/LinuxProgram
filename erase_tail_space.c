#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>

char help_message[] =
    "Usage : %s <path>\n";

void call_help(char *name)
{
    printf(help_message, name);
}

char *find_string_tail(char *string)
{
    char *tail = strchr(string, '\0') - 1;

    for(; (*tail == '\n') || (*tail == ' '); --tail);

    return tail;
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        call_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    struct dirent **dir_list;

    int node_count = scandir(argv[1], &dir_list, NULL, alphasort);
    if(node_count < 0) {
        fprintf(stderr, "scandir failed %d\n", node_count);
        exit(EXIT_FAILURE);
    }

    int erase_file_count = 0;

    while(node_count--) {
        if(dir_list[node_count]->d_type == DT_REG) {

            char filename[256] = "";
            snprintf(filename, 256, "%s/%s", argv[1], dir_list[node_count]->d_name);
            FILE *fd = fopen(filename, "r");
            if(!fd) {
                fprintf(stderr, "Open Original File Failed!\n");
                exit(EXIT_FAILURE);
            }

            char tempname[256] = "";
            snprintf(tempname, 256, "%s/%s", argv[1], ".temp");
            FILE *wfd = fopen(tempname, "w");
            if(!wfd) {
                fprintf(stderr, "Open Temp File Failed!\n");
                exit(EXIT_FAILURE);
            }

            printf("%s\n", filename);

            char buffer[1024];
            int line_count = 0;
            unsigned char edited = 0;
            while(NULL != fgets(buffer, 1024, fd)) {
                line_count++;

                char *tail = strchr(buffer, '\0') - 1;

                if(((*tail == '\n') && (*(tail - 1) == ' ')) || (*tail == ' ')) {
                    printf("[%d] : %s", line_count, buffer);
                    tail = find_string_tail(buffer);
                    snprintf(tail + 1, 2, "\n");
                    edited = 1;
                }

                fputs(buffer, wfd);
            }

            fclose(fd);
            fclose(wfd);

            if(rename(tempname, filename) != 0) {
                fprintf(stderr, "rename failed !\n");
                exit(EXIT_FAILURE);
            }
            if(edited)
                erase_file_count++;
        }
    }

    printf("Total Edited File : %d\n", erase_file_count);
}

