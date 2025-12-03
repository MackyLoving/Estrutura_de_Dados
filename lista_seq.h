#define LIMITE 100

typedef struct {
    int dados[LIMITE];
    int quantidade;
} Lista;

void inicializar(Lista *l);
int esta_vazia(Lista *l);
int esta_cheia(Lista *l);
int tamanho(Lista *l);
int obter(Lista *l, int pos, int *valor);
int alterar(Lista *l, int pos, int valor);
int inserir(Lista *l, int pos, int valor);
int remover(Lista *l, int pos, int *valor);
void mostrar(Lista *l);
