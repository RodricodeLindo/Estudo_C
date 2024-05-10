#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct no{
  float valor;
  struct no *proximo;
}No;

No* push(No *pilha, float valor){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = valor;
    novo->proximo = pilha;
    return novo;
  } else 
    printf("\nErro ao alocar memoria!!!\n");
  return NULL;
}

No* pop(No **pilha){
  No *remover = NULL;
  if(*pilha){
    remover = *pilha;
    *pilha = (*pilha)->proximo;
  } else 
    printf("\nPilha vazia!\n");
  return remover;
}

int elevadoint(float num, int x){
  if(x > 1){
    x--;
    return 10 * elevadoint(num, x);
  } else 
    return num;
}

float elevadodec(float num, int x){
  if(x > 0){
    x--;
    return 0.1 * elevadodec(num, x);
  } else 
    return num;
}

float notacao_polonesa(char calc[]){
  int inte=0, deci=0;
  float aux=0;
  No *pilha = NULL, *pilh = NULL, *remove;
  for(int x=0; calc[x]!='\0'; x++){
    aux = 0;
    if(isdigit(calc[x])){
      if(x > 0 && calc[x-1] == '-')
        pilha = push(pilha, 48-calc[x]);
      else 
        pilha = push(pilha, calc[x]-48);
      inte++;
    } else if(calc[x] == ',' || calc[x] == '.'){
      x++;
      while(calc[x] != ' '){
        if(isdigit(calc[x])){
          pilha = push(pilha, calc[x]-48);
          x++;
          deci++;
        }
      }
      x--;
    } else if(calc[x] == ' ' && inte > 0){
      while(deci>0){
        remove = pop(&pilha);
        aux += elevadodec(remove->valor, deci);
        free(remove);
        deci--;
      }
      for(int z=0; z<inte; z++){
        remove = pop(&pilha);
        pilh = push(pilh, remove->valor);
        free(remove);
      }
      while(pilh){
        remove = pop(&pilh);
        aux += elevadoint(remove->valor, inte);
        free(remove);
        inte--;
      }
      pilha = push(pilha, aux);
    } else if(calc[x] != ' ' && calc[x-1] == ' ' && (calc[x+1] == ' ' || calc[x+1] == '\0') && pilha){ 
      switch(calc[x]){
        case '+':
          remove = pop(&pilha);
          aux = remove->valor;
          free(remove);
          if(pilha){
            remove = pop(&pilha);
            pilha = push(pilha, remove->valor+aux);
            free(remove);
          }
          break;
        case '-': 
          remove = pop(&pilha);
          aux = remove->valor;
          free(remove);
          if(pilha){
            remove = pop(&pilha);
            pilha = push(pilha, remove->valor-aux);
            free(remove);
          }
          break;
        case '*': 
          remove = pop(&pilha);
          aux = remove->valor;
          free(remove);
          if(pilha){
            remove = pop(&pilha);
            pilha = push(pilha, remove->valor*aux);
            free(remove);
          }
          break;
        case '/': 
          remove = pop(&pilha);
          aux = remove->valor;
          free(remove);
          if(pilha){
            remove = pop(&pilha);
            pilha = push(pilha, remove->valor/aux);
            free(remove);
          }
          break;
        default:
          printf("\nERRO! valor invalido\n");
      }
    }
  }
  if(pilha){
    remove = pop(&pilha);
    aux = remove->valor;
    free(remove);
  }
  if(pilha){
    while(pilha){
      remove = pop(&pilha);
      free(remove);
    }
    printf("\nErro, sintaxe mal feita!!\n");
    aux=0;
  }
  return aux;
}

int main(){
  char calc[30];
  printf("Digite o calculo: ");
  scanf("%29[^\n]", calc);
  printf("\n\to resultado foi %.2f\n\n", notacao_polonesa(calc));

  return 0;
}
