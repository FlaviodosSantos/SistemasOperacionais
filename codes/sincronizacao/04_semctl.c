// codigo do livro Sistemas Distribuidos
// pag. 125

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 1234

union semun
{
    int val;
    struct semid_ds buf[2];
    unsigned short int array[4];
    struct seminfo * __buf;
};

int main ()
{
    struct sembuf sempar;
    int semid, semval, sempid;
    union semun arg;

    if ((semid = semget(KEY, 4, IPC_CREAT|IPC_EXCL|0600)) == -1)
    {
        printf("Erro ao criar o semaforo\n");
        exit(1);
    }

    printf("O conjunto de semaforos foi criado com o identificacao: %d\n", semid);

    if ((semval = semctl(semid, 2, GETVAL, arg)) == -1)
    {
        printf("Erro ao ler o terceiro semaforo \n");
        exit(1);
    } else {
        printf("O valor do terceiro semaforo eh: %d \n", semval);
    }

    sleep(3);
    sempar.sem_num = 2;
    sempar.sem_op = 1;
    sempar.sem_flg = SEM_UNDO;

    if (semop(semid, &sempar, 1) == -1)
    {
        printf("Nao foi possivel atualizar o semaforo\n");
        exit(-1);
    }
    if ((semval = semctl(semid, 2, GETVAL, arg)) == -1)
    {
        printf("Nao foi possivel pegar o valor do semaforo\n");
        exit(1);
    } else {
        printf("O valor do terceiro semaforo agora eh: %d \n", semval);
    }

    sleep(3);
    if (semctl(semid, 0, IPC_RMID, 0) == -1)
    {
        printf("Ipossivel destruir o semaforo\n");
        exit(1);
    } else {
        printf("O semaforo com id %d foi destruido\n", semid);
    }

    exit(0);
}

/*
Para compilar(no LINUX) este programa como "semctl" :
# gcc 04_semctl.c -o semctl

Para rodar:
# ./semctl

*/