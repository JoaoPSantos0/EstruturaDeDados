#include <stdlib.h>

typedef struct no {
    int valor; 
    struct no * proxima;
    
}No;

typedef struct {
    No * inicio;
    int tam;

}Lista;

void criarLista(Lista *lista);

void inserirInicio(Lista *lista, int num);

void inserirFinal(Lista *lista, int num);

void inserirMeio(Lista *lista, int num, int ant);

void printLista(Lista *lista);