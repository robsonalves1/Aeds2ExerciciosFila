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
    int res = f->ultimo - f->primeiro;

    if (res < 0) {
        res = res * (-1);
    }

    return res;
}

void destroi(FILA *f) {
    free(f);
}
 
void imprime(FILA *f) {
    FILA *fAux = cria();
    int numAux = 0;

    while (tamanho(f) > 0) {
        numAux = desenfilera(f);
        printf("%d\n", numAux);
        enfilera(fAux, numAux);
    }

    while (tamanho(fAux) > 0) {
        numAux = desenfilera(fAux);
        enfilera(f, numAux);
    }

    destroi(fAux);
}

int main() {
    FILA *f = cria();

    printf("Pilha criada.\n\n");

    enfilera(f, 3);
    enfilera(f, 7);
    enfilera(f, 1);
    enfilera(f, 9);

    destroi(f);

    return 1;
}