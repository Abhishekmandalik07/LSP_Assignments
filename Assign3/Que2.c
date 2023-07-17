//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept directory name and file name from user and check whether that file is present in that directory or not.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    char fname[20];

    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_Directory Name_Of_File\n");
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
        
        if((strcmp(entry->d_name,argv[2]))==0)
        {
            printf("%s file is present in %s Directory\n",argv[2],argv[1]);
            break;
        }
        
    }
    
    closedir(dp);
    
    return 0;
}