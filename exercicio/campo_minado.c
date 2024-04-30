#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<ctype.h>

int abrir_celula(int x, int y, int campo[10][10], int campov[10][10]){
    for(int z = -1; z < 2; z++)
        for(int v = -1; v < 2; v++)
            if(x-v < 10 && x-v > -1 && y-z < 10 && y-z > -1 && campov[x-v][y-z] == 0){
                campov[x-v][y-z] = 1;
                if(campo[x-v][y-z] == 0){
                    abrir_celula(x-v, y-z, campo, campov);
                }
            }
}
void campo_print(int campo[10][10], int campov[10][10]){
    printf("\n\t\t\tCampo Minado\n\n\t   ");
    for(int x = 97; x < 107; x++)
        printf("  %c ", x);
    printf("\n\t   ");
    for(int x = 0; x < 41; x++)
        printf("-");
    printf("\n\t");
    for(int y = 0; y < 10; y++){
        printf(" %d ", y);
        for(int x = 0; x < 10; x++){
            if(campov[x][y] == 0){
                printf("|   ");
            } else if(campov[x][y] == 1 && campo[x][y] == -1){
                printf("| B ");
            } else{
                printf("| %d ", campo[x][y]);}
            if(x == 9)
                printf("|");
        }
        printf("\n\t   ");
        for(int x = 0; x < 41; x++)
            printf("-");
        printf("\n\t");
        }
}
void campo_minado(){
    srand(time(0));
    int campo[10][10], campov[10][10], bomb = 10 + rand() % 15, temp1, temp2, cont = 0, wro = 0, win = 1, rev = 0;
    char c, l;
    for(int y = 0; y < 10; y++)
        for(int x = 0; x < 10; x++){
            campo[x][y] = 0;
            campov[x][y] = 0;
        }
    for(int x = 0; x < bomb; x++){
        temp1 = rand() % 10;
        temp2 = rand() % 10;
        if(campo[temp1][temp2] != -1)
            campo[temp1][temp2] = -1;
    }
    for(int y = 0; y < 10; y++)
        for(int x = 0; x < 10; x++)
            if(campo[x][y] == -1)
                for(int z = -1; z < 2; z++)
                    for(int v = -1; v < 2; v++)
                        if(x-v < 10 && x-v > -1 && y-z < 10 && y-z > -1)
                            if(campo[x-v][y-z] != -1)
                                campo[x-v][y-z] += 1;
    while(rev < 100-bomb){
        rev = 0;
        campo_print(campo, campov);
        if(!cont)
            printf("\nPara sair digite \'ss\'.");
        if(wro){
            printf("\nVocê digitou uma valor invalido! Por favor preste mais atenção e escreva as coordenadas certas ou \'ss\' para sair.");
            wro = 0;
        }
        printf("\nDigite a linha e a coluna da posição na qual deseje revelar: ");
        scanf("%c %c", &l, &c);
        getchar();
        cont++;
        if(isalpha(c)){
            tolower(c);
            temp2 = c - 97;
        } else
            temp2 = c - 48;
        if(isalpha(l)){
            tolower(l);
            temp1 = l - 97;
        } else
            temp1 = l - 48;
        if(temp1 < 10 && temp1 >= 0 && temp2 < 10 && temp2 >= 0){
            campov[temp2][temp1] = 1;
            if(campo[temp2][temp1] == 0){
                abrir_celula(temp2, temp1, campo, campov);
            } else if(campo[temp2][temp1] == -1){
                win = 0;
                break;
            }
        } else if(l == 's' || c == 's'){
            win = -1;
            break;
        } else
            wro = 1;
        for(int y = 0; y < 10; y++)
            for(int x = 0; x < 10; x++)
                if(campov[x][y] == 1)
                    rev++;
    }
    if(win == 1){
        for(int y = 0; y < 10; y++)
            for(int x = 0; x < 10; x++)
                if(!campov)
                    campov[x][y] = 1;
        campo_print(campo, campov);
        printf("\nParabéns! Você ganhou e eu estou com muita preguisa para fazer algo bonito\nEntão... fica por isso mesmo.\nTchau!");
        printf("\n\nForam feitas %d rodadas até você ganhar.\n", cont);
        printf("\nPressione qualquer tecla para continuar. . .");
        getchar();
    } else if(win == 0){
        for(int y = 0; y < 10; y++)
            for(int x = 0; x < 10; x++)
                if(campo[x][y] == -1 && campov[x][y] == 0)
                    campov[x][y] = 1;
        campo_print(campo, campov);
        printf("\nParabens! Você perdeu.\n\nForam %d rodadas para você perder.\n");
        printf("\nPressione qualquer tecla para continuar. . .");
        getchar();
    }
}

int main(){
    setlocale(LC_ALL, "portuguese-brazilian");
    campo_minado();
    return 0;
}
