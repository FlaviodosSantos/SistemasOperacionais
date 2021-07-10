// codigo do livro Sistemas Distribuidos
// pag. 56

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
    char *cmd[] = { "cat" , "/etc/passwd" , (char *)0 };

    printf("Vou chamar o programa cat para ler o conteúdo de /etc/passwd. \n");

    execv("/bin/cat", cmd);

    printf("Esta mensagem não será impressa. \n");

    exit(0);
}

/*
Para compilar(no LINUX) este programa como "execv" :
# gcc 2_execv.c -o execv

Para rodar:
# ./execv

*/