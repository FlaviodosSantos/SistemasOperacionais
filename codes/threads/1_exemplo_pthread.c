// codigo do livro Sistemas Distribuidos
// pag. 55

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void* funcao_thread(void* arg)
{
    printf("Nova thread criada com o PID %d. \n", getpid());
    sleep(20);
    return NULL;
}

int main ()
{
    pthread_t thread;
    printf("Processo pesado PID %d. \n", getpid());

    pthread_create (&thread , NULL, &funcao_thread, NULL);
    printf("Indentificador do thread %ld. \n", thread);

    sleep(20);
    exit(0);
}

/*
Para compilar(no LINUX) este programa como "exemplo_pthread" :
# gcc -pthread 1_exemplo_pthread.c -o exemplo_pthread

Para rodar:
# ./exemplo_pthread

*/