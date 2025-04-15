#include <stdio.h>

struct pessoa {
    char nome[40];
    char endereco[50];
    float salario;
    int dependentes;
};

int main(void) {
    struct pessoa p1 = { "Pedro Alvares", "Rua A", 1500.04, 7 };
    struct pessoa p2;

    p2 = p1;

    printf("\nNome: %s\nEndereco: %s\nSalario: %.2f\nDependentes: %d\n", 
        p2.nome, p2.endereco, p2.salario, p2.dependentes);
    return 0;
}