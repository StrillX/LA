/**
@file logica.h
Definição das funções que verificam jogadas e jogam
*/
#ifndef PROJETOLA_LOGICA_H
#define PROJETOLA_LOGICA_H

#include "lista.h"

/**
 * \brief Joga numa determinada posição
 * @param e Apontador para o estado
 * @param c Coordenada em que se pretender jogar
 */
int jogar(ESTADO *e, COORDENADA c);
/**
 * \brief Verifica se é possivel jogar numa certa coordenada
 * @param e Apontador para o estado
 * @param c Coordenada em que se pretender jogar
 * @return 1 ou 0, dependendo de ser verdadeiro ou nao
 */
int jogada_valida(ESTADO *e, COORDENADA c);
/**
 * \brief Deteta se o jogo acabou
 * @param e Apontador para o estado
 * @return 1 ou 0, dependendo de ser verdadeiro ou nao
 */
int fim_jogo(ESTADO *e);
/**
 * \brief Deteta se o jogador pode efetuar uma jogada
 * @param e Apontador para o estado
 * @return 1 ou 0, dependendo de ser verdadeiro ou nao
 */
int possivel_jogar(ESTADO *e);
LISTA listagem_de_jogadas(ESTADO *e,LISTA jogadas);
double distancia (COORDENADA c, COORDENADA destino);
#endif //PROJETOLA_LOGICA_H
