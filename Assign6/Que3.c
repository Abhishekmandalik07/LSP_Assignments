//////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program which Accept directory name and file  name fromm user and create file in that directory.
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>


int main(int argc , char *argv[])
{
    int dp = 0;

    struct dirent *entry = NULL;
    struct stat sobj;
    char name[20];
    int iMax = 0;
    char namecopy[20];

    int fd=0;

    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_Directory Name_Of_File");
        return -1;
    }
    
    dp = chdir(argv[1]);
    if(dp == -1)
    {
        printf("Unable to change Directory\n");
        return -1;
    }

    fd = creat(argv[2],0777);
    if(fd==-1)
    {
        printf("Unable to create File in Directory\n");
        return -1;
    }
    
    return 0;
}