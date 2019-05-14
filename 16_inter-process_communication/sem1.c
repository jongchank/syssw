#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};

#define PATH "/home/jongchank/syssw/16_inter-process_communication/key"

int main(int argc, char *argv[])
{
    key_t key;
    int semid;
    struct sembuf s;
    union semun arg;

    key = ftok(PATH, 'z');
    if (key < 0) {
        perror(argv[0]);
        exit(1);
    }
    semid = semget(key, 1, 0600 | IPC_CREAT);
    if (semid < 0) {
        perror(argv[0]);
        exit(1);
    }

    printf("semid = %d\n", semid);

    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    /* Lock */
    s.sem_num = 0;
    s.sem_op = -1; 
    s.sem_flg = 0;
    semop(semid, &s, 1);

    printf("getting sem\n");
    sleep(10);
    printf("releasing sem\n");

    /* Unlock */
    s.sem_num = 0;
    s.sem_op = 1;
    s.sem_flg = 0;
    semop(semid, &s, 1);
    /*
    semctl(semid, 0, IPC_RMID, NULL);      
    */
    exit(1);
}
