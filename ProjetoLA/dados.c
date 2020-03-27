/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#include "dados.h"
#include <stdlib.h>
#include <string.h>

ESTADO *inicializar_estado() {

    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    COORDENADA coord = {-1,-1};
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_comando = 1;
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
    for(int i=0;i<32;i++){
        e->jogadas[i].jogador1 = coord;
        e->jogadas[i].jogador2 = coord;
    }
    return e;
}
//! Atualiza o estado de uma casa para uma cor determinada.
void atualiza_estado_casa(ESTADO *e, COORDENADA c,CASA cor){
    e->tab[c.coluna] [c.linha] = cor;

}
