#include<stdio.h>

/* 
                                    Array 2D é uma array que guarda outras arrays dentro de sí.
                nome[Quantidade máxima de arrays][Quantidade máxima de elementos que cada array pode guardar(obrigatorio)]
*/

int main(){
    int num[][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
//  char nomes = {"rodrigo", "roberto", "carlos"} arrays de strings


    for(int x=0; x<sizeof(num)/sizeof(num[x]); x++){
        for(int z=0; z<sizeof(num[x])/sizeof(num[x][0]); z++){
            printf("%3d", num[x][z]);
        }
        printf("\n");
    }

    return 0;
}
