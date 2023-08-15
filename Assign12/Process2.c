
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


    shmid = shmget(Key,shmsize, 0666);

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared Memory is Attached Successfully...\n");
    }

    printf("Data received from shared memory is : ");
    
    while (*ptr !='\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    return 0;
}