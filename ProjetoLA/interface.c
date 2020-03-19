
#include "interface.h"
#include "dados.h"
#include "logica.h"
#include <string.h>
#include <stdio.h>
#define BUF_SIZE 1024
void mostra_prompt(ESTADO *e,int ac, int jogada, int jogador){


    printf("# %d PL%d (%d) > ",ac,jogador,jogada);

}
void mostrar_tabuleiro(ESTADO *e) {
    for(int i = 7 ; i >= 0 ; i--){
        printf("%d ",i+1);
        for(int j = 0; j < 8 ; j++){
            
                if( consulta_posicao(e,i,j) == VAZIO){
                    printf(".");
                }
                else if(consulta_posicao(e,i,j) == BRANCA){
                    printf("*");
                }
                else if(consulta_posicao(e,i,j)==PRETA){
                    printf("#");
                }
                else if(consulta_posicao(e,i,j)==UM){
                    printf("1");
                }
                else printf("2");

        }
        printf("\n");
    }
    printf("  abcdefgh\n");
}

int interpretador(ESTADO *e) {
    int ac=01;
    int jogada = 0;
    while(!fim_jogo(e)) {
        char linha[BUF_SIZE];
        char col[2], lin[2];




        int jogador = consulta_jogador(e);
        if(consulta_jogador(e)==2) jogada++;
        mostra_prompt(e,ac,jogada,jogador);
        ac++;


        if (fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};

            jogar(e, coord);
            mostrar_tabuleiro(e);

        }


    }
    if(casa_final(e,1)!=UM)           printf("Parabens Campeao: Jogador 1");
    else if(casa_final(e,2)!=DOIS)    printf("Parabens Campeao: Jogador 2");
    else printf("Parabens Campeao: Jogador %d",consulta_jogador(e));
    return 1;
}
