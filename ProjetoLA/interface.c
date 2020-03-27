

#include "interface.h"
#include "dados.h"
#include "logica.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024
void mostra_prompt(ESTADO *e){

    if(e->num_jogadas<10)
        printf("# 0%d PL%d (%d) > ",e->num_comando,e->jogador_atual,e->num_jogadas);

    else
        printf("# %d PL%d (%d) > ",e->num_comando,e->jogador_atual,e->num_jogadas);

}
void mostrar_tabuleiro(ESTADO *e, FILE *destino) {
    for(int i = 7 ; i >= 0 ; i--){
        printf("%d ",i+1);
        for(int j = 0; j < 8 ; j++){
            
                if( consulta_posicao(e,i,j) == VAZIO){
                    fprintf(destino,".");
                }
                else if(consulta_posicao(e,i,j) == BRANCA){
                    fprintf(destino,"*");
                }
                else if(consulta_posicao(e,i,j)==PRETA){
                    fprintf(destino,"#");
                }
                else if(consulta_posicao(e,i,j)==UM){
                    fprintf(destino,"1");
                }
                else fprintf(destino,"2");

        }
        fprintf(destino,"\n");
    }
    printf("  abcdefgh\n");
}

int interpretador(ESTADO *e) {
    int fim=0;
    char q;
    char mov[]= "movs";
    char conteudo[BUF_SIZE];
    while(!fim_jogo(e)) {

        char filename[BUF_SIZE];
        char linha[BUF_SIZE];
        char col[2], lin[2];


        mostra_prompt(e);
        e->num_comando++;


        if (fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2) {
            COORDENADA coord = {*col - '1', *lin - 'a'};

            jogar(e, coord);

            mostrar_tabuleiro(e,stdout);

        }

        else if(sscanf(linha,"gr %s",filename)==1){
            guardar(filename,e);
            mostrar_tabuleiro(e,stdout);



        }
        else if(sscanf(linha,"ler %s",filename)==1){
            ler(filename,e);
            mostrar_tabuleiro(e,stdout);
        }
        else if(sscanf(linha,"%s",conteudo)){
            if(strcmp(conteudo,mov)==0){
                movs(e,stdout);
            }
        }
        else if(sscanf(linha,"%c",&q)==1) {
            if (q == 'Q') {
                fim = 1;
                break;
            }
        }


    }
    if(fim==1) return 0;
    if(casa_final(e,1)!=UM)           printf("Parabens Campeao: Jogador 1");
    else if(casa_final(e,2)!=DOIS)    printf("Parabens Campeao: Jogador 2");

    else{
        atualiza_jogador(e);
        printf("Parabens Campeao: Jogador %d",consulta_jogador(e));
    }
    return 0;
}
void guardar(char *file,ESTADO *e){
    FILE *tabuleiroescrever;
    tabuleiroescrever=fopen(file,"w");
    mostrar_tabuleiro(e,tabuleiroescrever);
    fprintf(tabuleiroescrever," ");
    fprintf(tabuleiroescrever,"\n");
    movs(e,tabuleiroescrever);
    fclose(tabuleiroescrever);
}
void ler(char *file,ESTADO *e){
    FILE *tabuleiroler;
    tabuleiroler=fopen(file,"r");
    char buffer[BUF_SIZE];
    int l = 7;
    COORDENADA ultima;
    int jogadas_atual = 0;
    while(fgets(buffer, BUF_SIZE, tabuleiroler) != NULL) {

        for(int c = 0; c < 8; c++){
            COORDENADA coord = {l, c};
            atualiza_estado_casa(e, coord, buffer[c]);
            if(buffer[c]== '#')jogadas_atual++;
            if(consulta_posicao(e,l,c)==BRANCA){ ultima.coluna = l; ultima.linha = c;}
        }
        l--;

    }
    if(jogadas_atual%2==0)e->jogador_atual=1;
    else e->jogador_atual=2;

    if(ultima.coluna==-1)ultima.coluna=0;
    e->num_jogadas=jogadas_atual/2;
    muda_pos_ultima(e,ultima);
    fclose(tabuleiroler);

}
void movs(ESTADO *e,FILE * destino){
    COORDENADA coor = {-1,-1};
    for(int i = 0; i < 32; i++) {

            if (e->jogadas[i].jogador2.linha==coor.linha&&e->jogadas[i].jogador2.coluna==coor.coluna&&e->jogadas[i].jogador1.linha!=coor.linha&&e->jogadas[i].jogador1.coluna!=coor.coluna){
                fprintf(destino, "%02d: %c%d\n",i+1,e->jogadas[i].jogador1.linha+'a',e->jogadas[i].jogador1.coluna+1);
            }
            else if(e->jogadas[i].jogador2.linha!=coor.linha&&e->jogadas[i].jogador2.coluna!=coor.coluna&&e->jogadas[i].jogador1.linha!=coor.linha&&e->jogadas[i].jogador1.coluna!=coor.coluna){
                fprintf(destino, "%02d: %c%d %c%d\n",i+1,e->jogadas[i].jogador1.linha+'a',e->jogadas[i].jogador1.coluna+1,e->jogadas[i].jogador2.linha+'a',e->jogadas[i].jogador2.coluna+1);
            }
            else break;

    }
}
