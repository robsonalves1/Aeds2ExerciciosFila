#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//1.1 — Programa de teste
//Escreva uma função main que: cria uma fila, enfileira os valores 3, 7, 1, 9, imprime o tamanho,
//desenfileira e imprime todos os elementos (um por linha) e, por fim, destrói a fila. Confirme na saída que a
//ordem de remoção é 3, 7, 1, 9 (o primeiro a entrar é o primeiro a sair).

typedef struct {
    int elementos[MAX];
    int primeiro;
    int ultimo;
} FILA;

FILA *cria() {
    FILA *f;
    f = malloc(sizeof(FILA));

    if (!f) {
        perror(NULL);
        exit(1);
    }

    f->primeiro = 0;
    f->ultimo = 0;
}

void enfilera(FILA *f, int elem) {
    if ((f->ultimo + 1) % MAX == f->primeiro) {
        printf("Fila cheia\n");
        exit(1);
    } 

    f->elementos[f->ultimo] = elem;
    f->ultimo++;

    if (f->ultimo == MAX) {
        f->ultimo = 0;
    }
}

int desenfilera(FILA *f) {
    if (f->primeiro == f-> ultimo) {
        exit(1);
    }

    int res = f->elementos[f->primeiro];
    f->primeiro++;

    if (f->primeiro == MAX) {
        f->primeiro = 0;
    }

    return res;
}

int tamanho(FILA *f) {
    int res = f->ultimo - f->primeiro;

    if (res < 0) {
        res = res * (-1);
    }

    return res;
}

void destroi(FILA *f) {
    free(f);
}
 

int main() {
    FILA *f = cria();

    printf("Pilha criada.\n\n");

    enfilera(f, 3);
    enfilera(f, 7);
    enfilera(f, 1);
    enfilera(f, 9);

    printf("Tamanho da fila: %d\n\n", tamanho(f));

    printf("Elementos desenfilerados.\n\n");
    while (tamanho > 0) {
        printf("%d, ", desenfilera(f));
    }

    destroi(f);


    return 1;
}