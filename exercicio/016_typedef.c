#include<stdio.h>
#include<string.h>

//typedef char usuario[25];

typedef struct{
    char nome[25];
    char senha[25];
    int id;
} Usuario;

int main(){
    Usuario user1 = {"Rod", "rodrigogostoso", 666};
    Usuario user2 = {"rigo", "osotsogogirdor", 999};

    printf("Nome: %s, ID=%d\n", user1.nome, user1.id);
    printf("Senha: %s\n", user1.senha);

    return 0;
}
