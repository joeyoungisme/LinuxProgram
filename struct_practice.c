#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct joe_struct {
    struct joe_struct *prev, *next;
    int data;
}__attribute__((packed));

#define list_entry(pos, head)      \
    for(pos = (head)->next; pos != (head); pos = pos->next)

int main(int argc, char *argv[])
{
    struct joe_struct ooo = (struct joe_struct) {
        .prev = NULL,
        .next = NULL,
        .data = 999
    };

    printf("test struct data = %d\n", ooo.data);

    struct joe_struct test = {&test, &test, 100};
    struct joe_struct head = {&head, &head, 100};

//    for(int index = 0, struct joe_struct *pindex = &head; index < 10; ++index, pindex = pindex->next) {
    struct joe_struct *pindex = &head;
    for(int index = 0; index < 10; ++index, pindex = pindex->next) {
        pindex->next = (struct joe_struct *)malloc(sizeof(struct joe_struct));
        head.prev = pindex->next;
        
        pindex->next->next = &head;
        pindex->next->prev = pindex;
        pindex->next->data = pindex->data - 1;

    }

    struct joe_struct *pos;
    list_entry(pos, &head) {
        printf("pos = %X\n", pos);
        printf("pos data = %d\n", pos->data);
    }
        
/*
    printf("test(char + unsigned long) address = %X\n", (char *)&test+(unsigned long)16);
    printf("test(char + unsigned int) address = %X\n", (char *)&test+(unsigned int)16);
    printf("test(struct + struct) address = %X\n", (int *)&test+(unsigned int)4);
    printf("&test address = %X\n", &test);
    printf("(char *)&test address = %X\n", (char *)&test);
    printf("(struct joe_struct *)&test address = %X\n", (struct joe_struct  *)&test);

    printf("print lu : %lu\n", (unsigned long)88888888888888888888888);
    printf("print d : %d\n", (unsigned int)88888888888888888888888);

    printf("prev = %X, next = %X, data = %X\n", &test.prev, &test.next, &test.data);

    printf("Data Address Calculation : %d\n", &((struct joe_struct *)0)->data);

    //printf("address = %X\n", ((&test)+(&((struct joe_struct *)0)->data)));

    //printf("data = %d\n", *(int *)(&test - (&((struct joe_struct *)0)->data)));
*/

    return 0;
}
