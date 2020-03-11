//
// Created by bruno on 11/03/20.
//

#ifndef PROJETOLA_DADOS_H
#define PROJETOLA_DADOS_H

#define BUF_SIZE 1024
typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;
ESTADO *inicializar_estado();
#endif //PROJETOLA_DADOS_H
