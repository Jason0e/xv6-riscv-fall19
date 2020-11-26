#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcnt1.h"

#define MAXARG 10

int 
getcmd(char *buf, int nbuf)
{
    fprintf(2,"@ ");
    memset(buf, 0, nbuf);
    gets(buf, nbuf);
    if(buf[0] == 0)//EOF
        return -1;
    return 0;
}

void 
runcmd(struct cmd *cmd)
{
    int p[2];
    struct execcmd *ecmd;
    struct pipecmd *pcmd;
    struct redircmd *rcmd;
}

int
main(void)
{
    static char buf[100];
    int fd;

    while(getcmd(buf, sizeof(buf))>=0 )
    {
        if(fork() == 0)
        {
            char* argv[MAXARG];
            int argc = -1;

            setargs(buf, argv, &argv)
            execcmd(argv, argc);
        }
        wait(0);
    }
    exit(0);
}