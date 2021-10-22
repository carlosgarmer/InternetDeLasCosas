#include <signal.h>
#include <studio.h>

void handle(int signal){
    printf("Jajaja %d\n", signal);
}

int main(){
    signal(2, handle);
    while(1){
        printf("Trabajando \n");
        sleep(1);
    }

    return 0;
}