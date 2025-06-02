#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

FILE *file;

void writeText(void) {
  char ch[15] = "Something";
  int value[5] = { 1, 2, 3, 4, 5 };

  file = fopen("binary01.bin", "wb");

  if(file == NULL) {
		printf("\nErro: O arquivo binário.bin não foi criado!\n");
    system("PAUSE");
		exit(1);
	}

  fwrite(ch, sizeof(char), 15, file);
	fwrite(value, sizeof(int), 5, file);

  printf("\nFrase e valores gravados com sucesso!\n");

  fclose(file);
}

void readText(void) {
  char ch[15];
  int value[5], i;

  file = fopen("binary01.bin", "rb");

  if(file == NULL) {
		printf("\nErro: O arquivo binário.bin não foi aberto!\n");
		exit(1);
	}

  fread(ch, sizeof(ch), 1, file);

  for(i = 0; i < 15; i++) {
		printf("%c", ch[i]);
	}

  for(i = 0; i < 5; i++) {
		printf("\n%d", value[i]);
	}

  printf("\nDados lidos com sucesso!\n");
}

int main(void) {
  setlocale(LC_ALL, "portuguese");

  system("CLS");

  writeText();
  readText();

  system("PAUSE");

  return 0;
}
  