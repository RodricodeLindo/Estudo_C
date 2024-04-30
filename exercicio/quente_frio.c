#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<math.h>

int main(){
    setlocale(LC_ALL, "portuguese-brazilian");
    srand(time(0));

    int num = (rand() % 15) + 1, vida = 5;
    int player;

    printf("======================================================================\n");
    printf("  _   _                 _\n");
    printf(" | \\ | |               | |\n");
    printf(" |  \\| |_   _ _ __ ___ | |__   ___ _ __    __ _  __ _ _ __ ___   ___\n");
    printf(" | . ` | | | | '_ ` _ \\| '_ \\ / _ \\ '__|  / _` |/ _` | '_ ` _ \\ / _ \\\n");
    printf(" | |\\  | |_| | | | | | | |_) |  __/ |    | (_| | (_| | | | | | |  __/\n");
    printf(" |_| \\_|\\__,_|_| |_| |_|_.__/ \\___|_|     \\__, |\\__,_|_| |_| |_|\\___|\n");
    printf("                                           __/ |\n");
    printf("                                          |___/\n");
    printf("======================================================================\n");
    printf("Bem vindo à esse pequeno jogo de adivinhar numeros!!!\n\n");
    printf("Nós já temos um número soteado para você.\n");
    printf("Sé o número que você digitou estiver perto do número sorteado,\n");
    printf("falaremos se estar quente ou frio.\n\n");
    printf("Quando quiser sair digite zero.\n\n\n\n\n\n");

    while(1){
        printf("\n(Vida: %d)\n", vida);
        printf("Tente advinhar o número. (1 á 15): ");
        scanf("%d", &player);
        vida--;
        if(player == num){
            system("clear");
            printf("  _____  _____            ____    __  _   _  _____\n");
            printf(" |  __ \\|  __ \\     /\\   |  _ \\ _/_/_| \\ | |/ ____|\n");
            printf(" | |__) | |__) |   /  \\  | |_) | ____|  \\| | (___\n");
            printf(" |  ___/|  _  /   / /\\ \\ |  _ <|  _| | . ` |\\___ \\ \n");
            printf(" | |    | | \\ \\  / ____ \\| |_) | |___| |\\  |____) |\n");
            printf(" |_|    |_|  \\_\\/_/    \\_\\____/|_____|_| \\_|_____/\n\n\n\n\n");
            printf("Parabéns! Você acertou o número sorteado(");
            printf("%d", num);
            printf(").\nComo recompensa, você não vai ganhar nada!!!\n");
            break;
        } else if(vida <= 0){
            system("cls");
            printf("Perdeu! é uma pena.\nO número correto é ");
            printf("%d\n", num);
            printf("\nTente novamente.\n");
            break;
        } else if(player <= 0){
            break;
        } else if(player > 15){
            printf("O número não está entre 1 e 15.\nTente novamente.\n");
            vida++;
        } else if(fabs(player-num) >= 8 && player > 0){
            printf("FRIO\n");
        } else if(fabs(player-num) >= 5 && fabs(player-num) < 8){
            printf("QUENTE\n");
        } else if(fabs(player-num) >= 1 && fabs(player-num) <5){
            printf("MUITO QUENTE\n");
        }
    }
    printf("Pressione qualquer tecla para terminar o programa. . .");
    scanf("%c");
    getchar();

    return 0;
}
