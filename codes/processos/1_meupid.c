// codigo do livro Sistemas Distribuidos
// pag. 55

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
    printf("Eu sou o processo %d. Meu pai é o processo %d. O ID do grupo de processo é o %d. \n", getpid(), getppid(), getpgrp());

    exit(0);
}

/*
Para compilar(no LINUX) este programa como "meupid" :
# gcc 1_meupid.c -o meupid

Para rodar:
# ./meupid

*/