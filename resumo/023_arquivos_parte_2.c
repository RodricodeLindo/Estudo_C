#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL, "pt_BR-UTF8");
  FILE *f;
  char nome[30], file[30]="teste.txt";
  int idade, opc;
  float altura;

  do{
    printf("\n\t\tRegistro de pessoas\n\n");
    printf("Todos os registros que serão criados e lidos serão salvo em %s\n", file);
    printf("[1] -> Adicionar novo pessoa ao arquivo\n");
    printf("[2] -> Ler os registros no arquivo\n");
    printf("[3] -> Mudar o arquivo que sera utilizada\n");
    printf("[4] -> Fechar programa\n");
    printf("Digite a operação: ");
    scanf("%d", &opc);
    getchar();
    switch(opc){
      case 1:
        f = fopen(file, "w");
        if(f){
          printf("Nome: ");
          scanf("%30[^\n]", nome);
          getchar();
          printf("Idade: ");
          scanf("%d", &idade);
          getchar();
          printf("Altura: ");
          scanf("%f", &altura);
          getchar();
          fprintf(f ,"%s\n%d\n%.2f\n", nome, &idade, &altura);
          fclose(f);
        } else 
          printf("ERROR ao abrir arquivo!!!\n");
        fclose(f);
        break;
      case 2:
        f = fopen(file, "r");
        if(f){
          while(fscanf(f ,"%s%d%f", nome, &idade, &altura) != -1){
            printf("\nNome: %s\nIdade: %d\nAltura: %.2f", nome);
          }
        fclose(f);
        } else 
          printf("ERROR ao abrir o arquivo!!!");
        break;
      case 3:
        printf("\nNovo nome do arquivo: ");
        scanf("%30[^\n]", file);
        getchar();
        break;
      case 4:
        break;
      default:
        printf("Porfavor digite um valor valido!\n");
    }
  } while(opc != 4);


  return 0;
}
