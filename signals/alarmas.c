#include <stdio.h> // entra y salida
#include <unistd.h> // funciones estandar de unix
#include <stdlib.h> // librería estandar
#include <sys/types.h> // definición de tipos pid_t
#include <signal.h> // nombres de señales y función kill

void alarma_accion(int sig_num) {
    if (sig_num == SIGALRM) {
        printf("\nSe recibió la alarma\n");
    } else {
        printf("se recibió otra alarma");
    }
    printf("Tiempo acabdo...");
    exit(0);
}

int main() {
    char user[20];
    printf("mi pid es: %d\n", getpid());

    signal(SIGALRM, alarma_accion);

    printf("Nombre de usuario: ");
    fflush(stdout);

    alarm(10);
    fgets(user, 10, stdin);

    alarm(0);

    printf("Usario: %s\n", user);

    return 0;
}