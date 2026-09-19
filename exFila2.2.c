#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//2.2 — Duas filas são iguais?
//Implemente int iguais(struct fila *a, struct fila *b); que devolve verdadeiro se as duas filas
//têm os mesmos elementos, na mesma ordem. Ao final, a e b devem permanecer intactas

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

int iguais(FILA *a, FILA *b) {
    if (tamanho(a) != tamanho(b)) {
        return 0;
    }

    FILA *fAuxA = cria();
    FILA *fAuxB = cria();

    int res = 0;
    
    int nAuxA = 0; 
    int nAuxB = 0; 
    
    while (tamanho(a) > 0) {
        nAuxA = desenfilera(a);
        nAuxB = desenfilera(b);

        if (nAuxA != nAuxB) {
            return 0;
        } else {
            res = 1;

            enfilera(fAuxA, nAuxA);
            enfilera(fAuxB, nAuxB);
        }
    }

    while (tamanho(fAuxA) > 0) {
        enfilera(a, desenfilera(fAuxA));
        enfilera(b, desenfilera(fAuxB));
    }

    destroi(fAuxA);
    destroi(fAuxB);

    return res;
}

int main() {
    // 1. Cria duas filas para teste
    FILA *fila1 = cria();
    FILA *fila2 = cria();

    // 2. Adiciona os mesmos elementos em ambas
    enfilera(fila1, 10);
    enfilera(fila1, 20);
    enfilera(fila1, 30);

    enfilera(fila2, 10);
    enfilera(fila2, 20);
    enfilera(fila2, 30);

    // Teste 1: Devem ser iguais (retorna 1)
    printf("Teste 1 (Devem ser iguais): %d\n", iguais(fila1, fila2));

    // 3. Altera um elemento da segunda fila
    desenfilera(fila2); // remove o 10
    enfilera(fila2, 40); // adiciona o 40 (fila2 agora tem: 20, 30, 40)

    // Teste 2: Devem ser diferentes (retorna 0)
    printf("Teste 2 (Devem ser diferentes): %d\n", iguais(fila1, fila2));

    // 4. Limpa a memória das filas principais antes de encerrar
    destroi(fila1);
    destroi(fila2);

    return 0;

    return 1;
}