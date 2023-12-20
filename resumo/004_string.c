#include<stdio.h>
#include<string.h> //Funções com string
#include<locale.h>

//                                      String não e nada mais do que um arrays de char

int main(){
    setlocale(LC_ALL, "Portuguese-Brazilian");

    char nome[25];
    char string1[] = "Rodrigo";
    char string2[] = "Alves";
    int idade;

    //strlwr(string1)                             // Transfoma as letras em minúsculo.
    //strupr(string1)                             // Transfoma as letras em maiúsculo.
    //strcat(string1, string2)                    // Vai juntar duas strings em uma.
    //strncat(string1, string2, 3)                // Vai juntar as letras da string2 para a string1 até uma quantidade igual à especificada.
    //strcpy(string1, string2)                    // Cópia a string1 para a string2.
    //strncpy(string1, string2, 1)                // Cópia um certa quantidade de caracteres da string1 para a string2 igual à especificada.
    //strspn(string1, string2)                    // Esta função retorna o número de caracteres percorridos em string_1 antes de qualquer caractere correspondente a string_2.
    //strtol(string, raio) (stdlib.h)             // Converte uma string para long.

    //strset(string1, '?')                        // Muda todos caracteres da string1 para a letra especificada.
    //strnset(string1, 'x', 1)                    // Muda os caracteres até uma certa quantidade para a letra escolhida.
    //strrev(string1)                             // Inverter a palavra.

    //int result = strlen(string1)                // Retornar o comprimento da string como um inteiro.
    //int result = strcmp(string1, string2)       // Compara as duas strings. (Ignora minusculo e maiusculo)
    //int result = strncmp(string1, string2, 2)   // Comça a comparar as strings a partir da posição escolhida. (Ignora minúsculo e maiúsculo)

    //char *result = strtok(string1, string2)     // Dividi a string1 em tokens separando com string2. Isso irá destruir a string original.
    //char *result = strchr(string, char)         // Retorna a primeira ocorrência.
    //char *result = strrchr(string, char)        // Retorna a última ocorrência.
    //char *result = strstr(string1, string2)     // Ela procura na string principal(strin1) uma substring(string2) e retorna a primeira letra.

    printf("%s\n", string1);

/*
    if(result == 0){
        wprintf(L"São as mesmas strings\n");
    } else {
        wprintf(L"Não são as mesmas strings\n");
    }
*/

    printf("Qual é o seu nome?\n");
    fgets(nome, 25, stdin);
    nome[strlen(nome)-1] = '\0';//Strlen conta quantos números tem uma carateres tem uma string. Ele tá pegando a ultima posição da string e mudando o valor para null(\0).
    printf("Quantos anos você tem?\n");
    scanf("%d", &idade);
    printf("ola ser humano cujo nome e %s e possue %d anos.\n", nome, idade);

    return 0;
}