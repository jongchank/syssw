#include <stdio.h>

int main(void)
{
    float a = 1.0;
    float b = a / 3.0 - 1.0;
    float c = (b + 1.0) * 3.0;

    if (a == c) {
        printf("a is equal to c\n"); 
    }
    else {
        printf("a is not equal to c\n"); 
    }
    return 0;
}
