/////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name from user and print all information about the file.
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{

    int fd = 0;
    int mode=0;
    int ret =0;
    struct stat sobj;


    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File");
        return -1;
    }
    
    stat(argv[1],&sobj);
    printf("Name of the file is : %s\n",argv[1]);
    printf("Inode number of file is : %ld\n",sobj.st_ino);
    printf("Size of file in byte is : %ld\n",sobj.st_size);
    printf("UID od file is : %d\n",sobj.st_uid);
    printf("No. of blocks of file are : %ld\n",sobj.st_blocks);
    printf("Block size of file is : %ld\n",sobj.st_blksize);

    if(S_ISREG(sobj.st_mode))
    {
        printf("Its is regular file\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Its is Directory File\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Its a Symbolic link\n");
    }
    
    return 0;
}