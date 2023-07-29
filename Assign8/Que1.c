#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{

    int Ret = 0;
    int cpid=0;
    int Exit_status=0;


    Ret = fork();

    if(Ret == 0)
    {
        printf("Child Process is Running with PID %d\n",getpid());
    }
    else
    {
        printf("Parent Process is Running with PID %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Parent terminateds\n");
    }
    return 0;
}