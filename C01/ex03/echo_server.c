#include "echo_server.h"

bool    fill_struct(int *server_fd, struct sockaddr_in *info)
{
    *server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == NULL)
    {
        perror("FAIL");
        exit(EXIT_FAILURE);
    }
    info->sin_family = AF_INET;
    info->sin_port = htons(2000);
    info->sin_addr.s_addr = INADDR_ANY;
}
bool    echo_respond(int reciever, int client_fd, char *buf)
{
    while ((reciever = recv(client_fd,buf, sizeof(buf), 0)) > 0)
    {
        write(1, buf, reciever);
        send(client_fd, buf, reciever, 0);
    }
    return(true);
}
int main(int ac, char **av)
{
    int server_fd;
    int client_fd;
    struct sockaddr_in info;
    struct sockaddr_in client;
    socklen_t   client_len;
    char    buf[1024];
    ssize_t reciever;

    fill_struct(&server_fd, &info);
    client_len = sizeof(client);
    bind(server_fd, (struct sockaddr *)&info, sizeof(struct sockaddr_in));
    listen(server_fd, 0);
    client_fd = accept(server_fd, (struct sockaddr *)&client, &client_len);
    if (client_fd == -1)
    {
        perror("FAIL");
        exit(EXIT_FAILURE);
    }
    echo_respond(reciever, client_fd, buf);
    close(client_fd);
    close(server_fd);
}   
