// codigo do livro Sistemas Distribuidos
// pag. 130

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include "05.0_dijkstra.h"

#define KEY 123

int main()
{
    int sem;
    sem = sem_create(KEY, 1);
    printf("Um semaforo foi criado com o identificador %d. \n", sem);
    if (fork() == 0) {
        printf("\tProcesso filho usa o recurso. \n");
        P(sem);
        sleep(8);
        printf("\tProcesso filho libera o recurso. \n");
        V(sem);
        sleep(1);    
    } else {
        sleep(1); 
        printf("\tProcesso PAI bloqueia ao tentar acessar o recurso. \n");
        P(sem);
        printf("\tRecurso disponivel para o processo PAI. \n");
        sem_delete(sem);
    }

    exit(0);
}


/*
Para compilar(no LINUX) este programa como "semaforo_binario" :
# gcc -pthread 05.1_semaforo_binario.c -o semaforo_binario

Para rodar:
# ./semaforo_binario

*/