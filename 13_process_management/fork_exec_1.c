#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    
    printf("My PID = %d\n", getpid());

    pid = fork();
    if (pid < 0) {
       fprintf(stderr, "fork failed\n");
       return 1;
    }
    if (pid != 0) {  /* parent */
        printf("I'm the parent. My PID = %d\n", getpid());
        while(1);
    }
    else {  /* child */
        printf("I'm the child. My PID = %d\n", getpid());
        while(1);
    } 
 
    return 0;
}
