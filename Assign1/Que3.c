////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name and mode from user and that program check whether our 
//process can access that file in accepted mode or not
////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

    int fd = 0;
    int mode=0;
    int ret =0;


    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File Mode_of_File \n");
        return -1;
    }
    

    if ((ret = strcmp(argv[2],"Read")) == 0)
    {
        mode = R_OK;
    }
    
    else if ((ret = strcmp(argv[2],"Write")) == 0)
    {
        mode = W_OK;
    }
    else if ((ret = strcmp(argv[2],"Execute")) == 0)
    {
        mode = X_OK;
    }


    if ((access(argv[1],mode)) == 0)
    {
        printf("%s file access in %s mode\n",argv[1],argv[2]);
    }
    else
    {
        printf("Unable to access %s file in %s mode\n",argv[1],argv[2]);
    }
    
    
    return 0;
}