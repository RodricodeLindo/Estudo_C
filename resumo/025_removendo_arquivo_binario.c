#include <stdio.h>
#include <stdlib.h>

int main(){

    // nome do arquivo
    char nome[] = {"agenda.txt"};

    // tenta abrir o arquivo para escrita
    FILE *file = fopen(nome, "w");

    if(file){
        printf("\nArquivo aberto com sucesso!\n");
        fclose(file);

        // tenta remover o arquivo agenda.txt
        printf("\nRetorno: %d\n", remove(nome));
    }
    else{
        printf("\nErro ao abrir o arquivo!\n");

        // Ao tentar remover um arquivo que não existe a função retorna o valor -1
        printf("\nRetorno: %d\n", remove(nome));
    }

    return 0;
}
