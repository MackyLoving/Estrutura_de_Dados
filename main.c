#include <stdio.h>
#include "lista_sequencial.h"

int main(void) {
    Lista lista;
    inicializar(&lista);

    printf("Lista criada. Ela está vazia? %s\n", esta_vazia(&lista) ? "Sim" : "Não");

    // inserir alguns elementos
    inserir(&lista, 1, 10);
    inserir(&lista, 2, 20);
    inserir(&lista, 3, 30);
    inserir(&lista, 2, 15); // insere no meio

    printf("Lista após as inserções: ");
    mostrar(&lista);

    printf("Tamanho: %d\n", tamanho(&lista));

    int val;
    if (obter(&lista, 2, &val))
        printf("Valor da posição 2: %d\n", val);

    alterar(&lista, 2, 25);
    printf("Depois de alterar o valor da posição 2 para 25: ");
    mostrar(&lista);

    if (remover(&lista, 3, &val))
        printf("Posição 3 removida (valor %d): ", val);
    mostrar(&lista);

    printf("A lista está vazia? %s\n", esta_vazia(&lista) ? "sim" : "nao");
    printf("A lista está cheia? %s\n", esta_cheia(&lista) ? "sim" : "nao");

    inserir(&lista, tamanho(&lista) + 1, 99);
    printf("Depois de inserir 99 no final: ");
    mostrar(&lista);

    int ok = inserir(&lista, 0, 1); // pos inválida
    printf("Inserir posição 0 (esperado 0): %d\n", ok);

    ok = inserir(&lista, 1000, 1); // pos inválida
    printf("Inserir posição 1000 (esperado 0): %d\n", ok);

    return 0;
}
