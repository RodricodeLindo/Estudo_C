#include<stdio.h>
#include<locale.h>

typedef struct{
    char nome[45];
    int idade;
    float nota;
} estudante;

int main(){
    setlocale(LC_ALL, "portuguese-brazilian");
    estudante aluno0 = {"Rodrigo Gostoso Maravilhoso", 69, 666};
    estudante aluno1 = {"Luiz Inacio Lula da Silva", 77, 13};
    estudante aluno2 = {"Karl Marx", 3, 2.8};
    estudante aluno3 = {"Jair Messias Bolsonaro", 68, -5};
    estudante aluno4 = {"Ana Maria Braga", 74, 8};
    estudante aluno5 = {"Louro O passaro", 18, 10};
    estudante alunos[] = {aluno0, aluno1, aluno2, aluno3, aluno4, aluno5};

    for(int i=0; i<sizeof(alunos)/sizeof(alunos[0]); i++){
        printf("Nome:\t%s\n", alunos[i].nome);
        printf("idade:\t%10d\n", alunos[i].idade);
        printf("Nota Media:\t%.1f\n", alunos[i].nota);
        if(i < sizeof(alunos)/sizeof(alunos[0])-1){
            printf("\n");
        }
    }

    return 0;
}
