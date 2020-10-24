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
        for (int i = 0; i < 3; i++)
        {
            write(p[1], "" + i, 1);
        }
        close(p[1]);
    }
    else
    {
        int c[3];
        for (int i = 0; i < 3; i++)
        {
            read(p[0], &c, 1);
        }
        close(p[0]);
        for (int i = 0; i < 3; i++)
        {
            printf("%d ", c[i]);
        }
    }
    exit(0);
}