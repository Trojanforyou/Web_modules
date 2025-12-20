#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int fd;
    int connection;
    char    buf[1024];
    struct sockaddr_in info;
    int addr;

    if (ac != 1)
        return(-1);
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
        return(printf("here\n"), -1);
    addr = inet_pton(AF_INET, av[1], &info.sin_addr);
    if (addr == 1)
    {
        printf("YAY\n");
    }
    if (addr == 0)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }
    else if (addr == -1)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }
    connect(fd, (struct sockaddr *)&info.sin_addr, sizeof(struct sockaddr_in));
    close (fd);

    
}