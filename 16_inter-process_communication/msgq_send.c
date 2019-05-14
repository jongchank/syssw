#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define PATH "/home/jongchank/syssw/16_inter-process_communication/key"

int main(int argc, char *argv[])
{
    key_t key;
    int qid;
    key = ftok(PATH, 'z');
    if (key < 0) {
        perror(argv[0]);
        fprintf(stderr, "%d\n", __LINE__);
        exit(1);
    }
    qid = msgget(key, 0600);
    if (qid < 0) {
        perror(argv[0]);
        fprintf(stderr, "%d\n", __LINE__);
        exit(1);
    }
    printf("qid = %d\n", qid);
    msgsnd(qid, argv[1], strlen(argv[1]) + 1, 0);
    exit(0);
}    
