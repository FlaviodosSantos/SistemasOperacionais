// codigo do livro Sistemas Distribuidos
// pag. 114

#include <pthread.h>
#include <stdio.h>

pthread_t tid1, tid2;

long conta = 0;

void * t1()
{
    long i;
    for (i = 0; i < 1000000; i++)
    {
        conta = conta + 5;
    }

    printf("Encerrei t1\n");
}

void * t2()
{
    long i;
    for (i = 0; i < 1000000; i++)
    {
        conta = conta + 2;
    }

    printf("Encerrei t2 \n");
}

int main ()
{
    pthread_create(&tid1, NULL, t1, NULL);
    pthread_create(&tid2, NULL, t2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("O valor de conta eh: %ld\n", conta);

    return 0;
}

/*
Para compilar(no LINUX) este programa como "exclusao_mutua" :
# gcc -pthread 01_exclusao_mutua.c -o exclusao_mutua

Para rodar:
# ./exclusao_mutua

*/