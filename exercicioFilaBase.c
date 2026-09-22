#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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
        printf("Fila vazia\n");
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
    int res = (f->ultimo - f->primeiro + MAX) % MAX;

    return res;
}

void destroi(FILA *f) {
    free(f);
}
 

int main() {

    return 1;
}