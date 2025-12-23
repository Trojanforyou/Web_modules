
#include "tcp_client.h"

bool fill_info(struct sockaddr_in *info)
{
    info->sin_family = AF_INET;
    info->sin_port = htons(3000);
    return(true);
}
bool    connection_to_server(int n, int fd, struct sockaddr_in *info)
{
    n = connect(fd, (struct sockaddr *)info, sizeof(struct sockaddr_in));
    if (n == -1)
    {
        perror("FAIL");
        exit(EXIT_FAILURE);
    }
}
bool    sendin_mesage(ssize_t message, int fd, char *buf)
{
    ssize_t sending = send(fd, buf, strlen(buf), 0);
    message = recv(fd, buf,sizeof(buf), 0);
    if (sending > 0)
    {
        fwrite(buf,1, message, stdout);
    }
    close (fd);
}
int main(int ac, char **av)
{
    int fd;
    int connection;
    char   buf[1024] = "hello";
    struct sockaddr_in info;
    int addr;
    int msg;

    if (ac != 2)
        return(-1);
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
        return(printf("here\n"), -1);
    fill_info(&info);
    addr = inet_pton(AF_INET, av[1], &info.sin_addr);
    if (addr == -1)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }
    connection_to_server(connection, fd, &info);
    sendin_mesage(msg, fd, buf);
}

    // ssize_t sent = send(fd, buf, strlen(buf), 0);
    // printf("Sent %zd bytes: %s\n", sent, buf);
    // ssize_t n = recv(fd, buf, sizeof(buf), 0);
    // if (n > 0) {
    //     printf("Received %zd bytes: ", n);
    //     fwrite(buf, 1, n, stdout);
    //     printf("\n");