
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
LISTA criar_lista(){
    LISTA L = malloc(sizeof(LISTA));
    L->conteudo = NULL;
    L->prox = NULL;
    return L;
}
LISTA insere_cabeca(LISTA L, void *valor){
   if(L->conteudo == NULL){
       L->conteudo=valor;
       return L;
   }
   else{
       LISTA M = malloc(sizeof(LISTA));
       M->conteudo = valor;
       M->prox = L;
       return M;
   }

}
void *devolve_cabeca(LISTA L){
    return L->conteudo;
}
LISTA proximo (LISTA L){
    return L->prox;
}
LISTA remove_cabeca(LISTA L){
    LISTA M = L->prox;
    free(L);
    return M;
}
int lista_esta_vazia(LISTA L){
    if(L==NULL||(L->conteudo == NULL && L->prox == NULL)) return 1;
    else        return 0;
}