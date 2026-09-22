#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//2.5 — Remover todas as ocorrências de um valor
//Implemente void remove_valor(struct fila *f, int v); que remove todas as ocorrências de v
//mantendo a ordem dos demais elementos. Use apenas operações de fila (dica: uma fila auxiliar)

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

void removeValor(FILA *f, int v) {
    FILA *fAux = cria();
    int elemAux = 0;

    while (tamanho(f) > 0) {
        elemAux = desenfilera(f);

        if (elemAux != v) {
            enfilera(fAux, elemAux);
        }
    }

    while (tamanho(fAux) > 0) {
        enfilera(f, desenfilera(fAux));
    }

    destroi(fAux);
}


void imprime(FILA *f) {
    printf("[ ");
    int i = f->primeiro;
    while (i != f->ultimo) {
        printf("%d ", f->elementos[i]);
        i = (i + 1) % MAX;
    }
    printf("]\n");
}

int main() {
    FILA *f = cria();

    // 1. Enfileirando elementos de teste 
    // (A fila suporta MAX-1 elementos, ou seja, 9 elementos)
    enfilera(f, 10);
    enfilera(f, 20); // Valor alvo
    enfilera(f, 30);
    enfilera(f, 20); // Valor alvo (no meio)
    enfilera(f, 40);
    enfilera(f, 20); // Valor alvo (no final)
    enfilera(f, 50);

    printf("1. Fila original:\n");
    imprime(f);

    // 2. Testando a remocao de um valor que aparece varias vezes
    int valor_alvo = 20;
    printf("\nRemovendo o valor %d...\n", valor_alvo);
    removeValor(f, valor_alvo);
    
    printf("Fila apos a remocao:\n");
    imprime(f);

    // 3. Testando a remocao de um valor que NAO existe na fila
    int valor_inexistente = 99;
    printf("\nRemovendo o valor %d (nao existe)...\n", valor_inexistente);
    removeValor(f, valor_inexistente);
    
    printf("Fila apos tentar remover %d (deve ser igual a anterior):\n", valor_inexistente);
    imprime(f);

    // 4. Liberando a memória principal
    destroi(f);
    printf("\nMemoria liberada com sucesso. Fim do teste.\n");

    return 0;
}