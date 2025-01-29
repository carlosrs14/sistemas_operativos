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

    if  (pid > 0 ){
        
        printf("imprimiendo algo\n");
        printf("imprimiendo algo\n");
        printf("imprimiendo algo\n");
        printf("imprimiendo algo\n");
        wait(NULL);
    }

    if (pid == 0) {
        sleep(10);
        system("ls");
    }

    
    return 0;
}