#ifndef PILHA_H
#define PILHA_H

typedef struct no{
  int valor;
  struct no *proximo;
}No;

No* push(No *pilha, int num);

No* pop(No **pilha);

void imprimir(No *pilha);

#endif
