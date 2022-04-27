#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}TNo;

TNo * alocaNo(int k);
void insereInicio(TNo **p, int k);
void imprimeLista(TNo *p);

int main(void)
{
    TNo *prim=NULL;
    insereInicio(&prim, 12);
    insereInicio(&prim, 33);
    insereInicio(&prim, 4);
    imprimeLista(prim);
    printf("\n%d", prim->valor);
}

TNo * alocaNo(int k)
{
    TNo *paux;
    paux = (TNo *)malloc(sizeof(TNo));
    if (paux==NULL) {
        return NULL;
    }
    paux->valor = k;
    paux->prox = NULL;
    return paux;
}

void insereInicio(TNo **p, int k)
{
    TNo *paux=NULL;
    paux = alocaNo(k);
    if(paux == NULL) {
        return;
    }
    paux->prox = *p;
    *p = paux;
}

void imprimeLista(TNo *p)
{
    if (p==NULL) {
        printf("\nLista vazia.");
        return;
    }
    while (p!=NULL) {
        printf("\n%d", p->valor);
        p = p->prox;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defines a simple list that holds int type, declare with NULL
typedef struct node {
    int x;
    struct node *next;
} node;

// Pushes a node to the beginning of the list
void push_node(node **n, int x) {
    node *tmp = (node*) calloc(1, sizeof(node));
    if (tmp == NULL) return;
    tmp->next = *n; tmp->x = x;
    *n = tmp;
}

// Pushes a node to the end of the list
void node_add(node **n, int x) {
    node *new_node = (node*) calloc(1, sizeof(node));
    if (new_node == NULL) return;
    new_node->x = x; new_node->next = NULL;
    if (*n == NULL) *n = new_node;
    else {
        node *tmp = *n;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

// Asserts if node exists
bool node_exist(node *n, int x) {
    if (n == NULL) return false;
    if (n->x == x) return true;
    node_exist(n->next, x);
}

// Find index of node, returns -1 if not found
int search_node(node *n, int x) {
    int index = 0;
    if (!node_exist(n, x)) return -1;
    while (n != NULL) {
        if (n->x == x) return index;
        n = n->next;
        index++;
    }
}

// Prints all nodes
void print_node(node *n) {
    while (n != NULL) {
        printf("%d\n", n->x);
        n = n->next;
    }
    return;
}

// Frees list, valgrind: "All heap blocks were freed -- no leaks are possible"
void free_node(node *n) {
    node *tmp = n;
    while (n != NULL) {
        tmp = n->next;
        free(n);
        n = tmp;
    }
}
