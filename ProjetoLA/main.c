#include <stdio.h>
#include "dados.h"
#include "logica.h"
#include "interface.h"
int main() {
    ESTADO *e = inicializar_estado();

    mostrar_tabuleiro(e,stdout);
    interpretador(e);
    return 0;
}
