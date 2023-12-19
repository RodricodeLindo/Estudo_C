#include<stdio.h>

void decrescente(int x){
    if(x == 0){
        printf("%d\n", x);
    } else{
        decrescente(x - 1);
        printf("%d\n", x);
        }
}
void crescente(int x){
    if(x == 0){
        printf("%d\n", x);
    } else{
        printf("%d\n", x);
        crescente(x - 1);
        }
}

//  Função recursiva funciona como uma pilha, a primeira função lida sera a ultima executada.

int main(){

    crescente(10);
    printf("\n");
    decrescente(10);

    return 0;
}