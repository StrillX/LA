//
// Created by bruno on 11/03/20.
//
#include "dados.h"
#include "logica.h"
#include <stdio.h>
int jogar(ESTADO *e, COORDENADA c) {
    atualiza_estado_casa(e,c,BRANCA);
    atualiza_ultima(e);
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
}
