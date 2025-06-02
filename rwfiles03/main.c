#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

FILE *file;

typedef struct {
  char name[50];
  int age;
  char sex;
  float height;
} Friend;

void writeText(void) {
  file = fopen("friend.bin", "wb");

  if(file == NULL) {
		printf("\nErro: O arquivo binário.bin não foi criado!\n");
    system("PAUSE");
		exit(1);
	}

  Friend friendA, friendB, friendC;

  strcpy(friendA.name, "Isabel do Brasil");
  friendA.age = 21;
  friendA.sex = 'F';
  friendA.height = 1.61;

  strcpy(friendB.name, "Teresa Cristina de Bourbon-Duas Sicílias");
  friendB.age = 20;
  friendB.sex = 'F';
  friendB.height = 1.54;

  strcpy(friendC.name, "Joaquim José da Silva Xavier");
  friendC.age = 18;
  friendC.sex = 'M';
  friendC.height = 1.72;

  fwrite(&friendA, sizeof(Friend), 1, file);
  fwrite(&friendB, sizeof(Friend), 1, file);
  fwrite(&friendC, sizeof(Friend), 1, file);

  fclose(file);

  printf("\nRegistros gravados com sucesso!\n");
}

void readText(void) {
  file = fopen("friend.bin", "rb");

  if(file == NULL) {
		printf("\nErro ao abrir o arquivo binário.bin!\n");
    system("PAUSE");
		exit(1);
	}

  Friend friend;

  while(fread(&friend, sizeof(Friend), 1, file) == 1) {
    printf("Nome: %s\n", friend.name);
    printf("Idade: %d\n", friend.age);
    printf("Sexo: %c\n", friend.sex);
    printf("Altura: %.2f\n", friend.height);
    printf("\n");
  }

  fclose(file);

  printf("\nRegistros lidos com sucesso!\n");
}

int main(void) {
  setlocale(LC_ALL, "portuguese");

  system("CLS");

  writeText();
  readText();

  system("PAUSE");

  return 0;
}
  