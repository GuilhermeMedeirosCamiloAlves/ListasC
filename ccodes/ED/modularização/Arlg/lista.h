#define Max 10
typedef struct{
    int chave;
}Chave;
typedef struct{
    Chave elemento;
    int prox;
}no;
typedef struct{
    int inicio, dispo;
    no item[Max];
}Lista;
int cheia(Lista *lista);
void inicialista(Lista *lista);
int adicionaritem(int p, Lista *lista);
void removeritemporindice(int p, Lista *lista);
void limparista(Lista *lista);
void mostrarista( Lista *lista);
void trocaritemdeugar(int a, int b, Lista *lista);
int buscaritem(int p,Lista *lista);
