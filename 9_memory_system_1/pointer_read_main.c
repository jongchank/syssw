#if 0
unsigned long p = 16; /* p in data */
#else
unsigned long p; /* p in bss */
#endif

int main(void)
{
    function();
}
