#include "interface.h"
#include "dados.h"
#include "logica.h"
#include <string.h>
#include <stdio.h>
#define BUF_SIZE 1024
void mostra_prompt(ESTADO *e){


    printf("# %d PL%d (%d) > ",e->num_comando,e->jogador_atual,e->num_jogadas);

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

    while(!fim_jogo(e)) {
        char fim [BUF_SIZE];
        char filename[BUF_SIZE];
        char linha[BUF_SIZE];
        char col[2], lin[2];

        if(consulta_jogador(e)==2) e->num_jogadas++;
        mostra_prompt(e);
        e->num_comando++;


        if (fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2) {
            COORDENADA coord = {*col - '1', *lin - 'a'};

            jogar(e, coord);
            mostrar_tabuleiro(e);

        }

        if(sscanf(linha,"gr %s",filename)==1){
            FILE  *fp;
            fp=fopen("%s","w");
            fprintf(fp,"%s");
        }
        if(sscanf(linha,"%c",fim)=='Q'){
            printf("Jogo terminado!");
            return 0;}

    }

    if(casa_final(e,1)!=UM)           printf("Parabens Campeao: Jogador 1");
    else if(casa_final(e,2)!=DOIS)    printf("Parabens Campeao: Jogador 2");

    else{
        atualiza_jogador(e);
        printf("Parabens Campeao: Jogador %d",consulta_jogador(e));
    }
    return 1;
}
