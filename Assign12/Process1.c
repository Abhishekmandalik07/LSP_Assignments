#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include<sys/shm.h>

int main()
{
    int shmid=0;
    int Key=4567;
    int shmsize = 100;
    char *ptr = NULL;
    char Arr[] = "THE LINUX PROGRAMMING INTERFACE ";
    char i='\0';

    shmid = shmget(Key,shmsize,IPC_CREAT | 0666);

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared Memory is Attached Successfully...\n");
    }

    for (i = 'a'; i <='z'; i++)
    {
        *ptr = i;
        ptr++;
    }
    *ptr = '\0';
    
    
    return 0;
}