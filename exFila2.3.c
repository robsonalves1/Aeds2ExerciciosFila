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

void inverte(FILA *f) {
    int tam = tamanho(f);
    if (tam == 0) return;

    int fAux[tam];

    int i = tam - 1;
    int elemAux = 0;

    while (tamanho(f) > 0) {
        elemAux = desenfilera(f);
        fAux[i] = elemAux;
        i--;
    }

    for (int j = 0; j < tam; j++) {
        enfilera(f, fAux[j]);
    }
}
 

int main() {
    // 1. Cria a fila
    FILA *f = cria();

    // 2. Insere alguns elementos (Ordem de entrada: 10, 20, 30, 40, 50)
    enfilera(f, 10);
    enfilera(f, 20);
    enfilera(f, 30);
    enfilera(f, 40);
    enfilera(f, 50);

    printf("Fila criada com sucesso!\n");

    // 3. Inverte a fila
    inverte(f);

    // 4. Retira os elementos para verificar se inverteu (Deve sair: 50, 40, 30, 20, 10)
    printf("Elementos apos a inversao (deve sair de 50 ate 10):\n");
    while (tamanho(f) > 0) {
        printf("%d \n", desenfilera(f));
    }

    // 5. Libera a memoria
    destroi(f);

    return 0;
}