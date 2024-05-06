#include<stdio.h>
#include<stdlib.h>
#include "027_pilha.h"

int fatorial(int num){
  No *remover, *pilha = NULL;
  while(num > 1){
    pilha = push(pilha, num);
    num--;
  }

  imprimir(pilha);

  while(pilha){
    remover = pop(&pilha);
    num = num * remover->valor;
    free(remover);
  }
  return num;
}

int main(){
  int valor;
  printf("Digite um valor maior que zero para o fatorial: ");
  scanf("%d", &valor);
  printf("\tFatorial de %d: %d\n\n", valor, fatorial(valor));

  return 0;
}
