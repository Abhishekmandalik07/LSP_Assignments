#include"FileOp.h"

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  ComapareFile
//  Description :   Used to display Files are same or Not
//  Input :         Integer,Integer
//  Output :        -
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

void ComapareFile(int fd1,int fd2)
{
    char Buffer1[1024];
    char Buffer2[1024];

    struct stat obj1,obj2;

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Both size are Not same\n");
        return;
    }

    int Ret = 0;
    while ((Ret=read(fd1,Buffer1,sizeof(Buffer1)))!=0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));

        if((memcmp(Buffer1,Buffer2,Ret)!=0))
        {
            break;
        }
    }
    
    if(Ret == 0)
    {
        printf("Both files are same\n");
    }
    else
    {
        printf("Files are not same\n");
    }

}