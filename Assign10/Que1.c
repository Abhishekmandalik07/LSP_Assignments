///////////////////////////////////////////////////////////////////////////////
//Write a program which used to create simple thread by using pthread library.
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/wait.h>
#include<pthread.h>

void* ThreadProc(void* ptr)
{
    printf("Inside Thread One...\n  ");
}

int main()
{

    pthread_t TID;
    int ret=0;

    ret=pthread_create(&TID,NULL,ThreadProc,NULL);
    if(ret!=0)
    {
        printf("Thread is not created...");
    }

    printf("Thread created Successfully with id : %ld\n",TID);

    pthread_join(TID,NULL);

    return 0;
}