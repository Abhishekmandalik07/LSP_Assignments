////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which creates 2 processes.
//Process 1 count number of captial characters from Demo.txt and 
//Process 2 count number of small characters from Hello.txt
// Both the processes writes writes its count in Count.txt
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