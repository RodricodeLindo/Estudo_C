#include<stdio.h>
#include<string.h> //Fun��es com string
#include<locale.h>

//                                      String n�o e nada mais do que um arrays de char

int main(){
    setlocale(LC_ALL, "Portuguese-Brazilian");

    char nome[25];
    char string1[] = "Rodrigo";
    char string2[] = "Alves";
    int idade;

    //strlwr(string1)                             // Transfoma as letras em min�sculo.
    //strupr(string1)                             // Transfoma as letras em mai�sculo.
    //strcat(string1, string2)                    // Vai juntar duas strings em uma.
    //strncat(string1, string2, 3)                // Vai juntar as letras da string2 para a string1 at� uma quantidade igual � especificada.
    //strcpy(string1, string2)                    // C�pia a string1 para a string2.
    //strncpy(string1, string2, 1)                // C�pia um certa quantidade de caracteres da string1 para a string2 igual � especificada.
    //strspn(string1, string2)                    // Esta fun��o retorna o n�mero de caracteres percorridos em string_1 antes de qualquer caractere correspondente a string_2.
    //strtol(string, raio) (stdlib.h)             // Converte uma string para long.

    //strset(string1, '?')                        // Muda todos caracteres da string1 para a letra especificada.
    //strnset(string1, 'x', 1)                    // Muda os caracteres at� uma certa quantidade para a letra escolhida.
    //strrev(string1)                             // Inverter a palavra.

    //int result = strlen(string1)                // Retornar o comprimento da string como um inteiro.
    //int result = strcmp(string1, string2)       // Compara as duas strings. (Ignora minusculo e maiusculo)
    //int result = strncmp(string1, string2, 2)   // Com�a a comparar as strings a partir da posi��o escolhida. (Ignora min�sculo e mai�sculo)

    //char *result = strtok(string1, string2)     // Dividi a string1 em tokens separando com string2. Isso ir� destruir a string original.
    //char *result = strchr(string, char)         // Retorna a primeira ocorr�ncia.
    //char *result = strrchr(string, char)        // Retorna a �ltima ocorr�ncia.
    //char *result = strstr(string1, string2)     // Ela procura na string principal(strin1) uma substring(string2) e retorna a primeira letra.

    printf("%s\n", string1);

/*
    if(result == 0){
        wprintf(L"S�o as mesmas strings\n");
    } else {
        wprintf(L"N�o s�o as mesmas strings\n");
    }
*/

    printf("Qual � o seu nome?\n");
    fgets(nome, 25, stdin);
    nome[strlen(nome)-1] = '\0';//Strlen conta quantos n�meros tem uma carateres tem uma string. Ele t� pegando a ultima posi��o da string e mudando o valor para null(\0).
    printf("Quantos anos voc� tem?\n");
    scanf("%d", &idade);
    printf("ola ser humano cujo nome e %s e possue %d anos.\n", nome, idade);

    return 0;
}