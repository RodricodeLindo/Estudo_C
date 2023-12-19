#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese-Brazilian");
    for(int i=0; i <= 20; i+=2){
        printf("%d\n", i);
    }

    char nome[25];
    char name[25];
    int number=0, sum=0;

    printf("Digite o seu nome: ");

    fgets(nome, 25, stdin);
    nome[strlen(nome)-1] = '\0';

    while(strlen(nome) == 0){
        printf("Digite o seu nome: ");
        fgets(nome, 25, stdin);
        nome[strlen(nome)-1] = '\0';
    }

    printf("%s", nome);

    do{
        printf("Enter a # above 0: ");
        scanf("%d", &number);
        if(number > 0)
        {
            sum += number;
        }
    }while(number > 0);

    printf("sum: %d", sum);
   
    return 0;
}
