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
 
FILA *intercala(FILA *a, FILA *b) { 
    FILA *fIntercalado = cria();
    while (tamanho(a) > 0 && tamanho(b)) {
        enfilera(fIntercalado, desenfilera(a));
        enfilera(fIntercalado, desenfilera(b));
    }

    while (tamanho(a) > 0) {
        enfilera(fIntercalado, desenfilera(a));
    }

    while (tamanho(b) > 0) {
        enfilera(fIntercalado, desenfilera(b));
    }

    return fIntercalado;
}

int main() {
    FILA *a = cria();
    FILA *b = cria();

    // Preenchendo a fila 'a' (ex: 1, 3, 5)
    enfilera(a, 1);
    enfilera(a, 3);
    enfilera(a, 5);

    // Preenchendo a fila 'b' (ex: 2, 4, 6)
    enfilera(b, 2);
    enfilera(b, 4);
    enfilera(b, 6);

    // Intercalando as filas
    FILA *result = intercala(a, b);

    // Imprimindo os elementos da fila intercalada
    printf("Fila intercalada: [ ");
    while (tamanho(result) > 0) {
        printf("%d ", desenfilera(result));
    }
    printf("]\n");

    // Limpeza de memória
    destroi(a);
    destroi(b);
    destroi(result);

    return 0;
}