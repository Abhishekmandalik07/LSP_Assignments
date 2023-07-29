#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("Process1 is Running with PID %d\n",getpid());
    
    return 0;
}
