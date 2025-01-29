#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//haga un proces que cree un proceso hijo y muestra la relación entre estos

int main() {
    pid_t pid = fork();

    if (pid > 0) {  // Proceso padre
        wait(NULL);  // Espera a que el hijo termine
        printf("Soy el padre. Mi ID: %d, El ID de mi hijo: %d\n", getpid(), pid);
    } else if (pid == 0) {  // Proceso hijo
        printf("Soy el hijo. Mi ID: %d, El ID de mi padre: %d\n", getpid(), getppid());
    } else {
        printf("Error al crear el proceso\n");
    }

    return 0;
}

