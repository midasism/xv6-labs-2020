#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int args, char *argv[])
{
    if (args == 1)
    {
        printf("error：please enter sleep time.\n");
        exit(-1);
    }
    sleep(atoi(argv[1]) * 10);
    exit(0);
}