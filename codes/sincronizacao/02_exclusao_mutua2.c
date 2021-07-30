// codigo do livro Sistemas Distribuidos
// pag. 116

#include <pthread.h>
#include <stdio.h>

pthread_t tid0, tid1;
int turn;
int shared;
int flag[2];


void * p0()
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        flag[0] = 1;
        turn = 0;
        while ( flag [1] == 1 && turn == 0 )
        {
            /* loop infinto */
        }
        shared = shared + 5;
        flag [0] = 0;       
    }

    //printf("Encerrei p0\n");
}

void * p1()
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        flag[1] = 1;
        turn = 1;
        while ( flag [0] == 1 && turn == 1 )
        {
            /* loop infinto */
        }
        shared = shared + 2;
        flag [1] = 0;       
    }

    //printf("Encerrei p2 \n");
}

int main ()
{
    flag [0] = 0;
    flag [1] = 0;

    pthread_create(&tid0, NULL, p0, NULL);
    pthread_create(&tid1, NULL, p1, NULL);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    printf("O valor de shared eh: %d\n", shared);

    return 0;
}

/*
Para compilar(no LINUX) este programa como "exclusao_mutua2" :
# gcc -pthread 02_exclusao_mutua2.c -o exclusao_mutua2

Para rodar:
# ./exclusao_mutua2

*/