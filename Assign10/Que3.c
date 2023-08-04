/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program which creates single thread and we have to pass parameter to that thread from main Thread
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/wait.h>
#include<pthread.h>

void* ThreadProc(void* ptr)
{
    int No = (int*)ptr;
    printf("Inside thread 1 the value of No is %ld\n",No);
    No = No+4;

    pthread_exit(No);
}


int main()
{

    pthread_t TID;
    int ret=0;
    int No=51;
    int Result=0;

    ret=pthread_create(&TID,NULL,ThreadProc,(int*)No);
    if(ret!=0)
    {
        printf("Thread is not created...");
    }

    printf("Thread1 created Successfully with id : %ld\n",TID);

    pthread_join(TID,&Result);
    printf("Result is : %d\n",Result);

    return 0;
}