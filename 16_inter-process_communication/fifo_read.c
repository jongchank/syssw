#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd, n;
    char req[PIPE_BUF];

    if (mkfifo("./fifo1", 0600) < 0) {
        perror(argv[0]);
        exit(1);
    }
    fd = open("./fifo1", O_RDONLY);
    if (fd < 0) {
        perror(argv[0]);
        exit(1);
    }
    while (1) {
        n = read(fd, req, PIPE_BUF);
        if (n > 0) {
            printf("%d bytes read\n", n);
            write(STDOUT_FILENO, req, n);
        }
    }
    exit(0);
}
