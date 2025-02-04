#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// hacer un progrma que cree un procesos hijo
// el padre debe sumar una matriz por filas
// el hijo debe sumar la misma mtriz por columnas

int **crear_matriz(int, int);
void inicializar_al_azar(int, int, int**);

int main() {
    int filas, columnas;
    filas = columnas = 3;
    
    int **matriz = crear_matriz(filas, columnas);
    inicializar(filas, columnas, matriz);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 

    pid_t pid = fork();

    if (pid == 0) {
        int suma_columnas;
        for (int i = 0; i < filas; i++) {
            suma_columnas = 0;
            for (int j = 0; j < columnas; j++) {
                suma_columnas += matriz[j][i];
            }
            printf("La suma de la columna %d fue: %d\n", i + 1, suma_columnas);
        }
        exit(0);
    }

    if (pid) {
        int suma_filas;
        for (int i = 0; i < filas; i++) {
            suma_filas = 0;
            for (int j = 0; j < columnas; j++) {
                suma_filas += matriz[i][j];
            }
        printf("La suma de la fila %d fue: %d\n", i + 1, suma_filas);
        }
    }
    return 0;
}

int **crear_matriz(int filas, int columnas) {
    int **matriz;

    matriz = (int**) malloc(sizeof(int*) *  filas);

    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*) malloc(sizeof(int) *  columnas);
    }

    return matriz;
}

void inicializar_al_azar(int filas, int columnas, int **matriz) {
    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}
