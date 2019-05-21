#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

unsigned int loop_cnt;
volatile unsigned int counter = 0; // shared global variable

void *mythread(void *arg)
{
    char *letter = arg;
    int i;
    printf("%s: begin\n", letter);
    for (i = 0; i < loop_cnt; i++) {
        counter = counter + 1;
    }
    printf("%s: done\n", letter);
    return NULL;
}
                                                                             
int main(int argc, char *argv[])
{                    
    loop_cnt = atoi(argv[1]);

    pthread_t p1, p2;
    printf("main: begin [counter = %d]\n", counter);
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
    printf("main: done [counter: %d] [should be: %d]\n", counter, loop_cnt * 2);
    return 0;
}
