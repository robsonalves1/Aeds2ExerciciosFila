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
    FILA *filaDoBanco = cria();
    int tempo = -1;
    int i = 1;

    printf("---Abertura do Banco---\n\n");

    do {
        printf("Digite quanto tempo o cliente esperou para ser atendido: \n");
        scanf("%d", &tempo);
        enfilera(filaDoBanco, tempo);
    } while (tempo > -1);

    while (tamanho(filaDoBanco) > 0) {
        printf("o cliente %d esperou na fila %d minuto(s) para ser atendido. \n", i, desenfilera(filaDoBanco));
        i++;
    }

    destroi(filaDoBanco);

    return 1;
}