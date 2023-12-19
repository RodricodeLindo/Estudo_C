#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void calculadora(char esc,double a ,double b){
    float res;
    switch(esc){
        case '+':
            res = a + b;
            wprintf(L"O resultado da soma � ");
            printf("%.2f\n", res);
            break;
        case '-':
            res = a - b;
            wprintf(L"O resultado da diferen�a � ");
            printf("%.2f\n", res);
            break;
        case '*':
            res = a * b;
            wprintf(L"O resultado da multriplica��o � ");
            printf("%.2f\n", res);
            break;
        case '/':
            if(a == 0){
                wprintf(L"N�o � poss�vel dividir zero.");
            } else{
            res = a / b;
            wprintf(L"O resultado da divis�o � ");
            printf("%.2f\n", res);
            }
            break;
        default:
            wprintf(L"N�o consigo entender o que voc� pede.\nTente novamente.\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese-Brazilian");
    char esc;
    double a, b;

    wprintf(L"Bem vindo � calculadora de terminal!\n");
    wprintf(L"Qual opera��o deseja realizar hoje?\n");
    scanf("%c", &esc);
    wprintf(L"Por favor digite o primerio n�mero: ");
    scanf("%lf", &a);
    wprintf(L"Agora o segundo: ");
    scanf("%lf", &b);
    printf("\n");

    printf("%.2f\n", a);

    calculadora(esc, a, b);

    system("pause");
    return 0;
}