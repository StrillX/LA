#ifndef PROJETOLA_DADOS_H
#define PROJETOLA_DADOS_H

#define BUF_SIZE 1024
    typedef enum {VAZIO, BRANCA, PRETA,UM,DOIS} CASA;
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

void atualiza_estado_casa(ESTADO *e,COORDENADA c, CASA);
void atualiza_ultima(ESTADO *e);
void atualiza_jogador(ESTADO *e);
void muda_pos_ultima(ESTADO *e, COORDENADA c);

int consulta_jogador(ESTADO *e);

CASA consulta_posicao(ESTADO *e, int x, int y);
CASA casa_final(ESTADO *e,int x);
#endif //PROJETOLA_DADOS_H
