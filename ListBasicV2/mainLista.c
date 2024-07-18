//#include "listaHead.h"

#include <stdlib.h>
#include <stdio.h>
#include "listaHead.h"


int main(){
    Lista lista, lista2, lista3;
    criarLista(&lista);
    inserirInicio(&lista,3 );
    inserirInicio(&lista, 12);
    inserirInicio(&lista, 42);
    inserirInicio(&lista,76 );
    printLista(&lista);
    inserirFinal(&lista2, 6);
    inserirFinal(&lista2, 43);
    inserirFinal(&lista2, 23);
    inserirFinal(&lista2, 8);
    inserirFinal(&lista2, 98);
    printLista(&lista2);
    

    return 0;
}