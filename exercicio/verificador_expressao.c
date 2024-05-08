#include<stdio.h>
#include<stdlib.h>

typedef struct no{
  char caracter;
  struct no *proximo;
}No;

No* push(No *pilha, char caracter){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->caracter = caracter;
    novo->proximo = pilha;
    return novo;
  } else 
    printf("\nErro ao alocar memoria!\n");
  return NULL;
}

No* pop(No **pilha){
  No *remover = NULL;

  if(*pilha){
    remover = *pilha;
    *pilha = (*pilha)->proximo;
  } else 
    printf("\nPilha vazia\n");
  return remover;
}

void imprimir(No *pilha){
  printf("\tPilha\n");
  while(pilha){
    printf("\t%c\n", pilha->caracter);
    pilha = pilha->proximo;
  }
  printf("\tFIM PILHA\n");
}

int forma_par(char f, char d){
  switch(f){
    case ')':
      return (d == '(') ? 1 : 0;
      break;
    case ']':
      if(d == '[')
        return 1;
      else 
        return 0;
      break;
    case '}':
      if(d == '{')
        return 1;
      else 
        return 0;
      break;
    default:
      return 0;
  }
}

int verifica_expreissao(char x[]){
  int i=0;
  No *pilha = NULL, *remover;
  while(x[i] != '\0'){
    if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
      pilha = push(pilha, x[i]);
      imprimir(pilha);
    } else if(x[i] == ']' || x[i] == ')' || x[i] == '}'){
      if(pilha){
        remover = pop(&pilha);
        if(forma_par(x[i], remover->caracter) == 0){
          printf("\tEXPRESSAO MAL FORMADA\n");
          free(remover);
          return 1;
        }
        free(remover);
      } else{
        printf("\tEXPRESSAO MAL FORMADA\n");
        return 1;
      }
    } 
    i++;
  }
  imprimir(pilha);
  if(pilha){
    printf("\tExpressao mal formada\n");
    return 1;
  } else{
    printf("\tEXPRESSAO BEM FORMADA!\n");
    return 0;
  }
}

int main(){
  char exp[50];
  printf("\tDigite uma expressao: ");
  scanf("%49[^\n]", exp);
  printf("\nExpressao: %s\nRetorno: %d\n", exp, verifica_expreissao(exp));

  return 0;
}
