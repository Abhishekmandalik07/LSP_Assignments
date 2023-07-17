//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept two file names from user and copy the contents of an existing file into newly created file.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[])
{

    int fd1=0,fd2=0;
    int Ret = 0;
    char Buffer[BLOCKSIZE];


    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_Existing_File Name_Of_New_File");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1)
    {
        printf("Unable to open File1");
        return -1;

    }
    fd2 = creat(argv[2],0777);
    if(fd2 ==-1)
    {
        printf("Unable to create File2");
        close(fd1);
        return -1;
    }

    fd2 = open(argv[2],O_WRONLY);
    if(fd2 ==-1)
    {
        printf("Unable to open File2");
        close(fd1);
        close(fd2);
        return -1;
    }

    while ((Ret = read(fd1,Buffer,sizeof(Buffer))) !=0)
    {
        write(fd2,Buffer,Ret);
    }
    
    close(fd1);
    close(fd2);
    return 0;
}