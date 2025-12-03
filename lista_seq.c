#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void inicializar(Lista *l) {
    if (!l) return;
    l->quantidade = 0;
}

int esta_vazia(Lista *l) {
    if (!l) return 1;
    return l->quantidade == 0;
}

int esta_cheia(Lista *l) {
    if (!l) return 0;
    return l->quantidade == LIMITE;
}

int tamanho(Lista *l) {
    if (!l) return 0;
    return l->quantidade;
}

int obter(Lista *l, int pos, int *valor) {
    if (!l || pos < 1 || pos > l->quantidade || !valor) return 0;
    *valor = l->dados[pos - 1];
    return 1;
}

int alterar(Lista *l, int pos, int valor) {
    if (!l || pos < 1 || pos > l->quantidade) return 0;
    l->dados[pos - 1] = valor;
    return 1;
}

int inserir(Lista *l, int pos, int valor) {
    if (!l || pos < 1 || pos > l->quantidade + 1) return 0;
    if (esta_cheia(l)) return 0;

    for (int i = l->quantidade - 1; i >= pos - 1; --i) {
        l->dados[i + 1] = l->dados[i];
    }

    l->dados[pos - 1] = valor;
    l->quantidade++;
    return 1;
}

int remover(Lista *l, int pos, int *valor) {
    if (!l || pos < 1 || pos > l->quantidade) return 0;

    if (valor) *valor = l->dados[pos - 1];

    for (int i = pos - 1; i < l->quantidade - 1; ++i) {
        l->dados[i] = l->dados[i + 1];
    }

    l->quantidade--;
    return 1;
}

void mostrar(Lista *l) {
    if (!l) return;

    printf("[ ");
    for (int i = 0; i < l->quantidade; ++i) {
        printf("%d ", l->dados[i]);
    }
    printf("]\n");
}
