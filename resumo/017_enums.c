#include<stdio.h>

enum Dia{Seg=1, Ter=2, Quar=3, Quin=4, Sex=5, Sab=6, Dom=7};

int main(){
    enum Dia hoje = Seg;

    printf("%d", hoje); //enums N�O s�o strings, mas podem ser tratados como int. nnm

    return 0;
}
