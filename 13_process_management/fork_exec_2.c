#include <stdio.h>
#include <unistd.h>

char *args[] = {"./hello", "arg1", "arg2", "arg3", NULL};

int main(int argc, char *argv[], char *envp[])
{
    int ret;
    pid_t pid;
    
    printf("My PID = %d\n", getpid());

    pid = fork();
    if (pid < 0) {
       fprintf(stderr, "fork failed\n");
       return 1;
    }
    if (pid != 0) {  /* parent */
        printf("I'm the parent. My PID = %d and my child's PID = %d\n", getpid(), pid);
	sleep(20);
    }
    else {  /* child */
        printf("I'm the child. My PID = %d\n", getpid());
        sleep(10);
        ret = execve(args[0], args, NULL);
        if (ret < 0) {
            fprintf(stderr, "execve failed\n");   
            return 1;
        }
    } 
 
    return 0;
}
