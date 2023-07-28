#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<dlfcn.h>


int main()
{

    void *ptr = NULL;

    void(*fptr)();

    int No=0,Result=0;

    ptr = dlopen("Outer.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;

    }

    fptr = dlsym(ptr,"Outer");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr();

    return 0;
}