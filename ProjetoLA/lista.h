
/**
@file listas.h
Definição das listas ligadas usadas na heurística
*/
#include "dados.h"
#ifndef PROJETOLA_LISTA_H
#define PROJETOLA_LISTA_H
/**
\brief Definição da lista ligada genérica
*/
typedef struct lista{
    void *conteudo;
    struct lista *prox;
}*LISTA;
/**
\brief Função que cria um lista ligada
@returns Apontador para a lista ligada
*/
LISTA criar_lista();
/**
\brief Função que insere um valor à cabeça
@param L Lista ligada
@param valor Valor que vai ser adicionado
@returns Apontador para a lista ligada
 */
LISTA insere_cabeca(LISTA L, void *valor);
/**
\brief Função que devolve a cabeça da lista
@param L Lista ligada
@returns Conteúdo guardado na cabeça
*/
void *devolve_cabeca(LISTA L);
/**
\brief Função que devolve o próximo valor da lista
@param L Lista ligada
@returns Lista que começa no elemento seguinte da lista dada
 */
LISTA proximo(LISTA L);
/**
\brief Função que remove a cabeça da lista
@param L Lista ligada
@returns Cauda da lista ligada
 */
LISTA remove_cabeca(LISTA L);
/**
\brief Função que verifica se a lista está vazia
@param L Lista ligada
@returns 0 - Lista não está vazia | 1 - Lista está vazia
 */
int lista_esta_vazia(LISTA L);
#endif //PROJETOLA_LISTA_H
