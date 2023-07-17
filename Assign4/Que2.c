//////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which accept directory name from user and create new directory of that name.
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc , char *argv[])
{
    int fd;

    if(argc !=2)
    {
        printf("Invalid Number of Arguments");
        printf("Usage : Name_of_Executable Name_of_Directory");
        return -1;

    }

    fd = mkdir(argv[1],0777);
    
    if(fd == -1)
    {
        printf("Unable to create directory\n");
        return -1;
    }
    else
    {
        printf("Directory is created successfully with name: %s",argv[1]);
    }

    return 0;
}