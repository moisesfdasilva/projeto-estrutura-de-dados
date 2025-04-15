#include <stdio.h>
#include <string.h>

typedef struct {
    char rua[50];
    int numero;
    char complemento[50];
    char bairro[50];
} Endereco;

typedef struct {
    char nome[50];
    Endereco endereco;
    char cargo[50];
    float salario;
} Pessoa;

Pessoa inputPessoa() {
    Pessoa pessoa;
    Endereco endereco;

    printf("Digite o nome: ");
    scanf(" %[^\n]", pessoa.nome);

    printf("\nDigite o cargo: ");
    scanf(" %[^\n]", pessoa.cargo);

    printf("\nDigite o salario: ");
    scanf("%f", &pessoa.salario);

    printf("\nDigite o nome da rua: ");
    scanf(" %[^\n]", endereco.rua);

    printf("\nDigite o numero da rua: ");
    scanf("%d", &endereco.numero);

    printf("\nDigite o complemento do endereco: ");
    scanf(" %[^\n]", endereco.complemento);

    printf("\nDigite o bairro: ");
    scanf(" %[^\n]", endereco.bairro);

    pessoa.endereco = endereco;

    return pessoa;
}

void pessoaPrint(Pessoa pessoa) {
    printf("\nNome %s;\nRua %s, Numero %d, Complemento %s, Bairro %s;\nCargo %s;\nSalario %.2f.\n",
        pessoa.nome,
        pessoa.endereco.rua,
        pessoa.endereco.numero,
        pessoa.endereco.complemento,
        pessoa.endereco.bairro,
        pessoa.cargo,
        pessoa.salario);
}

int main(void) {
    Pessoa pessoas[3];
    int i;

    for(i = 0; i < 3; i++) {
        printf("\n-----%d----_\n", i);
        pessoas[i] = inputPessoa();
    }

    for(i = 0; i < 3; i++) {
        pessoaPrint(pessoas[i]);
    }

    return 0;
}
