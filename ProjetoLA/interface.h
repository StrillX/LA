/**
@file interface.h
Definição das funções que mostram ao utilizador o essencial para este poder jogar
*/
#include "dados.h"
#ifndef PROJETOLA_INTERFACE_H
#define PROJETOLA_INTERFACE_H
/**
 * \brief Apresenta o tabuleiro para o utilizador
 * @param e Apontador para o estado
 * @param destino Onde vai ser impresso o tabuleiro
 */
void mostrar_tabuleiro(ESTADO *e,FILE *destino);
/**
 * \brief interpreta os comandos do utilizador
 * @param e Apontador para o estado
 */
int  interpretador    (ESTADO *e);
/**
 * \brief Apresenta um painel com informaçoes basicas para o utilizador
 * @param e Apontador para o estado
 */
void mostra_prompt(ESTADO *e);
/**
 * \brief Guarda um tabuleiro num ficheiro
 * @param file ficheiro onde sera guardado o tabuleiro
 * @param e Apontador para o estado
 */
void guardar(char *file,ESTADO *e);
/**
 * \brief Copia o conteudo de um ficheiro e interpreta-o
 * @param linhas Linha onde se situa
 * @param coord_y   Posiçao na linha
 * @param e Apontador para o estado
 */
void convertelinha(char *linhas,int coord_y,ESTADO *e);
/**
 * \brief Le um ficheiro
 * @param file O nome do ficheiro
 */
ESTADO *ler(char *file);
/**
 * \brief Mostra os movimentos
 * @param e Apontador para o estado
 * @param destino Onde vai ser impresso a lista de movimentos
 */
void movs(ESTADO *e,FILE * destino);
/**
 * \brief Insere movimentos tendo em conta o jogador atual
 * @param e Apontador para o estado
 * @param c Coordenada
 * @param posicao Posição do jogador
 * @param jogador Jogador atual
 */
void inseremovs(ESTADO *e,COORDENADA c,int posicao,int jogador);
/**
 * \brief Retorna o tabulerio para uma jogada anterior
 * @param e Apontador para o estado
 * @param njogada o numero da jogada para a qual se pretende retornar
 * @return Retorna o estado do tabulerio nessa jogada
 */
ESTADO pos (ESTADO *e, int njogada);
/**
\brief Joga pelo jogador-Aleatorio
@param e Apontador para o estado
*/
void jog (ESTADO *e);
/**
\brief Joga pelo jogador-Distancia
@param e Apontador para o estado
*/
void jog2 (ESTADO *e);
#endif //PROJETOLA_INTERFACE_H
