#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese-brazilian");
    int idade = 21;
    int *pAidade = NULL;
    pAidade = &idade;

    printf("endere�o da idade: %p\n", &idade);
    printf("endere�o da idade: %p\n", pAidade);
    printf("Valor da idade: %d\n", idade);
    printf("Valor quardado no endre�o: %d", *pAidade);

    return 0;
}