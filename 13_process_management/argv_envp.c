#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int i;
    printf("----> Number of arguments = %d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("----> argv[%d] = \"%s\"\n", i, argv[i]);
    }
    for (i = 0; envp[i] != NULL; i++) {
        printf("----> envp[%d] = \"%s\"\n", i, envp[i]);
    }
    return 0;
}
