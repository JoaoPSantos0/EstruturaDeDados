#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int * mem;//quantidade de elementos na memoria da pilha;
    int tam_max;//quantidade maxima de elementos da pilha;
    int top;//inteiro que indica o topo da pilha;
}Stack;

//Funçao que cria uma nova pilha dinamicamente;
Stack * new_stack( int valor_max){
    Stack * p = calloc(1, sizeof(Stack));
    p->tam_max = valor_max;
    p->mem = calloc(valor_max, sizeof(int));
    return (Stack * )p;
}

//Funçao que insere um elemento no topo da pilha;
void push_stack ( Stack * p, int valor){
    if(p->top >= p->tam_max){
        printf("Stack overflow\n");
        exit(0);
    }
    p->mem[p->top] = valor;
    p->top++;
}

//Funçao que remove o elemento do topo da pilha;
int pop( Stack * p){
    if(p->top <= 0){
        printf("Stack underflow\n");
        exit(0);
    }
    p->top--;
    return p->mem[p->top];
}

//Funçao para exibiçao;
void print_stack ( Stack * p ){
    for(int i = 0; i<p->top; i++){
        printf("%d ",p->mem[i]);
    }
    printf("\n");
}

//Funçao para liberar memoria em tempo de execuçao;
void free_stack( Stack * p ){
    free(p->mem);
    free(p);
}


//Funçao main para teste de funcionalidade;
int main(){
    Stack * p = new_stack(5);
    push_stack(p, 1);
    push_stack(p, 2);
    push_stack(p, 3);
    push_stack(p, 4);
    push_stack(p, 5);
    print_stack(p);//1 2 3 4 5
    pop(p);
    print_stack(p);//1 2 3 4
    pop(p);
    print_stack(p);//1 2 3
    free_stack(p);
}
