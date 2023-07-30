//////////////////////////////////////////////////////////////////////////////
//Write a Program which used to Display Environment of our Running Process.
//////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<sys/resource.h>

extern char **environ;

int main()
{

 
    printf("Parent Process is Running with PID %d\n",getpid());

    char **env = environ;

    printf("Envirionment of Running Process is : \n\n");

    for(;*env != NULL;env++)
    {
        printf("%s : \n",*env);
    }

   
    return 0;
}