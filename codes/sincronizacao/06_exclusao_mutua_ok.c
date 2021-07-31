// codigo do livro Sistemas Distribuidos
// pag. 132

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "05.0_dijkstra.h"

#define KEY 1234

pthread_t tid1, tid2;

long conta = 0;

void * t1(int sem)
{
    P(sem);
    long i;
    for (i = 0; i < 1000000; i++)
    {
        conta = conta + 5;
    }

    printf("Encerrei t1\n");
    V(sem);
}

void * t2(int sem)
{
    P(sem);
    long i;
    for (i = 0; i < 1000000; i++)
    {
        conta = conta + 2;
    }

    printf("Encerrei t2 \n");
    V(sem);
}

int main ()
{
    int sem;
    sem = sem_create(KEY, 1);
    printf("Um semaforo foi criado com o identificador %d. \n", sem);

    pthread_create(&tid1, NULL, t1, (void *)sem);
    pthread_create(&tid2, NULL, t2, (void *)sem);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_delete(sem);
    printf("O valor de conta eh: %ld\n", conta);

    return 0;
}

/*
Para compilar(no LINUX) este programa como "exclusao_mutua_ok" :
# gcc -pthread 06_exclusao_mutua_ok.c -o exclusao_mutua_ok

Para rodar:
# ./exclusao_mutua_ok

*/