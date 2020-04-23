#include <stdio.h>
#include "dados.h"
#include "logica.h"
#include "interface.h"
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    ESTADO *e = inicializar_estado();

    mostrar_tabuleiro(e,stdout);
    interpretador(e);
    return 0;
}
