#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5
int saldo;

void *printhola(void *arg){
    // printf("Hola desde un hilo\n");
    int saldolocal = saldo;
    saldo += 100;
    saldo = saldolocal;
    // while(1){
    //     printf("Trabajando \n")
    //     sleep(1);
    // }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    for( int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printhola, NULL);
    }

    printf("El valor del saldo %d\n", saldo);
    pthread_exit(NULL);
}