
#include <stdlib.h>
#include <stdio.h>


typedef struct no {
    int valor; 
    struct no * proxima;
    
}No;

typedef struct {
    No * inicio;
    int tam;

}Lista;

void criarLista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserirInicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proxima = lista->inicio;
        lista->tam++;
    }
    else{
        printf("Erro ao alocar memória\n\n");
    }
}

void inserirFinal(Lista *lista, int num){
    No *novo = malloc(sizeof(No)), *aux;

    if(novo){
        novo->valor = num;
        novo->proxima = NULL;
        if(lista->inicio == NULL){
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while (aux->proxima)
            {
                aux = aux->proxima;
            }
            aux->proxima = novo;
            
        }
        lista->tam++;
    }
    else printf("Erro ao alocar memória\n\n");
}
//insere o elemento depois de um numero escolhido da lista;
void inserirMeio(Lista *lista, int num, int ant){
    No *novo = malloc(sizeof(No)), *aux;
    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proxima == NULL;
            lista->inicio = novo;   
        }
        else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proxima != NULL){
                aux = aux->proxima;
            }
            novo->proxima = aux->proxima;
            aux->proxima = novo;

        }
        lista->tam++;

    }
    else{
        printf("Erro ao alocar memória\n\n");
    }

}

void printLista(Lista lista){
    No *aux = lista.inicio;
    printf("\n\tLista: ");
    while (aux->proxima)
    {
        printf("%d ", aux->valor);
    }
    printf("\n\n");
    
}