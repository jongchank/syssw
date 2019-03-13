#include <stdio.h>

int main(void)
{
    unsigned char uc;
    char sc;

    uc = 255;
    uc++;
    printf("255 + 1 = %u\n", uc);

    sc = 127;
    sc++;
    printf("127 + 1 = %d\n", sc);

    uc = 0;
    uc--;
    printf("0 - 1 = %u\n", uc);

    sc = -128;
    sc--;
    printf("-128 - 1 = %d\n", sc);

    return 0;
}
