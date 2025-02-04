#include <stdio.h> // entra y salida
#include <unistd.h> // funciones estandar de unix
#include <stdlib.h> // librería estandar
#include <sys/types.h> // definición de tipos pid_t
#include <signal.h> // nombres de señales y función kill


// un programa que recibe una señal

void captura_signal(int num_signal) {
    printf("La señal recibida es : %d\n", num_signal);
}

int main() {
    // pid_t pid = getpid();
    printf("\nMi pid es: %d\n", getpid());
    fflush(stdout);

    signal(SIGINT, captura_signal);

    while (1) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    
    //alarm(0);

    return 0;
}