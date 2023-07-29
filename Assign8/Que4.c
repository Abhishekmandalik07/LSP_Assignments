////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program which creates three different processes internally as process2,process3,process4.
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int Ret1=0,Ret2=0;
    int cpid=0;
    int Exit_status=0;


    Ret1 = fork();

    if(Ret1 == 0)
    {
        execl("./Process1","NULL",NULL);
        printf("Process1 is Running with PID %d\n",getpid());
    }

    Ret2 = fork();

    if(Ret2 == 0)
    {
        execl("./Process2","NULL",NULL);
        printf("Process2 Process is Running with PID %d\n",getpid());
    }
    else
    {
        printf("Parent Process is Running with PID %d\n\n",getpid());
        cpid = wait(&Exit_status);
        printf("\n");
        printf("Parent Terminates\n");
    }

   
    return 0;
}