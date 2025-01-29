#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int dato = 0;
int dato2 = 0;


int main() {
    int fd[2];
    int fd2[2];
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int tam = sizeof(numeros) / sizeof(int);
    pid_t pid = fork(), pid2;
    int final = 4;
    char buffer[10];

    pipe(fd);
    pipe(fd2);
    if (pid > 0) {
        pid2 = fork();
        final = 8;
    }

    if (pid == 0 || pid2 == 0) {
        close(fd[0]);
        close(fd2[0]);
        int sum = 0;
        for (int i = final - 4; i < final; i++) {
            sum += numeros[i];
        }
        char num_char[10];
        if (final == 4) {

            printf("La suma de este lado fue: %d\n", sum);
            sprintf(num_char, "%d", sum);
            write(fd[1], num_char, strlen(num_char) + 1);
            close(fd[1]);
            exit(0);
        } else {
            sleep(3);
            printf("La suma de este lado fue: %d\n", sum);
            sprintf(num_char, "%d", sum);
            write(fd2[1], num_char, strlen(num_char) + 1);
            close(fd2[1]);
            exit(0);
        }
    }
    
    close(fd[1]);
    close(fd2[1]);
    wait(NULL);
    read(fd[0], buffer, sizeof(buffer));
    printf("recibido %s\n", buffer);
    
    
    read(fd2[0], buffer, sizeof(buffer));
    wait(NULL);
    printf("recibido %s\n", buffer);
    close(fd[0]);
    close(fd2[0]);

    return 0;
}