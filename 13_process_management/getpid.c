#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    printf("----> My PID = %d\n", getpid());
    printf("----> My Parent's PID = %d\n", getppid());
    while(1);
    return 0;
}
