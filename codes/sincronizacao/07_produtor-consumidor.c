#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000000000
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;