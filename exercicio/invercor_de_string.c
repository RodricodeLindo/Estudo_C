#include<stdlib.h>
#include<stdio.h>

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
    printf("\nError ao alocar memoria!!!\n");
  return NULL;
}

No* pop(No **pilha){
  No *remover = NULL;
  if(*pilha){
    remover = *pilha;
    *pilha = (*pilha)->proximo;
  } else 
    printf("\nErro, a pilha esta vazia!!!\n");
  return remover;
}

void invertor_string(char frase[]){
  No *pilha = NULL, *remover;
  int y;
  for(int x=0; frase[x] != '\0'; x++){
    pilha = push(pilha, frase[x]);
  }
  while(pilha){
    remover = pop(&pilha);
    frase[y] = remover->letra;
    free(remover);
    y++;
  }
}

int main(){
  char frase[] = "eu nao abro nao";
  printf("%s->", frase);
  invertor_string(frase);
  printf("%s\n", frase);

  return 0;
}
