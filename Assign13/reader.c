#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


int main()
{
 
    int fd = 0;

    char *path = "/tmp/mypipe";

    char Buffer[1024];

    fd = open(path,O_RDONLY);
    
    read(fd,Buffer,sizeof(Buffer));

    printf("Data from pipe is : %s\n",Buffer);

    return 0;
}