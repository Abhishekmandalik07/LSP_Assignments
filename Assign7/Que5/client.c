#include"sharedfile.h"

int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        printf("Usage : Name_Of_Executable File_Name\n");
        return -1;
    }
    void *ptr = NULL;
    void(*fptr)(int);
    int fd =0;

    fd = open(argv[1],O_RDONLY);

    DisplayInfo(fd);

    return 0;

}