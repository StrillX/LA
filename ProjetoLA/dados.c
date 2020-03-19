#include "dados.h"
#include <stdlib.h>
#include <string.h>

ESTADO *inicializar_estado() {

    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    for(int i=0;i<8;i++){
        for(int j = 0 ; j<8; j++){
            e-> tab [i] [j] = VAZIO;
        }
    }
    e-> tab [4] [4] = BRANCA;
    e-> tab [7] [7] = DOIS;
    e-> tab [0] [0] = UM;
    e-> ultima_jogada.coluna = 4;
    e-> ultima_jogada.linha = 4;
    return e;
}

void atualiza_estado_casa(ESTADO *e, COORDENADA c,CASA cor){
    e->tab[c.linha] [c.coluna] = cor;
}
CASA consulta_posicao(ESTADO *e, int x , int y){
    return e->tab [x] [y];
}
void atualiza_ultima(ESTADO *e){
    atualiza_estado_casa(e,e->ultima_jogada,PRETA);
}
void atualiza_jogador(ESTADO *e){
    if(e->jogador_atual==1)e->jogador_atual=2;
    else (e->jogador_atual=1);
}
int consulta_jogador(ESTADO *e){
    if(e->jogador_atual==1)return 1;
    else return 2;
}


void muda_pos_ultima(ESTADO *e, COORDENADA c){
    e->ultima_jogada.coluna= c.coluna;
    e->ultima_jogada.linha = c.linha;
}
CASA casa_final(ESTADO *e,int x){
    if(x==1&&consulta_posicao(e,0,0)==BRANCA) return BRANCA;
    if(x==2&&consulta_posicao(e,7,7)==BRANCA) return BRANCA;

}
