#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int main(){    
    key_t key = ftok("/tmp/sem.temp", 1);
    int semid = semget(key, 16, IPC_CREAT | 0666); // sid

    struct sembuf sops[16];    
    for (int i = 0; i < 16; i++) {        
        sops[i].sem_num = i;        
        sops[i].sem_op = i;        
        sops[i].sem_flg = 0;    
    }    
    semop(semid, sops, 16);    
    perror("Errno after semop: ");
    return 0;
}
