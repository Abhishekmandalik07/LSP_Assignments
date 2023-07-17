///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept Directory name from user and print all file names of such file having largest size.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    int iMax = 0;
    char fname[20];

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
        
        if(iMax < (sobj.st_size))
        {
            iMax = sobj.st_size;
            strcpy(fname,name);
        }
    }
    
    printf("Name of largest size is : %s with size :%d\n",fname,iMax);

    closedir(dp);
    
    return 0;
}