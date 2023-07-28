#include"sharedfile.h"

void DisplayInfo(int fd)
{
    struct stat obj;

    fstat(fd,&obj);

    printf("Information of File is as Follows : \n");
    printf("fd is :%d\n",fd);
    printf("Inode of file is : %ld\n",obj.st_ino);
    printf("size of file is : %ld\n",obj.st_size);
    printf("Number of links in file are : %ld\n",obj.st_nlink);
    printf("System Number of file is : %ld\n",obj.st_dev);
    printf("Number of blocks in file is : %ld\n",obj.st_blocks);

}