#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdbool.h>
#include<dlfcn.h>


int main(int argc,char* argv[])
{
    int *ptr = NULL;
    void(*fptr)(int,int);

    int fd1=0,fd2=0;

    if (argc!=3)
    {
        printf("Usage: Name_Of_Executable File_Name1 File_Name2\n");
        return -1;
    }
    

    ptr = dlopen("FileLibrary.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;

    }

    fptr = dlsym(ptr,"ComapareFile");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    fptr(fd1,fd2);

    return 0;
}