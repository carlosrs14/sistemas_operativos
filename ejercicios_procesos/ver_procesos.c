#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Proceso hijo: Crear otro hijo para simular un árbol de procesos
        fork();
        sleep(2);  // Esperar un poco para que el padre siga corriendo
        exit(0);
    } else {
        // Proceso padre: Esperar un momento y luego ejecutar `pstree`
        sleep(1);
        printf("Jerarquía de procesos:\n");
        
        pid_t pid2 = fork();

        if (pid2) {
            char comand[50];
            sprintf(comand, "pstree -p %d", getpid()); // $$ es el PID del shell que ejecuta este programa
            system(comand);
        } else {
            fork();
            sleep(1);
        }
        

    }

    return 0;
}
