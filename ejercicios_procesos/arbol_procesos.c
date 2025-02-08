#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid) {
        printf("padre %d mi hijo es %d\n", getpid(), pid);
        waitpid(pid, NULL, 0);
    } else {
        for (int i = 0; i < 3; i++) {
            pid_t pid = fork();
            if (pid) {
                printf("padre %d mi hijo es %d\n", getpid(), pid);
                waitpid(pid, NULL, 0);
            } else {
                if (i == 1) {
                    for (int i = 0; i < 2; i++) {
                        pid_t pid = fork();
                        if (pid) {
                            printf("padre %d mi hijo es %d\n", getpid(), pid);
                            waitpid(pid, NULL, 0);
                            exit(0);
                        }
                    }
                    exit(0);
                    
                } else {
                    pid_t pid = fork();
                    if (pid) {
                        printf("padre %d mi hijo es %d\n", getpid(), pid);
                        waitpid(pid, NULL, 0);
                        exit(0);
                    } else {
                        for (int i = 0; i < 2; i++) {
                            pid_t pid = fork();
                            if (pid) {
                                printf("padre %d mi hijo es %d\n", getpid(), pid);
                                waitpid(pid, NULL, 0);
                            } else {
                                exit(0);
                            }
                        }
                        exit(0);                        
                    }
                }
            }
        }
    }
    return 0;
}