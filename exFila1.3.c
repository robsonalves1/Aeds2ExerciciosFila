#include <stdio.h>
#include <stdlib.h>
#define MAX 3

//1.3 — esta_vazia e esta_cheia
//Implemente duas funções que devolvem 1 (verdadeiro) ou 0 (falso):
//    int esta_vazia(struct fila *f);
//    int esta_cheia(struct fila *f);
//Depois, reescreva as suas versões de enfilera e desenfilera usando essas funções em vez de comparar
//os índices "na mão".

typedef struct {
    int elementos[MAX];
    int primeiro;
    int ultimo;
} FILA;

// Na linguagem C os métodos precisam estar declarados antes de serem chamados
int esta_vazia(FILA *f);
int esta_cheia(FILA *f);
//

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
    if (esta_cheia(f)) {
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
    if (esta_vazia(f)) {
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

int esta_vazia(FILA *f) {
    if (f->primeiro == f->ultimo) {
        return 1;
    } else {
        return 0;
    }
}

int esta_cheia(FILA *f) {
    if ((f->ultimo + 1) % MAX == f->primeiro) {
        return 1;
    } else { 
        return 0;
    }
}

int main() {
    FILA *f = cria();

    printf("Pilha criada.\n\n");

    enfilera(f, 3);
    enfilera(f, 7);
    enfilera(f, 1);
    enfilera(f, 9);

    return 1;
}