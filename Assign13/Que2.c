////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program which creates child process and parent process will communicate with child process by sending signals
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void sighup();
void sigint();
void sigquit();


int main()
{

    int pid=0;

    pid = fork();

    if (pid==0)
    {
        signal(SIGHUP,sighup);
        signal(SIGINT,sigint);
        signal(SIGQUIT,sigquit);
        while (1)
        {}
        
    }

    else
    {
        printf("\nPARENT : sending SIGHUP\n\n");
        kill(pid,SIGHUP);
        sleep(1);

        printf("\nPARENT : sending SIGINT\n\n");
        kill(pid,SIGINT);
        sleep(1);

        printf("\nPARENT : sending SIGQUIT\n\n");
        kill(pid,SIGQUIT);
        sleep(1);
    }
    
    


    return 0;
}

void sighup()
{
    signal(SIGHUP,sighup);
    printf("CHILD:I have received a SIGHUP\n");
}

void sigint()
{
    signal(SIGINT,sigint);
    printf("CHILD:I have received a SIGINT\n");
}

void sigquit()
{
    printf("Parent process kill child\n");
    exit(0);
}