#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *args[]) {
    int numero;
    char caracter;
    FILE *file = fopen(args[1], "r");
    while (!feof(file)) {
        fscanf(file, "%d", &numero);
        fscanf(file, "%c", &caracter);
        
        printf("numero: %d\n", numero);
        printf("numero: %c\n", caracter);
        
    }
}
