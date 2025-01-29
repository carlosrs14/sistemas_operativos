#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int count = 3;
    for (size_t i = 0; i < count; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            exit(1);
        }
        if (pid > 0) {
            waitpid(pid, NULL, 0);
            exit(0);
        }

        if (pid == 0) {
            printf("Yo soy %d y mi padre es %d\n", getpid(), getppid());
        }
        
    }
    

    return 0;
}
