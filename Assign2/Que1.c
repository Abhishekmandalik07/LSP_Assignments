//////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name from user and read whole file.
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[])
{

    int fd = 0;
    unsigned Ret =0;
    char Buffer[BLOCKSIZE];

    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd==-1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    while ((Ret = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        write(1,Buffer,Ret);
    }
    
    close(fd);
    
    return 0;
}
