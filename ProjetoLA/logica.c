
#include "dados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
int jogar(ESTADO *e, COORDENADA c) {

        if (jogada_valida(e, c)) {
            atualiza_estado_casa(e, c, BRANCA);
            atualiza_ultima(e);
            muda_pos_ultima(e,c);

            atualiza_jogadas(e,c);
            atualiza_jogador(e);
            if(consulta_jogador(e)==2) e->num_jogadas++;
        } else {
            printf("Jogada Invalida\n");

            interpretador(e);

        }

    return 1;
}
int jogada_valida(ESTADO *e, COORDENADA c){
    if( (abs(c.coluna-e->ultima_jogada.coluna)<=1 && abs(c.linha-e->ultima_jogada.linha)<=1) ){

        if((consulta_posicao(e,c.coluna+0,c.linha+0))==BRANCA)  {  return 0 ;}
        else if((consulta_posicao(e,c.coluna+0,c.linha+0))==PRETA)  {  return 0 ;}
        else return 1;
    }
    return 0;
}


int fim_jogo(ESTADO *e){
    if((e->ultima_jogada.coluna==0&&e->ultima_jogada.linha==0)||(e->ultima_jogada.coluna==7&&e->ultima_jogada.linha==7)) return 1;
    if(!possivel_jogar(e)) return 1;
    return 0;
}
int possivel_jogar(ESTADO *e){
    if(e->ultima_jogada.linha==0){
    if(     (consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha+0)==PRETA)&&
            (consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha+1)==PRETA)&&
            (consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha+0)==PRETA)&&
            (consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha+1)==PRETA)&&
            (consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha+1)==PRETA)
            ) return 0;



    }

    if(e->ultima_jogada.linha==7){
        if(     (consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha+0)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha-1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha+0)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha-1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha-1)==PRETA)
                ) return 0;
    }


    if(e->ultima_jogada.coluna==7){
        if(     (consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha+1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha-1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha+0)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha+1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha-1)==PRETA)
                ) return 0;
    }


    if(e->ultima_jogada.coluna==0){
        if(     (consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha+1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha-1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha+0)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha+1)==PRETA)&&
                (consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha-1)==PRETA)
                ) return 0;
    }
    if(e->ultima_jogada.linha ==0 && e->ultima_jogada.coluna==7) {
        if ((consulta_posicao(e, e->ultima_jogada.coluna + 0, e->ultima_jogada.linha + 1) == PRETA) &&
            (consulta_posicao(e, e->ultima_jogada.coluna - 1, e->ultima_jogada.linha + 1) == PRETA) &&
            (consulta_posicao(e, e->ultima_jogada.coluna - 1, e->ultima_jogada.linha + 0) == PRETA)
                )
            return 0;
    }
    if(e->ultima_jogada.linha ==7 && e->ultima_jogada.coluna==0) {
        if ((consulta_posicao(e, e->ultima_jogada.coluna + 0, e->ultima_jogada.linha - 1) == PRETA) &&
            (consulta_posicao(e, e->ultima_jogada.coluna + 1, e->ultima_jogada.linha - 1) == PRETA) &&
            (consulta_posicao(e, e->ultima_jogada.coluna + 1, e->ultima_jogada.linha + 0) == PRETA)
                )
            return 0;
    }



    if(consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha+0)==VAZIO) return 1;
    if(consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha+1)==VAZIO) return 1;
    if(consulta_posicao (e,e->ultima_jogada.coluna+1,e->ultima_jogada.linha-1)==VAZIO) return 1;
    if(consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha+0)==VAZIO) return 1;
    if(consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha+1)==VAZIO) return 1;
    if(consulta_posicao (e,e->ultima_jogada.coluna-1,e->ultima_jogada.linha-1)==VAZIO) return 1;
    if(consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha+1)==VAZIO) return 1;
    if(consulta_posicao (e,e->ultima_jogada.coluna+0,e->ultima_jogada.linha-1)==VAZIO) return 1;

    return 0;
}
