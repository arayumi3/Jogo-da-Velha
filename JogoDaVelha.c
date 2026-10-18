#include <stdio.h>
#include <stdlib.h>

void tab(char tabuleiro_Jogo[3][3]) {
   printf("\tJogo da Velha\n\n");
   printf("\t %c | %c | %c\n", tabuleiro_Jogo[0][0], tabuleiro_Jogo[0][1], tabuleiro_Jogo[0][2]);
   printf("\t-----------\n");
   printf("\t %c | %c | %c\n", tabuleiro_Jogo[1][0], tabuleiro_Jogo[1][1], tabuleiro_Jogo[1][2]);
   printf("\t-----------\n");
   printf("\t %c | %c | %c\n", tabuleiro_Jogo[2][0], tabuleiro_Jogo[2][1], tabuleiro_Jogo[2][2]);
}

int main() {
    char tabuleiro_Jogo[3][3];
    char respostas[10]; 
    int cont_jogadaS;
    int vez = 0;
    int i;
    int tab_Jogada; 

    do {
        cont_jogadaS = 1;

        for (i = 0; i < 3; i++) {  
            for (int j = 0; j < 3; j++) {  
                tabuleiro_Jogo[i][j] = ' ';
            }
        }

        do {
            tab(tabuleiro_Jogo);


            printf("\nJogador %d, digite uma casa de 1 a 9:\n", vez % 2 == 0 ? 1 : 2);

            scanf("%i", &tab_Jogada);
            
            if (tab_Jogada == 0) {  
                printf("Posicao invalida. Jogue novamente.\n");
            }

            if (tab_Jogada < 1 || tab_Jogada > 9) {
                tab_Jogada = 0;
                continue;
            } else {
                int linha = (tab_Jogada - 1) / 3;
                int coluna = (tab_Jogada - 1) % 3;
                if (tabuleiro_Jogo[linha][coluna] != ' ') {
                    tab_Jogada = 0;
                    printf("\nPosicao ja preenchida. Tente novamente.\n\n");
                } else {
                    if (vez % 2 == 0) {
                        tabuleiro_Jogo[linha][coluna] = 'X';
                    } else {
                        tabuleiro_Jogo[linha][coluna] = 'O';
                    }

                    cont_jogadaS++;
                    vez++;
                }
            }

            
            if(tabuleiro_Jogo[0][0] == 'X' && tabuleiro_Jogo[0][1] == 'X' && tabuleiro_Jogo[0][2] == 'X') {cont_jogadaS = 11;}
            if(tabuleiro_Jogo[1][0] == 'X' && tabuleiro_Jogo[1][1] == 'X' && tabuleiro_Jogo[1][2] == 'X') {cont_jogadaS = 11;}
            if(tabuleiro_Jogo[2][0] == 'X' && tabuleiro_Jogo[2][1] == 'X' && tabuleiro_Jogo[2][2] == 'X') {cont_jogadaS = 11;}
            if(tabuleiro_Jogo[0][0] == 'X' && tabuleiro_Jogo[1][0] == 'X' && tabuleiro_Jogo[2][0] == 'X') {cont_jogadaS = 11;}
            if(tabuleiro_Jogo[0][1] == 'X' && tabuleiro_Jogo[1][1] == 'X' && tabuleiro_Jogo[2][1] == 'X') {cont_jogadaS = 11;}
            if(tabuleiro_Jogo[0][2] == 'X' && tabuleiro_Jogo[1][2] == 'X' && tabuleiro_Jogo[2][2] == 'X') {cont_jogadaS = 11;}
            if(tabuleiro_Jogo[0][0] == 'X' && tabuleiro_Jogo[1][1] == 'X' && tabuleiro_Jogo[2][2] == 'X') {cont_jogadaS = 11;}
            if(tabuleiro_Jogo[0][2] == 'X' && tabuleiro_Jogo[1][1] == 'X' && tabuleiro_Jogo[2][0] == 'X') {cont_jogadaS = 11;}

            if(tabuleiro_Jogo[0][0] == 'O' && tabuleiro_Jogo[0][1] == 'O' && tabuleiro_Jogo[0][2] == 'O') {cont_jogadaS = 12;}
            if(tabuleiro_Jogo[1][0] == 'O' && tabuleiro_Jogo[1][1] == 'O' && tabuleiro_Jogo[1][2] == 'O') {cont_jogadaS = 12;}
            if(tabuleiro_Jogo[2][0] == 'O' && tabuleiro_Jogo[2][1] == 'O' && tabuleiro_Jogo[2][2] == 'O') {cont_jogadaS = 12;}
            if(tabuleiro_Jogo[0][0] == 'O' && tabuleiro_Jogo[1][0] == 'O' && tabuleiro_Jogo[2][0] == 'O') {cont_jogadaS = 12;}
            if(tabuleiro_Jogo[0][1] == 'O' && tabuleiro_Jogo[1][1] == 'O' && tabuleiro_Jogo[2][1] == 'O') {cont_jogadaS = 12;}
            if(tabuleiro_Jogo[0][2] == 'O' && tabuleiro_Jogo[1][2] == 'O' && tabuleiro_Jogo[2][2] == 'O') {cont_jogadaS = 12;}
            if(tabuleiro_Jogo[0][0] == 'O' && tabuleiro_Jogo[1][1] == 'O' && tabuleiro_Jogo[2][2] == 'O') {cont_jogadaS = 12;}
            if(tabuleiro_Jogo[0][2] == 'O' && tabuleiro_Jogo[1][1] == 'O' && tabuleiro_Jogo[2][0] == 'O') {cont_jogadaS = 12;}

        } while (cont_jogadaS <= 9); 

        tab(tabuleiro_Jogo);
    
         if (cont_jogadaS == 11) {
            printf("Jogador 1 venceu\n");
        }else if (cont_jogadaS == 12) {
            printf("Jogador 2 venceu\n");
        }else if (cont_jogadaS == 10) {
            printf("Empate!\n");
        } 

        printf("\nJOGAR NOVAMENTE? (SIM ou NAO): ");
        while (getchar() != '\n');
        scanf("%s", respostas);

    } while (respostas[0] == 's' || respostas[0] == 'S');
      if (respostas[0] == 'n' || respostas[0] == 'N'){
	  printf("\nObrigado por jogar!\n");
    }
    return 0;
}

