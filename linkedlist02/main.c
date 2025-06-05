#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num;
  struct node *next;
} Node;

Node* criateNode(int value) {
  Node *newNode = malloc(sizeof(struct node));

  if(newNode == NULL) {
    printf("Erro: memoria insuficiente.\n");
    exit(0);
  }

  newNode->num = value;
  newNode->next = NULL;

  return newNode;
}

Node* insertAfter(Node *nodeA, int valueB) {
  Node *nodeB;

  if(nodeA == NULL) {
    printf("Erro: tentativa de inserir item apos ponteiro nulo.\n");
    exit(0);
  }

  nodeB = criateNode(valueB);
  nodeB->next = nodeA->next;
  nodeA->next = nodeB;

  return nodeB;
}

int listLen(Node *list) {
  Node *tmp = list;
  int len = 0;

  while(tmp != NULL) {
    tmp = tmp->next;
    len++;
  }

  return len;
}

Node* removeIndex(Node *list, int index) {
  int len = listLen(list);

  if(len <= index) {
    printf("Erro: remoção de índice inválido.\n");
    exit(0);
  }

  Node *tmp = list;

  if(index == 0) {
    list = tmp->next;
    free(tmp);
  } else {
    for(int i = 1; i < index; i++) {
      tmp = tmp->next;
    }

    Node *nodeB = tmp->next;
    tmp->next = nodeB->next;

    free(nodeB);
  }

  return list;
}

void printDefault(Node *list) {
  Node *tmp = list;

  printf("Lista: ");
  while(tmp != NULL) {
    printf(" %d", tmp->num);
    tmp = tmp->next;
  }
  printf("\n");
}

int main(void) {
  Node *list = NULL;

  Node *node1 = criateNode(2);

  list = node1;

  Node *node2 = insertAfter(node1, 4);
  Node *node3 = insertAfter(node2, 8);
  Node *node4 = insertAfter(node3, 10);
  Node *node5 = insertAfter(node4, 12);
  Node *node6 = insertAfter(node5, 14);
  Node *node7 = insertAfter(node6, 16);
  insertAfter(node7, 18);

  printf("Tamanho da lista: %d\n", listLen(list));

  printDefault(list);

  list = removeIndex(list, 5);
  list = removeIndex(list, 6);
  list = removeIndex(list, 1);
  list = removeIndex(list, 0);

  printDefault(list);
}
