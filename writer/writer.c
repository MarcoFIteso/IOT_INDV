#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "common.h"

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    char *shm_ptr = (char *)shmat(shm_id, NULL, 0);

    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);

    // Inicializamos semáforo en 0
    semctl(sem_id, 0, SETVAL, 0);

    struct sembuf signal = {0, 1, 0};  // V operation

    while (1) {
        char buffer[SHM_SIZE];
        printf("Escribe mensaje: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        strcpy(shm_ptr, buffer);

        // Avisar al reader
        semop(sem_id, &signal, 1);
    }

    return 0;
}
