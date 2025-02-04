#include <stdio.h> // entra y salida
#include <unistd.h> // funciones estandar de unix
#include <stdlib.h> // librería estandar
#include <sys/types.h> // definición de tipos pid_t
#include <signal.h> // nombres de señales y función kill


// un programa que se envía una señal así mismo

int main() {
    pid_t pid = getpid();

    printf("soy un proceso");
    fflush(stdout);
    int i = 0;
    while (i++ < 5) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    kill(pid, SIGTSTP);

    printf("Hola mundo");
    

    return 0;
}