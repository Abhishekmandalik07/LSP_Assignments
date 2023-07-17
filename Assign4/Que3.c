////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which accept 2 file names from user and check whether contents of that two files are equal or not
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{

    int fd1 = 0,fd2 = 0;
    int Ret = 0;
    char Buffer1[1024];
    char Buffer2[1024];

    struct stat obj1,obj2;

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are different\n");
        return -1;
    }

    while ((Ret = read(fd1,Buffer1,sizeof(Buffer1)))!=0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));

        if(memcmp(Buffer1,Buffer2,Ret)!=0)
        {
            break;
        }
    }

    if(Ret == 0)
    {
        printf("Both files are Equal\n");
    }
    else
    {
        printf("Both Files are Different\n");
    }

    return 0;
}