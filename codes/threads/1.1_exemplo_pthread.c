#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define gettid() syscall(SYS_gettid)

void* funcao_thread(void* arg)
{
    printf("\tNova thread criada com PID %d e TID %ld.\n", 
            getpid(), gettid());
    sleep(10);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    printf("Processo pesado PID %d\n", getpid());
    
    pthread_create(&thread1, NULL, &funcao_thread, NULL);
    
    pthread_create(&thread2, NULL, &funcao_thread, NULL);

    //printf("Identificador da thread %lu\n",thread1);
    //printf("Identificador da thread %lu\n",thread2);
    
    sleep(5);
    
    printf("Main finalizando\n");

    return 0;
}