#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>  // Para sched_getcpu()

int main() {
    printf("Proceso padre en CPU: %d\n", sched_getcpu());

    pid_t pid = fork();
    if (pid == 0) {
        printf("Proceso hijo en CPU: %d\n", sched_getcpu());
    } else {
        wait(NULL);
    }

    return 0;
}
