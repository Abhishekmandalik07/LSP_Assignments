#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<fcntl.h>

int main()
{

   int fd1=0,fd2=0;
    char Buffer[512];
    int iCnt=0,iRet=0,i=0;
    char str[60];

    fd1 = open("Hello.txt",O_RDONLY);

    while ((iRet = read(fd1,Buffer,sizeof(Buffer)))!=0)
    {
        for ( i = 0; i < iRet; i++)
        {
            if((Buffer[i]>='A') && Buffer[i]<='Z')
            {
                iCnt++;
            }
        }
        
    }

    sprintf(str, "Count of Capital letters from file Demo.txt is :  %d\n", iCnt);

    fd2=open("Count.txt",O_WRONLY | O_APPEND);

    write(fd2,str,60);

    close(fd1);
    close(fd2);
   
    return 0;
}