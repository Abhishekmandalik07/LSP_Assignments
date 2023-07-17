/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept Directory name from user and print all file names and its types from that Directory.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char* argv[])
{

    DIR *dp = NULL;
    char name[20];
    struct dirent *entry = NULL;
    struct stat sobj;

    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the Directory\n");
        return -1;
    }

    

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("File name is : %s and It is a Regular File \n",name);
        }
        if(S_ISDIR(sobj.st_mode))
        {
            printf("File name is : %s and It is a Directory File \n",name);
        }
        if(S_ISBLK(sobj.st_mode))
        {
            printf("File name is : %s and It is a Symbolic link \n",name);
        }
    }
    

    closedir(dp);
    
    return 0;
}