//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept two directory from names from user and move all files from source directory to destination Directory.
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
    struct dirent *entry = NULL;
    char sourcename[20];
    char destname[20];


    if(argc !=3)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_Source_Directory Name_Of_Destination_Directory\n");
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
        sprintf(sourcename,"%s/%s",argv[1],entry->d_name);
        sprintf(destname,"%s/%s",argv[2],entry->d_name);

        rename(sourcename,destname);

    }
    
    closedir(dp);
    
    return 0;
}