#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//1.2 — frente (espiar sem remover)
//Implemente
//    int frente(struct fila *f);
//que devolve o elemento do início da fila sem desenfileirá-lo. A fila deve continuar exatamente igual depois
//da chamada. Trate o caso de fila vazia. 

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
 
int frente(FILA *f) {
    if (tamanho(f) > 0) {
        return f->elementos[f->primeiro];
    } else {
        printf("Fila vazia.\n");
        exit(1);
    }
}

int main() {
    FILA *f = cria();

    printf("Pilha criada.\n\n");

    enfilera(f, 3);
    enfilera(f, 7);
    enfilera(f, 1);
    enfilera(f, 9);

    desenfilera(f);

    int primeiro = frente(f);
    printf("primeiro elemento: %d\n", primeiro);

    destroi(f);


    return 1;
}