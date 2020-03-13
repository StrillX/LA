//
// Created by bruno on 11/03/20.
//

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
e-> ultima_jogada.coluna = 4;
e-> ultima_jogada.linha = 4;
return e;
}
