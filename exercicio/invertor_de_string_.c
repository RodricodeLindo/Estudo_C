#include<stdio.h>
#include<stdlib.h>

typedef struct no{
  char letra;
  struct no *proximo;
}No;

No* push(No *pilha, char letra){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->letra = letra;
    novo->proximo = pilha;
    return novo;
  } else 
    printf("\nErro ao alocar memoria\n");
  return NULL;
}

No* pop(No **pilha){
  No *remove = NULL;
  if(*pilha){
    remove = *pilha;
    *pilha = (*pilha)->proximo;
  } else 
    printf("\nPilha vazia!!!\n");
  return remove;
}

void inverter_string(char frase[]){
  No *pilha = NULL, *remover;
  int y=0;
  for(int x=0; frase[x]!='\0'; x++){
    if(frase[x] != ' ')
      pilha = push(pilha, frase[x]);
    else{
      while(pilha){
        remover = pop(&pilha);
        frase[y] = remover->letra;
        free(remover);
        y++;
      }
      frase[y] = ' ';
      y++;
    }
  }
  while(pilha){
    remover = pop(&pilha);
    frase[y] = remover->letra;
    free(remover);
    y++;
  }
}

int main(){
  char frase[] = "cois sdkfj fjfjfjfjfj";
  inverter_string(frase);
  printf("\n%s\n\n", frase);

  return 0;
}
