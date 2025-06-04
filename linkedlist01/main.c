#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num;
  struct node *next;
} Node;

int main(void) {
  Node *list = NULL;

  Node *node1 = malloc(sizeof(Node));

  int number = 3;
  node1->num = number;
  node1->next = NULL;

  list = node1;

  Node *node2 = malloc(sizeof(Node));

  number = 9;
  node2->num = number;
  node2->next = NULL;

  node1->next = node2;

  Node *tmp = list;

  while(tmp != NULL) {
    printf("%d\n", tmp->num);
    tmp = tmp->next;
  }

  return 0;
}