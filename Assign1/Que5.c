////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name and number of bytes from user and read that number of bytes from file.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include <sys/stat.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{

    int fd = 0;
    char *Buffer = NULL;
    unsigned Ret = 0;

    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File No_Of_Bytes");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    Buffer = (char*)malloc(sizeof(atoi(argv[2])));

    Ret = read(fd,Buffer,atoi(argv[2]));
    
    write(1,Buffer,Ret);
    
    return 0;
}