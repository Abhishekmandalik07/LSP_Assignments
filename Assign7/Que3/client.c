#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<dlfcn.h>


int main()
{

    void *ptr1 = NULL;
    void *ptr2 = NULL;

    bool(*fptr1)(int);
    bool(*fptr2)(int);

    bool bResult=false;
    int No=0;

    ptr1 = dlopen("NumberLib.so",RTLD_LAZY);

    if(ptr1 == NULL)
    {
        printf("Unable to load library\n");
        return -1;

    }

    fptr1 = dlsym(ptr1,"CheckPrime");
    if(fptr1 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    printf("Enter a Number : \n");
    scanf("%d",&No);

    bResult = fptr1(No);

    if(bResult == true)
    {
        printf("Given Number is Prime\n");
    }
    else
    {
        printf("Given Number not a Prime Number\n");
    }
    



    ptr2 = dlopen("NumberLib.so",RTLD_LAZY);

    if(ptr2 == NULL)
    {
        printf("Unable to load library\n");
        return -1;

    }

    fptr2 = dlsym(ptr2,"CheckPerfect");
    if(fptr2 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    printf("Enter a Number : \n");
    scanf("%d",&No);

    bResult = fptr2(No);

    if(bResult == true)
    {
        printf("Given Number is Perfect Number\n");
    }
    else
    {
        printf("Given Number not a Perfect Number\n");
    }

    return 0;
}