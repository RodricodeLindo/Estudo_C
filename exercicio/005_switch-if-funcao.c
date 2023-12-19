#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void calculadora(char esc,double a ,double b){
    float res;
    switch(esc){
        case '+':
            res = a + b;
            wprintf(L"O resultado da soma é ");
            printf("%.2f\n", res);
            break;
        case '-':
            res = a - b;
            wprintf(L"O resultado da diferença é ");
            printf("%.2f\n", res);
            break;
        case '*':
            res = a * b;
            wprintf(L"O resultado da multriplicação é ");
            printf("%.2f\n", res);
            break;
        case '/':
            if(a == 0){
                wprintf(L"Não é possível dividir zero.");
            } else{
            res = a / b;
            wprintf(L"O resultado da divisão é ");
            printf("%.2f\n", res);
            }
            break;
        default:
            wprintf(L"Não consigo entender o que você pede.\nTente novamente.\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese-Brazilian");
    char esc;
    double a, b;

    wprintf(L"Bem vindo á calculadora de terminal!\n");
    wprintf(L"Qual operação deseja realizar hoje?\n");
    scanf("%c", &esc);
    wprintf(L"Por favor digite o primerio número: ");
    scanf("%lf", &a);
    wprintf(L"Agora o segundo: ");
    scanf("%lf", &b);
    printf("\n");

    printf("%.2f\n", a);

    calculadora(esc, a, b);

    system("pause");
    return 0;
}