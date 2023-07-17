/////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name from user and write string in that file.
/////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char* argv[])
{

    int fd = 0;

    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File String");
        return -1;
    }

    fd = open(argv[1],O_RDWR | O_APPEND);

    if(fd==-1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    
    write(fd,argv[2],strlen(argv[2]));

    close(fd);
    
    return 0;
}