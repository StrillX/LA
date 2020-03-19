#include "dados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
int jogar(ESTADO *e, COORDENADA c) {

        if (jogada_valida(e, c)) {
            atualiza_estado_casa(e, c, BRANCA);
            atualiza_ultima(e);
            muda_pos_ultima(e,c);

            atualiza_jogador(e);
        } else {
            printf("Jogada Invalida\n");
            atualiza_ultima(e);
            muda_pos_ultima(e,c);
            interpretador(e);

        }

    return 1;
}
