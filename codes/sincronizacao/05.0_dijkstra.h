/* SEMAFORO DE DIJKSTRA - BIBLIOTECA */

int sem_create(key_t key, int initval)
{
    int semid;
    union semun{
        int val;
        struct semid_ds *buf;
        ushort array[1];        
    } arg_ctl;
}

semid = semget(ftok("05.0_dijkstra.h", key),1,IPC_CREAT|IPC_EXCL|0666);
if (semid == -1) {
    semid = semget(ftok("05.0_dijkstra.h", key),1,0666);
    if (semid == -1){
        printf("Erro semget()\n");
        exit(1);
    }
}