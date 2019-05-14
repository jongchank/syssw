#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;

    fd = open("./fifo1", O_RDWR);
    if (fd < 0) {
        perror(argv[0]);
        exit(1);
    }
    if (argc == 2)
        write(fd, argv[1], strlen(argv[1]) + 1);    
    close(fd);    
    return 0;
}
