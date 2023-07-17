///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept directory name from user and combine all contents of file from that directory into one file named as AllCombine
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>


#pragma pack(1)

struct FileInfo
{
    char FileName[20];
    int FileSize;
};


int main(int argc , char *argv[])
{
    int fd = 0;
    char DirName[20];
    char name[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct FileInfo fobj;
    
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

    fd = creat("AllCombine.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
        }
    }
    
    
    closedir(dp);
    return 0;
}