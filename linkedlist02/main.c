#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num;
  struct node *next;
} Node;

Node* criateNode(int value) {
  Node *newNode = malloc(sizeof(struct node));

  if (newNode == NULL) {
    printf("Erro: memoria insuficiente.\n");
    exit(0);
  }

  newNode->num = value;
  newNode->next = NULL;

  return newNode;
}

int main(void) {
  Node *node1 = criateNode(1);
}
