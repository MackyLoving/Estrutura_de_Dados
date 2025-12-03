#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h" 

void inicializa_lista(Lista *dados) {
    if (!dados) return; 
    dados->quantidade = 0; 
}

int esta_vazia(Lista *dados) {
    if (!dados) return 1;    
    return dados->quantidade == 0; 
}

int esta_completa(Lista *dados) {
    if (!dados) return 0;
    return dados->quantidade == MAX;
}

int obter_tamanho(Lista *dados) {
    if (!dados) return 0;
    return dados->quantidade;
}

int pegar_elemento(Lista *dados, int indice, int *destino) {
    
    if (!dados || indice < 1 || indice > dados->quantidade || !destino) 
    return 0;
    
    *destino = dados->elementos[indice - 1]; 
    return 1;
}

int modificar_elemento(Lista *dados, int indice, int novoValor) {
    if (!dados || indice < 1 || indice > dados->quantidade) 
    return 0;

    dados->elementos[indice - 1] = novoValor; 
    return 1;
}

int incluir_elemento(Lista *dados, int indice, int novoValor) {

    if (!dados || indice < 1 || indice > dados->quantidade + 1) 
    return 0;    
    if (esta_completa(dados)) return 0;

    for (int j = dados->quantidade - 1; j >= indice - 1; --j) {
        dados->elementos[j + 1] = dados->elementos[j];
    }
    
    dados->elementos[indice - 1] = novoValor;
  
    dados->quantidade++;
    return 1;
}

int excluir_elemento(Lista *dados, int indice, int *removido) {

    if (!dados || indice < 1 || indice > dados->quantidade) 
    return 0;
    if (removido) *removido = dados->elementos[indice - 1];
    for (int k = indice - 1; k < dados->quantidade - 1; ++k) {
        dados->elementos[k] = dados->elementos[k + 1];
    }
    
    dados->quantidade--;
    return 1;
}

void exibir_lista(Lista *dados) {
    if (!dados) return;
    printf("Lista: [ ");
    for (int m = 0; m < dados->quantidade; ++m) {
        printf("%d ", dados->elementos[m]);
    }
    printf("]\n");
}
