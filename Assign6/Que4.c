#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>


int main(int argc , char *argv[])
{

    DIR *dp = NULL;

    struct dirent *entry = NULL;
    struct stat sobj;
    char name[20];
    int iMax = 0;
    char namecopy[20];

    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File");
        return -1;
    }
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open Directory\n");
        return -1;
    }

    while ((entry = readdir(dp))!= NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > 100)
            {
                remove(name);
            }
        }
    }
    
    
    closedir(dp);
    return 0;
}