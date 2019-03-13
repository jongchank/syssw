#include <stdio.h>

int main(void)
{
    int i;
    unsigned int a = 0;

    while (1) {
        printf("%u = %02x %02x %02x %02x",
            a,
            ((unsigned char *)&a)[0],
            ((unsigned char *)&a)[1],
            ((unsigned char *)&a)[2],
            ((unsigned char *)&a)[3]); 
        a++; 
        getchar();
    }

    return 0;
}
