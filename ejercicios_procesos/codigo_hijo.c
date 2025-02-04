#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("soy %d, y soy el proceso hijo de %d\n", getpid(), getppid());
    fflush(stdout);
    printf("hola mudnooooo\n");
    return 0;
}