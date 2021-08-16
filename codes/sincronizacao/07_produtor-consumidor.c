// livro Sistemas Operacionais Modernos - Tanenbaum
// exemplo da pagina 95

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000000000
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;

void *producer(void *ptr)
{
    int i;

    for (i = 1; i <= MAX; i++){
        pthread_mutex_lock(&the_mutex);
        
        while (buffer != 0) {
            pthread_cond_wait(&condp, &the_mutex);
        }
        
        buffer = i;

        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&the_mutex);
    }

    pthread_exit(0);
}

void *consumer(void *ptr)
{
    int i;

    for (i = 1; i <= MAX; i++){
        pthread_mutex_lock(&the_mutex);
        
        while (buffer == 0) {
            pthread_cond_wait(&condc, &the_mutex);
        }
        
        buffer = 0;

        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&the_mutex);
    }

    pthread_exit(0);
}

