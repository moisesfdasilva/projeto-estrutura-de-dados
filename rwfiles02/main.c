#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

FILE *file;
char fileName[] = "the-file.txt";
char str[60];

void writeText(void) {
  printf("Digite a frase: ");
  scanf(" %[^\n]", str);

  file = fopen(fileName, "a");

  fprintf(file, strcat(str, "\n"));

  fclose(file);
}

void readText(void) {
  file = fopen(fileName, "r");

  if (file == NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1);
  }

  while(fgets(str, 50, file) != NULL){
    printf("%s", str);
  }

  fclose(file);
}

int main(void) {
  setlocale(LC_ALL, "portuguese");

  int option = 0;

  system("CLS");

  do {
    printf("Escolha a opção abaixo:\n");
    printf("1 - Escrever no arquivo texto\n");
    printf("2 - Ler conteúdo do arquivo texto\n");
    printf("3 - Sair\n");
    scanf("%d", &option);

    switch(option) {
      case 1:
        writeText();
        printf(" Escrita concluída!\n");
        break;
      case 2:
        readText();
        printf(" Leitura concluída!\n");
        break;
      case 3:
        printf(" Saindo \n");
        break;
      default:
        printf(" Digite uma opção válida \n");
        break;
      }
    } while(option != 3);

  system("PAUSE");

  return 0;
}
  