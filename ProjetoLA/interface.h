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
 * @param destino onde vai ser impresso o tabuleiro
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
 * @param e Apontador para o estado
 */
void ler(char *file,ESTADO *e);
#endif //PROJETOLA_INTERFACE_H
