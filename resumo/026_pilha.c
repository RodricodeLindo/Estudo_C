#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct{
  int dia, mes, ano;
} Data;

typedef struct{
  char nome[50];
  Data data;
} Pessoa;

typedef struct no{
  Pessoa p;
  struct no *proximo;
} No;

Pessoa ler_pessoa(){
  Pessoa p;
  printf("\nDigite nome e data de nascimento dd mm aaaa: ");
  scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
  printf("\n");
  return p;
}

No* push(No *topo){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->p = ler_pessoa();
    novo->proximo = topo;
    return novo;
  } else 
    printf("\nErro ao alocar memória!!!\n");
  return NULL;
}

No* pop(No **topo){
  if(*topo){
    No *remover = *topo;
    *topo = (*topo)->proximo;
    return remover;
  } else 
    printf("\nPilha vazia!\n");
  return NULL;
}

void imprimir_pessoa(Pessoa p){
  printf("\nNome: %s\nData: %2d%2d%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void imprimir_pilha(No *topo){
  while(topo){
    imprimir_pessoa(topo->p);
    topo = topo->proximo;
  }
}

int main(){
  setlocale(LC_ALL, "portuguese-brazilian");
  No *remover, *topo = NULL;
  int opc;

  do{
    printf("\n0 - Sair\n1 - Empilar\n2 - Desempilhar\n3 - Imprimir\n");
    scanf("%d", &opc);
    getchar();

    switch(opc){
      case 1:
        topo = push(topo);
        break;
      case 2:
        remover = pop(&topo);
        if(remover){
          printf("\nElemento removido com sucesso!\n");
          imprimir_pessoa(remover->p);
          free(remover);
        } else 
        printf("\nSem no a remover.\n");
        break;
      case 3:
        imprimir_pilha(topo);
        break;
      default:
        if(opc != 0)
          printf("\nOpção inválida!!!\n");
    }
  }while(opc != 0);

  return 0;
}
