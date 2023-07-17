//////////////////////////////////////////////////////////////////////////////////////////////////
//Write a Program which writes structure in File.Structure should contains information of student.
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#pragma pack(1)

struct StudentInfo
{
    char Sname[20];
    int Rollno;
    float Marks;
    int Age;
};

int main(int argc , char *argv[])
{

    struct StudentInfo sobj;
    int fd = 0;
    char Fname[20];

    if(argc !=2)
    {
        printf("Insufficient Number of Arguments..\n");
        printf("Usage : Name_of_Executable Name_Of_File");
        return -1;
    }

    strcpy(sobj.Sname,"Rahul");
    sobj.Rollno = 11;
    sobj.Marks = 89.99;
    sobj.Age = 25;


    
    fd = creat(argv[1],0777);

    write(fd,&sobj,sizeof(sobj));


    close(fd);

    return 0;

}