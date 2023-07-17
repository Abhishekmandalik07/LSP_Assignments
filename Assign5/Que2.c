//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which Accept file name from user which contains information of employee, we have to read all contents of that file.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#pragma pack(1)

struct EmployeeInfo
{
    char Ename[20];
    int EID;
    int Esalary;
    int age;
};

int main(int argc , char *argv[])
{

    struct EmployeeInfo eobj;
    int fd = 0;
    char Fname[20];

    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File");
        return -1;
    }

    strcpy(eobj.Ename,"Ram");
    eobj.EID= 21;
    eobj.Esalary = 50000;
    eobj.age = 30;


    fd = creat(argv[1],0777);

    //write(1,&eobj,sizeof(eobj));
    read(fd,&eobj,sizeof(eobj));

    printf("Name is  : %s \n",eobj.Ename);
    printf("ID : %d \n",eobj.EID);
    printf("Salary : %d \n",eobj.Esalary);
    printf("Age : %d \n",eobj.age);

    close(fd);

    return 0;

}