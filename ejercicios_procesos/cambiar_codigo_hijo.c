#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


// llamar así
// ./prueba ./codigo_hijo
int main(int argc, char *args[]) {
    
    pid_t pid = fork();
    //= {"./codigo_hijo.out", 0};
    
    if (pid == -1) {
        printf("Hubo un error al crer el hijo\n");
        exit(0);
    }

    if (pid) {
        printf("soy %d el padre de %d\n", getpid(), pid);
        wait(NULL);
        printf("terminó el prceso del hijo\n");
    }

    if (!pid) {
        execvp(args[1], args);
        perror("Hubo un error al ejercutar execvp\n");
        return 1;
    }

    return 0;
}