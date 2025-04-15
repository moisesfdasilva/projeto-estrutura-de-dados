#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[40];
    char endereco[50];
    float salario;
    int dependentes;
} Pessoa;

int main(void) {
    Pessoa p;

    strcpy(p.nome, "Pedro Alvares Cabral");
    strcpy(p.endereco, "Rua A, nr 123");
    p.salario = 1500.04;
    p.dependentes = 7;

    return 0;
}
