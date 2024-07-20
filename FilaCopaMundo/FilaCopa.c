#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    int ident;
    struct pessoa * prox;
}Pessoa;

typedef struct{
    Pessoa * first;
    Pessoa * last;
    int tam;
}Fila;

void CriarFila(Fila * fila){
    fila->first = NULL;
    fila->last = NULL;
    fila->tam = 0;
}

void inserirFila(Fila * fila, int id){
    Pessoa * nova = malloc(sizeof(Pessoa)), * aux;
    if(nova){
        nova->ident = id;
        nova->prox = NULL;
        if(fila->first == NULL){
            fila->first = nova;
            fila->last = nova;
        }
        else{
            fila->last->prox = nova;
            fila->last = nova;
        }
        fila->tam++;
    }
}

Pessoa * removerFila(Fila * fila, int num){
    Pessoa * aux = NULL, * cont;
    if(fila->first){
        if(fila->first->ident == num){
            aux = fila->first;
            fila->first = aux->prox;
            fila->tam--;
        }
        else{
            cont = fila->first;
            while(cont->prox && cont->prox->ident != num){
                cont = cont->prox;
            }
            if(cont->prox){
                aux = cont->prox;
                cont->prox = aux->prox;
                fila->tam--;
            }
        }
    }

    return aux;
}

void imprimir(Fila * fila){
    Pessoa * aux = fila->first;
    while(aux){
        printf("%d ", aux->ident);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    Fila  fila;
    CriarFila(&fila);
    int n, num;
    scanf("%d", &n);
    //n = n+1;
    while(n--){
        scanf("%d", &num);
        inserirFila(&fila, num);
    }
    scanf("%d", &n);
    //n = n+1;
    while(n--){
        scanf("%d", &num);
        removerFila(&fila, num);
    }

    imprimir(&fila);
    
}

