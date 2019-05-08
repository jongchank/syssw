#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>

#define LEN_HOSTNAME	30

int main(void)
{
    char hostname[LEN_HOSTNAME + 1];
    memset(hostname, 0x00, sizeof(hostname));
    printf("username: %s\n", getpwuid(getuid())->pw_name);

    gethostname(hostname, LEN_HOSTNAME);
    printf("hostname: %s\n", hostname);

    return 0;
}
