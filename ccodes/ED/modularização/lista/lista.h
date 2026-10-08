    //por valor
    #define MAX 100
    typedef struct{
        int element;
    }Element;

    typedef struct{
        Element e[MAX];
        int tamanho;
    }Lista;

    void inicialista(Lista *lista);
    void adicionaritem(int p, Lista *lista);
    void removeritemporindice(int p, Lista *lista);
    void limparista(int p, Lista *lista);
    void mostrarista( Lista *lista);
    void trocaritemdeugar(int a, int b, Lista *lista);
    int buscaritem(int p,Lista *lista);
