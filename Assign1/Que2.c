/////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name and mode from user and open that file in specified mode.  /
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[])
{

    int fd = 0;
    int mode=0;

    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File Mode_of_File \n");
        return -1;
    }
    
    if(strcmp(argv[2],"Read") ==0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") ==0)
    {
        mode = O_WRONLY;
    }


    fd = open(argv[1],mode);

    if(fd!=-1)
    {
        printf("File is Opened Successfully with fd : %d\n",fd);
    }
    else
    {
        printf("Unable to open file\n");
        return -1;
    }
    

    return 0;
}
