#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int Ret=0;
    int cpid=0;
    int Exit_status;
    
    printf("In Child1 Process..\n\n");
    
    Ret = fork();
    
    if(Ret == 0)
    {
        printf("Child1 Process created another Child2 process with PID %d\n",getpid());
    }
    else
    {
        printf("(Parent of child2)Child1 process is Running with PID %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Child2 having PID %d Terminates with exit Status %d\n",cpid,Exit_status);
        printf("(Parent of child2)Child1 Terminated\n");
    }
    return 0;
}
