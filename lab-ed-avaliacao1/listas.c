#include <stdio.h>>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
  int value;
  struct node *next;
} TNo;

TNo * alocaNo(int k);
void insereInicio(TNo **p, int k);
void insereFinal(int k, TNo **p);
void deletaInicio(TNo **p);
void deletaFinal(TNo *p);
int procuraNo(int k, TNo *p);
void puxaNo(TNo **p, int k);
void imprimeLista(TNo *p);
void liberaLista(TNo *p);

TNo * alocaNo(int k)
{
    TNo *paux;
    paux = (TNo *)malloc(sizeof(TNo));
    if (paux==NULL) {
        return NULL;
    }
    paux->value = k;
    paux->next = NULL;
    return paux;
}

void insereInicio(TNo **p, int k)
{
    TNo *paux=NULL;
    paux = alocaNo(k);
    if(paux == NULL) {
        return;
    }
    paux->next = *p;
    *p = paux;
}

void insereFinal(int k, TNo **p)
{
  TNo *new_node = (TNo *) malloc(sizeof(TNo));
  if (new_node == NULL) return;

  new_node->value = k;
  new_node->next = NULL;

  if (*p == NULL) *p = new_node;
  else
  {
    TNo *paux = *p;
    while (paux->next != NULL)
      {
        paux = paux->next;
      }
    paux->next = new_node;
  }
}

void deletaInicio(TNo **p)
{
  TNo *paux = (TNo *) malloc(sizeof(TNo));
  if (paux == NULL) return;

  paux = *p;
  *p = paux->next;
  free(paux);
}

void deletaFinal(TNo *p)
{
  while (p->next->next != NULL)
    {
      p = p->next;
    }
  free(p->next);
  p->next = NULL;
}

int procuraNo(int k, TNo *p)
{
  
  int index = 0;
  if (!exist_node(k, p)) return -2;
  while (p != NULL)
    {
      index++;  
      if (p->value == k) return index;
      p = p->next;
    }
  
}

// puxa para o começo da lista
void puxaNo(TNo **p, int k) {
    TNo *paux = (TNo*) calloc(1, sizeof(TNo));
    if (paux == NULL) return;
    paux->next = *p; paux->value = k;
    *p = paux;
}

void imprimeLista(TNo *p)
{
    if (p==NULL) {
        printf("\nLista vazia.");
        return;
    }
    while (p!=NULL) {
        printf("\n%d", p->value);
        p = p->next;
    }
}

void liberaLista(TNo *p)
{
    TNo *paux = p;

    while (p != NULL)
    {
        paux = p->next;
        free(p);
        p = paux;
    }
    return 0;
}
