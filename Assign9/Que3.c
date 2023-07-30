///////////////////////////////////////////////////////
//Write a Program which used to prority of process
///////////////////////////////////////////////////////

#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<sys/resource.h>

int main()
{

    int Ret1=0;
    int cpid=0;
    int Exit_status=0;
    int prior1=0,prior2=0;

    Ret1 = fork();

    if(Ret1 == 0)
    {
        printf("Process1 is Running with PID %d\n",getpid());

        prior1 =getpriority(PRIO_PROCESS,0);
        printf("Priority of process1 is  : %d\n",prior1);

    }

    else
    {
        printf("Parent Process is Running with PID %d\n\n",getpid());
        cpid = wait(&Exit_status);
        printf("\n");

        prior2 =getpriority(PRIO_PROCESS,0);
        printf("Priority of parent process is  : %d\n",prior2);

        printf("Parent Terminates\n");
    }

   
    return 0;
}