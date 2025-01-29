#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        exit(1);
    }
    

    if (pid > 0) {
        for (int i = 0; i < 20; i++) {
            sleep(2);
            printf("El papá\n");
        }
    }
    if (pid == 0) {
        for (int i = 0; i < 5; i++) {
            sleep(5);
            printf("El hijoooo\n");
        }
    }
    return 0;
}