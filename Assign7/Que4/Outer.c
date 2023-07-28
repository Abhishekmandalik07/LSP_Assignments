#include "Outer.h"

void Outer()
{
    void *ptr = NULL;

    int(*fptr)(int);

    int No=0,Result=0;

    ptr = dlopen("Inner.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return ;

    }

    fptr = dlsym(ptr,"Factorial");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return;
    }

    printf("Enter a Number to get Factorial:\n");
    scanf("%d",&No);

    Result = fptr(No);
    printf("Factotial of %d is %d \n",No,Result);



}