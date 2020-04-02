/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef PROJETOLA_DADOS_H
#define PROJETOLA_DADOS_H

#include <bits/types/FILE.h>

#define BUF_SIZE 1024
/**
\brief Tipo de dados para a casa
*/
    typedef enum {VAZIO='.', BRANCA='*', PRETA='#',UM='1',DOIS='2'} CASA;
/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];
/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** A coordenada da última jogada */
    COORDENADA ultima_jogada;
    /** As jogadas */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
    /** O nº de comando, usado no prompt */
    int num_comando;
} ESTADO;

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();
/**
\brief Muda o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@param cor O novo valor para a casa
*/
void atualiza_estado_casa(ESTADO *e,COORDENADA c, CASA cor);
/**
 * \brief Muda o estado da da ultima posiçao para PRETA
 * @param e Apontador para o estado
 */

void atualiza_ultima(ESTADO *e);
/**
 * \brief Altera de um jogador para o outro
 * @param e Apontador para o estado
 */
void atualiza_jogador(ESTADO *e);
/**
 * \brief Muda a coordenada da da ultima posiçao para a posiçao atual
 * @param e
 */
void muda_pos_ultima(ESTADO *e, COORDENADA c);
/**
 \brief Devolve o Jogador atual
 @param e Apontador para o estado
 */
int consulta_jogador(ESTADO *e);
/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param x e @param y  sao as coordenadas
@returns O valor da casa
*/
CASA consulta_posicao(ESTADO *e, int x, int y);
/**
 * \brief Deteta se o estado com a casa 1 ou 2 é alterado
 * @param e Apontador para o estado
 * @param x determina se é a casa com 1 ou 2 a ser analisada
 * @return O estado atual da casa 1 ou 2
 */
CASA casa_final(ESTADO *e,int x);
/**
 * /brief Atualiza as jogadas
 * @param e indicador para o estado
 * @param c A coordenada
 */
void atualiza_jogadas(ESTADO *e,COORDENADA c);
#endif //PROJETOLA_DADOS_H
