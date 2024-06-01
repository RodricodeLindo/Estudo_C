#include<stdio.h>
#include<stdlib.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

void inserir(No **fila, int num){
  No *novo = malloc(sizeof(No)), *aux;
  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    if(*fila == NULL)
      *fila = novo;
    else{
      aux = *fila;
      while(aux->proximo)
        aux = aux->proximo;
      aux->proximo = novo;
    }
  } else 
    printf("\n\Erro ao alocar memoria.\n");
}

No* remover(No **fila){
  No *remover = NULL;

  if(*fila){
    remover = *fila;
    *fila = remover->proximo;
  }
  else 
    printf("\n\tFila Vazia\n");
  return remover;
}

void imprimir(No *fila){
  printf("\t---------- FILA --------\n\t");
  while(fila){
    printf("%d ", fila->valor);
    fila = fila->proximo;
  }
  printf("\n\t-------- FIM FILA ------\n");
}

int main(){
  No *fila = NULL, *r;
  int opc, valor;
  do{
    printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - imprimir\n");
    scanf("%d", &opc);

    switch(opc){
      case 1:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir(&fila, valor);
        break;
      case 2:
        r = remover(&fila);
        if(r){
          printf("Removido: %d\n", r->valor);
          free(r);
        }
        break;
      case 3:
        imprimir(fila);
        break;
      default:
        if(opc != 0)
          printf("\nOpção inválida\n");
    }
  } while(opc);

  return 0;
}

