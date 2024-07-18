#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no * next;
    
}Lista;


//Procedimento para inserir um elemento no inicio de uma lista;
void insertElementInicio(Lista **lista, int num){

    Lista *newLista = malloc(sizeof(Lista));

    if(newLista){
        newLista->valor = num;
        newLista->next = *lista;
        *lista = newLista;
    }
    else printf("Erro ao adiconar elemento!\n");


//Procedimento para inserir um elemento no final de uma lista;
void insertElementFim(Lista **lista, int num){
    Lista *newLista = malloc(sizeof(Lista)), *aux;
    if(newLista != NULL){
        newLista->valor = num;
        newLista->next = NULL;
        if(*lista == NULL){
            *lista = newLista;
        }
        else{
            aux = *lista;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = newLista;
        }
    }
    else printf("Erro ao adicionar um elemento!\n");
}

void inserirElementoMeio(Lista **lista, int num, int ant){
    Lista *newLista = malloc(sizeof(Lista)), *aux;
    if(newLista){
        newLista->valor = num;
        //É o primeiro;
        if(*lista == NULL){
            newLista->next = NULL;
            *lista = newLista;
        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->next){
                aux = aux->next;
            }
            newLista->next = aux->next;
            aux->next = newLista;
        }
    }
    else printf("Erro ao adicionar um elemento!\n");

}

Lista *removerElemento(Lista **lista, int num){
    Lista *remove = NULL, *aux;

    if(*lista){
        if((*lista)->valor == num){//se for o primeiro elemento da lista;
            remove = *lista;
            *lista = remove->next;
        }
        else{
            aux = *lista;
            while(aux->next && aux->next->valor != num){
                aux = aux->next;
            }
            if(aux->next){
                remove = aux->next;
                aux->next = remove->next;
            }
        }

    }
    return remove;

}


void printList(Lista * lista){
    printf("\n\tLista: ");
    while(lista){
        printf("%d ", lista->valor);
        lista = lista->next;
    }
    printf("\n\n");
}

int main(){

    Lista *lista = NULL, *lista2 = NULL;
    int n, valor;
    printf("Digite o tamanho da lista:\n");
    scanf("%d",&n);
    for(int i = 1; i<=n; i++){
        scanf("%d", &valor);
        insertElementInicio(&lista, valor);
    }
    printList(lista);
    printf("Digite o tamanho da lista:\n");
    scanf("%d",&n);
    for(int i = 1; i<=n; i++){
        scanf("%d", &valor);
        insertElementFim(&lista2, valor);
    }
    printList(lista2);
    free(lista2);

    printf("\n Digite um valor a ser removido:\n");
    scanf("%d",&n);
    lista = removerElemento(&lista, n);
    printf("\nElemento removido\n");
    printList(lista);
    
    return 0;
}
