#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int a = 0;
int b = 0;

int main(int argc, char *argv[], char *envp[])
{
    int ret, status;
    pid_t pid, cpid;
    
    printf("My PID = %d\n", getpid());

    pid = fork();
    if (pid < 0) {
       fprintf(stderr, "fork failed\n");
       return 1;
    }
    if (pid != 0) {  /* parent */
        printf("! I'm the parent. My PID = %d and my child's PID = %d\n", getpid(), pid);
        a = 1;
        printf("! a = %d b = %d\n", a, b);
        sleep(6);
        printf("! a = %d b = %d\n", a, b);
    }
    else {  /* child */
        printf("@ I'm the child. My PID = %d\n", getpid());
        sleep(3);
        printf("@ a = %d b = %d\n", a, b);
        b = 1;
        printf("@ a = %d b = %d\n", a, b);
    } 
 
    return 0;
}
