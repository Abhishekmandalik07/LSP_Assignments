//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Write a program which creates two processes as reader and writer and taht processes should communicate with each other using FIFO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>

int main()
{
    int Ret1=0,Ret2=0;
    int cpid=0,Exit_Status1=0,Exit_Status2=0;


    Ret1 = fork();

    if (Ret1 == 0)
    {
        printf("Writer Process is Running...\n");
        execl("./writer","NULL",NULL);   

        printf("Writer Process Terminated...\n");
        
    }

    Ret2 = fork();

    if (Ret2 == 0)
    {
        printf("Reader Process is Running...\n");
        execl("./reader","NULL",NULL);   

        printf("Reader Process Terminated...\n");
    }
    

    else
    {
        printf("Parent Process is Running...\n");
        wait(&Exit_Status1);
       
        printf("\n");
        printf("Parent Terminates...\n");
    }
    
    

    return 0;
}