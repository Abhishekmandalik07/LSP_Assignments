#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>

int main()
{
 
    int fd = 0;
    char arr[] = "Pipes can be used to pass data between related processes (the meaning of related will become clear later). FIFOs are a variation on the pipe concept. The important difference is that FIFOs can be used for communication between any processes.";
    
    char *path = "/tmp/mypipe";

    fd = mkfifo(path,0666);

    if(fd==-1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    fd = open(path,O_WRONLY);

    write(fd,arr,sizeof(arr));

    close(fd);

    printf("Data successfully written in pipe\n");


    return 0;
}
