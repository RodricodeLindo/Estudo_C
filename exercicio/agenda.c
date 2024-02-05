#include <stdlib.h>
#include <stdio.h>

typedef struct{
  char nome[50];
  int dia, mes, ano;
}contato;

void imprimir(contato **c, int quant){
  printf("\n\t\tLista de Contatos:\n");
  printf("\t------------------------------------------\n");
  for(int x=0; x < quant; x++){
    printf("\t%d = %2d/%2d/%4d\t%s\n", x+1, c[x]->dia, c[x]->mes, c[x]->ano, c[x]->nome);
  }
  printf("\t------------------------------------------\n");
}

int cadastrar_contato(contato **c, int quant, int tam){
  if(quant < tam){
    contato *novo = malloc(sizeof(contato));

    printf("\nDigite o nome do contato: ");
    scanf("%50[^\n]", novo->nome);
    printf("\nDigite a data de aniversário dd mm aaaa: ");
    scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
    getchar();
    c[quant] = novo;

    return 1;
  } else{
    printf("\n\tErro ao efetuar novo cadastro. Vetor cheio!\n");
    return 0;
  }
}

void alterar_contato(contato **c, int quant){
  int id;
  
  imprimir(c, quant);

  printf("\n\tDigite o código do contato que deseja alterar: \n");
  scanf("%d", &id);
  getchar();
  id--;

  if(id >= 0 && id < quant){
    contato *novo = malloc(sizeof(contato));

    printf("\nDigite o nome do contato: ");
    scanf("%50[^\n]", novo->nome);
    printf("\nDigite a data de aniversário dd mm aaaa: ");
    scanf("%2d%2d%d", &novo->dia, &novo->mes, &novo->ano);
    getchar();
    c[id] = novo;
  } else
      printf("\n\tCódigo inválido!\n");
}

void salvar(contato **c, int quant, char arquivo[]){
  FILE *file = fopen(arquivo, "w");

  if(file){
    fprintf(file, "%d\n", quant);
    for(int x=0; x < quant; x++){
      fputs(c[x]->nome, file);
      fputc('\n', file);
      fprintf(file, "%d %d %d\n", c[x]->dia, c[x]->mes, c[x]->ano);
    }
    fclose(file);
  } else
    printf("\n\tNÃO FOI POSSÍVEL ABRIR/CRIAR O ARQUIVO!!!\n");
}

int ler_arquivo(contato **c, char arquivo[]){
  FILE *file = fopen(arquivo, "r");
  contato *novo = malloc(sizeof(contato));
  int quant = 0;

  if(file){
    fscanf(file, "%d\n", &quant);
    for(int x=0; x<quant; x++){
      fscanf(file, "%50[^\n]", novo->nome);
      fscanf(file, "%d %d %d\n", &novo->dia, &novo->mes, &novo->ano);
      c[x] = novo;
      if(x < quant-1)
        novo = malloc(sizeof(contato));
    }
    fclose(file);
  } else 
    printf("\n\tNÃO FOI POSSÍVEL ABRIR/CRIAR O ARQUIVO!!\n");
  return quant;
}

int main(){
  contato *agenda[50];
  int tam = 50, quant = 0, opc;
  char arquivo[] = {"agenda.txt"};
  
  do{
    printf("\n\n\t\tCalendário de Aniversários!!\n\n");
    printf("1 - Cadastrar\n2 - Imprimir\n3 - Salvar\n4 - Ler arquivo\n5 - Alterar\n0 - Sair\n\n-> ");
    scanf("%d", &opc);
    getchar();
    switch(opc){
      case 1:
        quant += cadastrar_contato(agenda, quant, tam);
        break;
      case 2:
        imprimir(agenda, quant);
        break;
      case 3:
        salvar(agenda, quant, arquivo);
        break;
      case 4:
        quant = ler_arquivo(agenda, arquivo);
        break;
      case 5:
        alterar_contato(agenda, quant);
        break;
      default:
        if(opc != 0)
          printf("\n\tOpção Inválida!!");
    }
  }while(opc != 0);

  return 0;
}
