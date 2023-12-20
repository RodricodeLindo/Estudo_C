#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void torre(int, int, char);

int main(){
    setlocale(LC_ALL, "Portuguese-Brazilian");
    int lar, alt;
    char simbolo;

    printf("Digite a largura: ");
    scanf("%d", &lar);
    printf("Digite a altura: ");
    scanf("%d", &alt);
    scanf("%c");
    printf("Qual simbolo: ");
    scanf("%c", &simbolo);

    system("cls");
    torre(lar, alt, simbolo);
    system("pause");

    return 0;
}

void torre(int largura, int altura, char simbolo){
    for(int x=0; x < altura; x++){
        for(int z=0; z < largura; z++){
            printf("%c", simbolo);
        }
        printf("\n");
    }
}
