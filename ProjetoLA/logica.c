//
// Created by bruno on 11/03/20.
//
#include "dados.h"
#include "logica.h"
#include <stdio.h>
int jogar(ESTADO *e, COORDENADA c) {
    e-> tab [c.linha] [c.coluna] = BRANCA;
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
}