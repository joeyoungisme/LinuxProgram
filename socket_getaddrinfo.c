#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

void show_addrinfo(struct addrinfo *point)
{

    printf("**************************\n");
    printf("Current Address : %X\n", point);
    printf("ai_flags : %d\nai_family : %d\nai_socktype : %d\nai_protocol : %d\n", point->ai_flags, point->ai_family, point->ai_socktype, point->ai_protocol);
    printf("socketlen_t : %d\nsockaddr(struct) point : %X\nai_cannoname : %s\nai_next point : %X\n", point->ai_addrlen, point->ai_addr, point->ai_canonname, point->ai_next);
    printf("**************************\n");
}


int main(int argc, char *argv[])
{
    struct addrinfo setting, *return_addr;

    int res = getaddrinfo(NULL, "8888", NULL, &return_addr);

    if(res != 0)
    {
        printf("getaddrinfo error !\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("getaddrinfo success!\n");

    for(struct addrinfo *temp = return_addr; temp!=NULL; temp=temp->ai_next)
        show_addrinfo(temp);

    exit(EXIT_SUCCESS);
}

