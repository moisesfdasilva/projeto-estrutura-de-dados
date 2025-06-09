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

  FILE *file = fopen("produto.bin", "rb");

  system("CLS");

  if(file == NULL) {
	  printf("\nErro: O arquivo binário não foi aberto!\n");
    system("PAUSE");
    exit(1);
	}

  Produto product;

  while(fread(&product, sizeof(Produto), 1, file) == 1) {
    printf("\nCódigo: %s\n", product.codigo);
    printf("Nome: %s\n", product.nome);
    printf("Preço unitário: %.2f\n", product.precoUnitario);
    printf("Quantidade vendida: %d\n", product.quantidadeVendida);
  }

  fclose(file);

  printf("\nRegistros lidos com sucesso!\n\n");

  system("PAUSE");

  return 0;
}
  