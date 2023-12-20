#include<stdio.h>

void sort(char[], int);
void print_array(char[], int);

int main(){
    char letra[] = {'A', 'B', 'C', 'D', 'E', 'F'}; //Letras também tem valor numérico como mostrado na tabela ascii.
    int num[] = {9,5,7,8,3,1,4,2,6};
    int tam = sizeof(letra)/sizeof(letra[0]);

    sort(letra, tam);
    print_array(letra, tam);

    return 0;
}

void sort(char array[], int size){
    int temp;
    for(int i=0; i<size-1; i++){
        for(int x=0; x<size-i-1; x++){
            if(array[x] > array[x+1]){
                temp = array[x];
                array[x] = array[x+1];
                array[x+1] = temp;
            }
        }
    }
}

void print_array(char array[], int size){
    int temp;
    for(int i=0; i<size; i++){
        temp = array[i];
        printf("%d ", temp);
    }
}