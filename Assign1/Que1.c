////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name from user and open that file.
///////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{

    int fd = 0;

    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File");
        return -1;
    }


    fd = open(argv[1],O_RDONLY);
    if(fd!=-1)
    {
        printf("File is Opened Successfully..\n");
    }
    else
    {
        printf("Unable to open file\n");
    }
    

    return 0;
}