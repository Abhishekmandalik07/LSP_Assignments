////////////////////////////////////////////////////////////////////////
//Write a Program which used to demonstrate concept of I/O redirection
////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>

int main(int argc , char* argv[])
{
    int iNo1 = 0,iNo2 = 0;
    int iAns = 0;

    scanf("%d",&iNo1);


    scanf("%d",&iNo2);

    iAns = iNo1+iNo2;

    printf("Addition is : %d\n",iAns);

    return 0;
}
//  ./FileSystem5 <Input.txt >Output.txt