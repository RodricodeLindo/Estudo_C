#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese-brazilian");
    int idade = 21;
    int *pAidade = NULL;
    pAidade = &idade;

    printf("endereço da idade: %p\n", &idade);
    printf("endereço da idade: %p\n", pAidade);
    printf("Valor da idade: %d\n", idade);
    printf("Valor quardado no endreço: %d", *pAidade);

    return 0;
}