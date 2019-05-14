#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PATH "/home/jongchank/syssw/16_inter-process_communication/key"

int main(int argc, char *argv[])
{
    key_t key;
    int qid;
    char buf[1024];

    key = ftok(PATH, 'z');    
    if (key < 0) {
        perror(argv[0]);
        fprintf(stderr, "%d\n", __LINE__);
        exit(1);
    }
    qid = msgget(key, 0666 | IPC_CREAT);
    if (qid < 0) {
        fprintf(stderr, "%d\n", __LINE__);
        perror(argv[0]);
        exit(1);
    }
    printf("qid = %d\n", qid);
    while (1) {
        if (msgrcv(qid, buf, 1024, 0, 0) < 1) {
            perror(argv[0]);
            fprintf(stderr, "%d\n", __LINE__);
            exit(1);
        }
        if (!strncmp(buf, "quit", 4)) {
            break;
        }
        printf("%s\n", buf);
    }
    msgctl(qid, IPC_RMID, NULL);
    exit(0);
}
