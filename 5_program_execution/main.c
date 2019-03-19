/*
 * This is the file with the main function
 *
 * Created by Jong-Chan Kim
 */

#include <stdio.h>
#include "func.h"

#define LEN_STR (30 + 1)

int g_global = 0;

int main(void)
{
#if 1
    char str[LEN_STR] = "Hello World\n";
#else 
    char str[LEN_STR] = "Goodbye World\n";
#endif
    
    func(str);
   
    return 0;
}
