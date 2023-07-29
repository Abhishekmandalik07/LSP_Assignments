///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program which create three level process hierarchy where process 1 creates process 2 and it internally creates process3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        execl("./ChildProcess1","NULL",NULL);
        printf("\n");
        printf("Child1 Process is Running with PID %d\n",getpid());
    }
    else
    {
        printf("Parent of Child1 Process is Running with PID %d\n",getpid());
        printf("\n");

        cpid = wait(&Exit_status);
        printf("\n");

        printf("Child1 having PID %d Terminates with exit Status %d\n",cpid,Exit_status);
        printf("Parent of child1 terminated\n");
    }
    return 0;
}