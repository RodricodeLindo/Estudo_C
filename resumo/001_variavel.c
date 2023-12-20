#include<stdio.h>
#include<stdbool.h>// Biblioteca pool
#include<locale.h>

/*
        format specifier % = defines and formats a type of data to be displayed

        %c = character
        %s = string (array of characters) 
        %f = float
        %lf = long float (double)
        %d = integer

        %.1 = decimal precision
        %1 = minimum field width
        %- = left align
*/

const float pi = 3.14159;//Constante

int main(){
    setlocale(LC_ALL, "Portuguese-Brazilian");

    float a;
    int num = 5;// -2,174,483,648 a 2,147,483,647; 4 bytes.
    long long int longo = 9000000000000000099;// -9 quintilh�o a 9 quintilh�o; %lld; 8 bytes.
    unsigned long long int gran = 18000000000000000099U;// 0 a 18 quitilh�o; %llu; 8bytes.
    unsigned unnum = 4000000;// 4,294,967,295; %u.
    short int shin = 32780;// -32,768 a 32,767. caso ultrapasse os limites ele vai guardar o m�nimo que ele pode; %d; 2 bytes.
    unsigned short unshin = 65535;// 0 a 65,535; %d; 2 bytes.

    float numque = 20.3333333; // Float suporta at� 6 - 7 casas decimais. (32 bits de precis�o) 4 bytes.
    double numque2 = 51.44444444444444; // Double consegue suportar 15 - 16 casas decimais. (64 bits de precis�o) 8 bytes.

    char letra = 'b';// letras e numeros (-128 a 127) 1 bytes.
    signed char lenum = 120;// Por padr�o a maioria dos data types j� s�o signed. 1 bytes
    char string[] = "Rodrigo";//%s; 1 bytes.
    unsigned char uncha = 50;// 0 a 255, se ultrapassar esse limite ele retorna 0(fecha o programa e da error).

    bool tf = true; // true = 1 e false = 0; 1 bytes.

    /*ops: N�o precisar escrever "short int" s� short serve.
    Se usar "long long int" porque o int j� possue um long invis�vel.*/

    printf("int %d\n",num);
    printf("short int %d\n",shin);
    printf("unsigned short int %d\n",unshin);
    printf("unsigned int %u\n",unnum);
    printf("long long int %lld\n",longo);
    printf("unsigned long long int %llu\n\n",gran);
    printf("float %0.3f\n",numque);
    printf("double %0.8lf\n\n",numque2);
    printf("char %c\n",letra);
    printf("char com numeros %d\n", lenum);
    printf("unsigned char com numeros %d\n",uncha);
    printf("char %s\n\n",string);
    printf("bool %d\n",tf);

    printf("\nDigite um n�mero quebrado: ");
    scanf("%f", &a);
    scanf("%c");
    printf("\n\'%-8.2f\'\n\n",a);
    printf("Ops! O n�mero do pi � %f(\u03C0)\n\n",pi);

    printf("Pressione qualquer tecla para finalizar...");
    getchar();
    return 0;
}
//vari�veis, tipos de data e especifica��o de formata��o.