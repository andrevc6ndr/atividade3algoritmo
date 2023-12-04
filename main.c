#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações do produto
typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

// Estrutura para o nó da lista encadeada
typedef struct No {
    Produto produto;
    struct No *prox;
} No;

// Função que inicializa a lista vazia
No *inicializaLista() {
    return NULL;
}

// Função que adiciona um novo produto à lista de estoque
No *adicionaProduto(No *lista) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Memória insuficiente.\n");
        return lista;
    }

    printf("Informe o código, descrição, quantidade e valor do produto: ");
    scanf("%d %s %d %f", &novoNo->produto.codigo, novoNo->produto.descricao, &novoNo->produto.quantidade, &novoNo->produto.valor);
    novoNo->prox = lista;

    return novoNo;
}

// Função que imprime um relatório com as informações de cada produto
void imprimeRelatorio(No *lista) {
    printf("Relatório de produtos:\n");
    No *atual = lista;

    while (atual != NULL) {
        printf("Código: %d, Descrição: %s, Quantidade: %d, Valor: %.2f\n", atual->produto.codigo, atual->produto.descricao, atual->produto.quantidade, atual->produto.valor);
        atual = atual->prox;
    }
}

// Função que pesquisa um produto pelo código
void pesquisaPorCodigo(No *lista, int codigo) {
    No *atual = lista;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            printf("Produto encontrado:\nCódigo: %d, Descrição: %s, Quantidade: %d, Valor: %.2f\n", atual->produto.codigo, atual->produto.descricao, atual->produto.quantidade, atual->produto.valor);
            encontrado = 1;
            break;
        }
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

// Função que remove um produto do estoque pelo código
No *removeProduto(No *lista, int codigo) {
    No *atual = lista;
    No *anterior = NULL;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            if (anterior == NULL) {
                lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Produto removido com sucesso.\n");
            encontrado = 1;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }

    return lista;
}

int main() {
    No *lista = inicializaLista();
    int opcao, codigo;

    do {
        printf("\nMenu:\n1 - Adicionar produto\n2 - Consultar produtos\n3 - Gerar relatório de produtos\n4 - Pesquisar produto por código\n5 - Remover produto do estoque\n0 - Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lista = adicionaProduto(lista);
                break;
            case 2:
                imprimeRelatorio(lista);
                break;
            case 3:
                imprimeRelatorio(lista);
                break;
            case 4:
                printf("Informe o código do produto a pesquisar: ");
                scanf("%d", &codigo);
                pesquisaPorCodigo(lista, codigo);
                break;
            case 5:
                printf("Informe o código do produto a remover: ");
                scanf("%d", &codigo);
                lista = removeProduto(lista, codigo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}