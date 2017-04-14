#ifndef PROCESS_SHM_H
#define PROCESS_SHM_H

#define SHARE_KEY   1011
#define MEM_SIZE    2048

typedef struct {
    unsigned char lock;
    char buffer[MEM_SIZE];
}MY_STRUCT;

#endif
