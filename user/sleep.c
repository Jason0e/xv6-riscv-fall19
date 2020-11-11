
#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("error\n");
        exit();
    }
    sleep(atoi(argv[1]));
    printf("Sleep for %s\n",argv[1]);
    exit();

    // if(argc != 2)
    // {
    //     printf("error\n");
    // }
    // else 
    // {
    //     int time = atoi(argv[1]);
    //     sleep(time);
        
    // }
    // exit();
}