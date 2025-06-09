#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
  char codigo[50];
  char nome[50];
  float precoUnitario;
  int quantidadeVendida;
} Produto;

int main(void) {
  setlocale(LC_ALL, "portuguese");

  FILE *file = fopen("produto.bin", "ab");
  if(file == NULL) {
    printf("\nErro: O arquivo binário não foi aberto!\n");
    system("PAUSE");
    exit(1);
  }

  char option[50];

  system("CLS");

  while(1) {
    printf("Digite o código do produto para cadastrar um produto novo.\n");
    printf("Ou digite 'fim' para sair.\n");
    scanf(" %[^\n]", option);

    if(strcmp(option, "fim") != 0) {
      Produto newProduct;

      strcpy(newProduct.codigo, option);

      printf("Digite o nome do produto.\n");
      scanf(" %[^\n]", newProduct.nome);

      printf("Digite o preço unitário do produto.\n");
      scanf("%f", &newProduct.precoUnitario);

      printf("Digite a quantidade de unidades vendidas.\n");
      scanf("%d", &newProduct.quantidadeVendida);

      fwrite(&newProduct, sizeof(Produto), 1, file);

      printf("\nRegistros gravados com sucesso!\n");
    } else {
      break;
    }
  }

  fclose(file);

  system("PAUSE");

  return 0;
}
