#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int args, char *argv[])
{
    int p[2];
    if (pipe(p) < 0)
    {
        printf("pipe() failed\n");
        exit(1);
    }
    //子进程
    if (fork() == 0)
    {
        printf("%d: received ping\n", getpid());
        write(p[1], "pong", 4);
        close(p[1]);
    }
    else
    {
        char c[4];
        read(p[0], &c, 4);
        close(p[0]);
        printf("%d: received %s\n", getpid(), c);
    }
    exit(0);
}