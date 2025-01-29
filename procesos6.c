#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0 ) {
        printf("error\n");
        exit(1);
    }

    if  (pid > 0 ) {
        wait(NULL);
        printf("Soy el padre y me ejecuto después de mi hijo.\n");
    }

    if (pid == 0) {
        sleep(2);
        printf("Soy el hijo y me estoy ejecutando primero...\n");
        sleep(2);
    }    
    return 0;
}