///////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept directory name from user and delete all empty files from that directoty.
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char* argv[])
{

    DIR *dp = NULL;
    char name[20];
    struct dirent *entry = NULL;
    struct stat sobj;
    char fname[20];

    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_Directory \n");
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

        if(sobj.st_size == 0)
        {
            remove(name);
        }
    }
    
    closedir(dp);
    
    return 0;
}