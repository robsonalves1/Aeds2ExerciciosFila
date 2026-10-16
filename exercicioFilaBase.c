#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elementos[MAX];
    int primeiro;
    int ultimo;
    int total;
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
    f->total = 0;
}

int estaCheia(FILA *f) {
    return f->total == MAX;
}

int estaVazia(FILA *f) {
    return f->total == 0;
}

void enfilera(FILA *f, int elem) {
    if (estaCheia(f)) {
        printf("Fila cheia\n");
        exit(1);
    } 

    f->elementos[f->ultimo] = elem;
    f->ultimo++;

    if (f->ultimo == MAX) {
        f->ultimo = 0;
    }

    f->total++;
}

int desenfilera(FILA *f) {
    if (estaVazia(f)) {
        printf("Fila vazia\n");
        exit(1);
    }

    int res = f->elementos[f->primeiro];
    f->primeiro++;

    if (f->primeiro == MAX) {
        f->primeiro = 0;
    }

    f->total--;

    return res;
}

void destroi(FILA *f) {
    free(f);
}
 

int main() {
    FILA *f = cria();

    for (int i = 1; i <= 5; i++)
        enfilera(f, i * 10);

    while (!estaVazia(f))
        printf("%d\n", desenfilera(f));

    destroi(f);
    return 0;
}