#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_TRHREADS 100
int saldo;

pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;

void *printHola(void *arg){
    int saldolocal = saldo;
    pthread_mutex_lock(&lockSaldo);
    saldolocal = saldo;
    saldolocal += 100;
    saldo = saldolocal;
    pthread_mutex_unlock(&lockSaldo);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_TRHREADS];
    saldo = 0;
    for (int i = 0; i < NUM_TRHREADS; i++) {
        pthread_create(&threads[i],NULL,printHola, NULL); 
    }
    for (int i = 0; i < NUM_TRHREADS; i++) {
        pthread_join(threads[i],NULL); 
    }
    printf("El valor del saldo es %d \n", saldo);
    pthread_exit(NULL); 
}