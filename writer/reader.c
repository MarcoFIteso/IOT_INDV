#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "common.h"

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    char *shm_ptr = (char *)shmat(shm_id, NULL, 0);

    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);

    struct sembuf wait = {0, -1, 0};  // P operation

    while (1) {
        // Espera hasta que writer escriba
        semop(sem_id, &wait, 1);

        printf("Reader recibió: %s\n", shm_ptr);
    }

    return 0;
}
