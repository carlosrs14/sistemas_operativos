#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num_hijos = 3;  // Número de procesos hijos a crear
    pid_t pids[num_hijos];

    for (int i = 0; i < num_hijos; i++) {
        pids[i] = fork();

        if (pids[i] < 0) {
            perror("Error al crear el proceso hijo");
            exit(1);
        }

        if (pids[i] == 0) {  // Código del proceso hijo
            printf("Soy el hijo %d, mi PID es %d, mi padre es %d\n",i + 1, getpid(), getppid());
            exit(0);  // Finaliza el proceso hijo correctamente
        }
    }

    // Código del proceso padre: espera a que todos los hijos terminen
    for (int i = 0; i < num_hijos; i++) {
        waitpid(pids[i], NULL, 0);
    }

    printf("Soy el proceso padre con PID %d, todos mis hijos han terminado.\n", getpid());

    return 0;
}
