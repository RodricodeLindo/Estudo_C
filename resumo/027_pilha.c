#include <stdio.h>
#include <stdlib.h>
#include "027_pilha.h"

No* push(No *pilha, int num){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = pilha;
    return novo;
  } else 
    printf("\nNão foi possivel alocar memoria!!\n");
  return NULL;
}

No* pop(No **pilha){
  No *remover = NULL;
  if(*pilha){
    remover = *pilha;
    *pilha = (*pilha)->proximo;
    return remover;
  } else 
    printf("\nA pilha esta vazia!!\n");
  return NULL;
}

void imprimir(No *pilha){
  printf("\n\tPILHA\n");
  while(pilha){
    printf("\t%d\n", pilha->valor);
    pilha = pilha->proximo;
  }
  printf("\n");
}
