//
// Created by bruno on 11/03/20.
//

#include "interface.h"
#include "dados.h"
#include "logica.h"
#include <string.h>
#include <stdio.h>
#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    for(int i = 7 ; i >= 0 ; i--){
        for(int j = 0; j < 8 ; j++){
            if(j==7 && i == 7) printf("2");
            else if (j==0 && i == 0) printf("1");
            else{
                if( e -> tab [i] [j] == VAZIO){
                    printf(".");
                }
                else if(e -> tab [i] [j] == BRANCA){
                    printf("*");
                }
                else{
                    printf("#");
                }
            }

        }
        printf("\n");
    }
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col -'a', *lin -'1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}