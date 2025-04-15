#include <stdio.h>

struct endereco {
    char rua[50];
    int numero;
};

struct pessoa {
    char nome[40];
    struct endereco end;
    float salario;
    int dependentes;
};

int main(void) {
    struct pessoa p = { "Pedro Alvares", { "Rua Abc", 123 }, 1500.04, 7};

    printf("\nNome: %s\nRua: %s\nNumero: %d\nSalario: %.2f\nDependentes: %d\n",
        p.nome, p.end.rua, p.end.numero, p.salario, p.dependentes);

    return 0;
}