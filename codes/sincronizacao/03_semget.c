// codigo do livro Sistemas Distribuidos
// pag. 121

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 123

int main () 
{
    int semid;
    if ((semid = semget(KEY, 4, IPC_CREAT|IPC_EXCL|0600)) ==-1) 
    {
        printf("Erro ao criar o semaforo\n");
        exit(1);
    }
    printf("Os semaforos foram criados com o identificador: %d\n", semid);
    printf("Este conjunto tem a chave unica: %d\n", KEY);
    exit(0);
}

/*
Para compilar(no LINUX) este programa como "semget" :
# gcc 03_semget.c -o semget

Para rodar:
# ./semget

*/