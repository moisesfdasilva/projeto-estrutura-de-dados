#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    char endereco[50];
    float salario;
    int dependentes;
} Pessoa;

void troca(Pessoa pessoaA, Pessoa pessoaB) {
    Pessoa pessoaC = pessoaA;
    pessoaA = pessoaB;
    pessoaB = pessoaC;

    printf("Pessoa a: %s, %s, %.2f, %d\n", pessoaA.nome, pessoaA.endereco, pessoaA.salario, pessoaA.dependentes);
    printf("Pessoa b: %s, %s, %.2f, %d\n", pessoaB.nome, pessoaB.endereco, pessoaB.salario, pessoaB.dependentes);
}

int main(void) {
    Pessoa pessoaA = { "Joao A.", "Rua A", 2500.50, 1 };
    Pessoa pessoaB = { "Jose B.", "Rua B", 3500.35, 3 };

    troca(pessoaA, pessoaB);

    return 0;
}
