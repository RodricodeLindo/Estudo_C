#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int *p, tam, *vet;
//  p = malloc(sizeof(int));
  p = calloc(1, sizeof(int));
  *p = 30;
  srand(time(0));

  printf("\nA memória alocada em %p, possue o valor %d\n", p, *p);
  printf("Digite o tamnaho do vetor: ");
  scanf("%d", &tam);

  vet = calloc(tam, sizeof(int));
  
  if(vet){
    for(int x=0;x<tam;x++)
      *(vet + x) = rand() % 50;
    for(int x=0;x<tam;x++)
      printf("\nMemória: %p Valor: %d\n", vet+x, *(vet + x));
  } else 
    printf("Erro ao alocar memória!\n");

  free(vet);//memory leak
  p = realloc(p, 0);// realloc(ponteiro, novo tamanho) retorna um endereço de memória.
//                     Se o novo tamanho da memória for zero ele a libera, caso não haja tamho suficiente NULL.
  return 0;
}
