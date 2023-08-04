//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program which used to create 2 Threads,first thread print numbers from 1 to 500 & other thread print numbers from 500 to 1.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/wait.h>
#include<pthread.h>

void* ThreadProc1(void* ptr)
{
    printf("Inside Thread 1\n");
   
    int i=0;
    for ( i = 1; i <= 500; i++)
    {
        printf(" %d ",i);
    }
    pthread_exit(NULL);
}

void* ThreadProc2(void* ptr)
{
    printf("Inside Thread 2\n");
    int i=0;
    for ( i = 500; i >= 1; i--)
    {
        printf(" %d ",i);
    }
    pthread_exit(NULL);
}
int main()
{

    pthread_t TID1,TID2;
    int ret1=0,ret2=0;

    ret1=pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if(ret1!=0)
    {
        printf("Thread is not created...");
    }

    printf("Thread1 created Successfully with id : %ld\n",TID1);



    ret2=pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if(ret2!=0)
    {
        printf("Thread is not created...");
    }

    printf("Thread2 created Successfully with id : %ld\n",TID2);


    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    return 0;
}