#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

#define MAX_LINE    (30 + 1)

int main(int argc, char *argv[]) {
    int fd[2], n;
    pid_t pid;
    char line[MAX_LINE] = "";

    if (pipe(fd) < 0) {
        perror(argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid < 0) {    /* fork() error */
        perror(argv[0]);
        exit(1);
    } 
    
    if (pid > 0) {    /* parent */
        char *hello = "hello baby";
        write(fd[1], hello, 11);
        printf("parent : Write to pipe <%s>\n", hello);
        sleep(2);
        n = read(fd[0], line, MAX_LINE);
        printf("parent : Read from pipe <%s>\n", line);
    }
    else {    /* child */
        char *hello = "hello mommy";
        sleep(1);
        n = read(fd[0], line, MAX_LINE);
        printf("child : Read from pipe <%s>\n", line);
        write(fd[1], hello, 12);
        printf("child : Write to pipe <%s>\n", hello);
    }
    exit(0);
}
