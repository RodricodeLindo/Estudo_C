#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*
            Modos de abertura de arquivos:
                w -> Write
                r -> Read
                a -> Append
               a+ -> Leitura e escrita (Adiciona ao final do arquivo)
               r+ -> Leitura e escrita
               w+ -> Leitura e escrita (Apaga o conteúdo caso o arquivo exista)
            fputc: File put Char    -> Inseri um char no arquivo.
            fgetc: File get Char    -> Retorna endereço de memória
            fgets: File get String  -> Retorna endereço de memória
            feof : File End Of File -> Indica o fim do arquivo.
            rewind: Reseta o ponteiro do arquivo para o início.
*/

void escrever(char f[]){
  FILE *file = fopen(f, "w");
  char texto[500];
  
  if(file){
    printf("\nDigite uma frase ou somente um character para finalizar.\n");
    scanf("%500[^\n]", texto);
    getchar();
    while(strlen(texto) > 1){
      fputs(texto, file);
      fputc('\n', file);
      scanf("%500[^\n]", texto);
      getchar();
    }
    fclose(file);
  } else
    printf("\nERROR ao abrir arquivo!\n");
}

void ler(char f[]){
  FILE *file = fopen(f, "r");
  char texto[500];

  if(file){
    printf("\n\t\tTexto lido do arquivo\n");
    while(!feof(file)){
      if(fgets(texto, 500, file))// fgets(variável, strMAX, arquivo)
        printf("---> %s", texto);//      ps: 'stdin' é o arquivo onde fica quardado o buffer do teclado.

    }
  fclose(file);
  } else
    printf("\nERRO ao abrir o arquivo!\n");
}

int main(){
  setlocale(LC_ALL, "pt_BR.UTF-8");
  char nome[30];
  printf("\nDigite o nome do arquivo no qual você queira escrever: ");
  scanf("%20[^\n]", nome);
  getchar();
  escrever(nome);
  ler(nome);

  return 0;
}
