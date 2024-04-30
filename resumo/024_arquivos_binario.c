#include<stdio.h>

/*
            Modos de abertura de arquivos:
                wb -> Write
                rb -> Read
                ab -> Append
                ab+ -> Leitura e escrita (Adiciona ao final do arquivo)
                rb+ -> Leitura e escrita
                wb+ -> Leitura e escrita (Apaga o conteúdo caso o arquivo exista)
*/

typedef struct{
  char nome[50];
  int dia, mes, ano;
}contato;

void escrever(char arq[]){
  contato c;
  FILE *file = fopen(arq, "ab");

  if(file){
    printf("Digite o nome e a data de nascimento dd mm aaaa: ");
    scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
    fwrite(&c, sizeof(contato), 1, file);
    fclose(file);
  } else
    printf("\nErro ao abrir arquivo!\n");
}

void ler(char arq[]){
  contato c;
  FILE *file = fopen(arq, "rb");

  if(file){
    while(!feof(file)){
      if(fread(&c, sizeof(contato), 1, file))
        printf("Nome: %s\nData %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
    }
    fclose(file);
  } else
      printf("\nErro ao abrir arquivo!!\n");
}


int main(){
  char arquivo[] = {"agenda.dat"};

  escrever(arquivo);
  ler(arquivo);

  return 0;
}
