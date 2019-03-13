#include <stdio.h>

int main(void)
{
    int i;
    float sum = 0.0;
    
    for (i = 0; i < 1000; i++) {
        sum += 0.001;
    } 
    
    printf("%f\n", sum);
    
    return 0;
}

