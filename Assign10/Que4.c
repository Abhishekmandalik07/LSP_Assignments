////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program which creates single thread and it accept one value from user and return some value to the caller thread.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/wait.h>
#include<pthread.h>

void* ThreadProc(void* ptr)
{
    int No=0;
    printf("Please Enter a Number : \n");
    scanf("%d",&No);

    pthread_exit(No);
}


int main()
{

    pthread_t TID;
    int ret=0;
    int Result=0;

    ret=pthread_create(&TID,NULL,ThreadProc,NULL);
    if(ret!=0)
    {
        printf("Thread is not created...");
    }

    printf("Thread1 created Successfully with id : %ld\n",TID);

    pthread_join(TID,&Result);
    printf("Result is : %d\n",Result);

    return 0;
}