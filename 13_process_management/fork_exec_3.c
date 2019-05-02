#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *args[] = {"./hello", NULL};

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
        printf("I'm the parent. My PID = %d and my child's PID = %d\n", getpid(), pid);
        cpid = waitpid(pid, &status, 0);
        if (cpid != pid) {
            fprintf(stderr, "waitpid failed\n");        
        }
        printf("Child process terminated\n");
        if (WIFEXITED(status)) {
            printf("Exit status is %d\n", WEXITSTATUS(status)); 
        }
    }
    else {  /* child */
        printf("I'm the child. My PID = %d\n", getpid());
        ret = execve(args[0], args, NULL);
        if (ret < 0) {
            fprintf(stderr, "execve failed\n");   
            return 1;
        }
    } 
 
    return 0;
}
