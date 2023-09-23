#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX 5
#define IA 0
#define MAX_TAMANHO_SENHA 50

const static char senhaGerente[] = "gerente";
const static char senhaCaixa[] = "caixa";
const static char senhaFrentista[] = "frentista";


typedef struct {
    int id;
    float preco;
    char nome[50];
    char validade[20];
} Produto;

int login() {
    int ent;
    char senha[MAX_TAMANHO_SENHA];


    printf("\n");
    printf("______________________________\n");
    printf("|============================| ");
    printf("\n|-Bem-vindo ao Posto Esquinão|\n");
    printf("|============================|\n");
    printf("|1. Entrar como Gerente      |\n");
    printf("|2. Entrar como Caixa        |\n");
    printf("|3. Entrar como Frentista    |\n");
    printf("|____________________________|\n");
    printf("Escolha uma op??o: ");
    scanf("%d", &ent);

    printf("Digite a senha: ");
    scanf("%s", &senha);

    if ((ent == 1 && strcmp(senha, senhaGerente) == 0) ||
        (ent == 2 && strcmp(senha, senhaCaixa) == 0) ||
        (ent == 3 && strcmp(senha, senhaFrentista) == 0)) {
        printf("\nLogin feito com sucesso!!");
        return ent;
    } else {
        printf("\nSenha incorreta");
        return -1;
    }
}

void insertInicio(Produto produto[], int *IL, int *FL) {
    for (int i = *FL; i >= *IL; i--) {
        produto[i + 1] = produto[i];
    }
    printf("\nDigite o id, o nome, o preço e a validade do produto: ");
    scanf("%d%s%f%s", &produto[*IL].id, &produto[*IL].nome, &produto[*IL].preco, &produto[*IL].validade);
    (*FL)++;
}

void insertMeio(Produto produto[], int *IL, int *FL, int k) {


    if (k < IA || k > *FL) {
        printf("\nPosição inválida. A posição deve estar entre %d e %d\n", IA, *FL);
        return;
    }
    k--;
    for (int i = *FL; i >= k; i--) {
        produto[i + 1] = produto[i];
    }
    printf("\nDigite o id, o nome, o preço e a validade do produto: ");
    scanf("%d%s%f%s", &produto[k].id, &produto[k].nome, &produto[k].preco, &produto[k].validade);
    (*FL)++;

}

void insertFim(Produto produto[], int *IL, int *FL) {
    int posicao = *FL;
    printf("\nDigite o id, o nome, o preço e a validade do produto: ");
    scanf("%d%s%f%s", &produto[posicao].id, &produto[posicao].nome, &produto[posicao].preco,
          &produto[posicao].validade);
    (*FL)++;
}

void insertProdutoEstoque(int ent, Produto produto[], int *IL, int *FL, int posicao) {
    int k;
    if (*FL == MAX) {
        printf("\nImpossível realizar a ação: Lista cheia\n");
        return;
    }

    if (ent == 3) {
        if (*FL == -1) {
            *FL = 0;
            *IL = 0;
        }
        if (posicao == 1) {
            insertInicio(produto, IL, FL);

        } else if (posicao == 2) {
            printf("\nDigite a posição onde deseja inserir o produto: ");
            scanf("%d", &k);
            insertMeio(produto, IL, FL, k);

        } else if (posicao == 3) {
            insertFim(produto, IL, FL);
        } else {
            printf("\nPosição desejada inválida.\n");
        }
    }
}

void ordenarPorID(Produto produto[], int FL) {
    //IMPLEMENTAR BUBBLESORT
    Produto aux;
    for (int i = 0; i < FL; ++i) {
        for (int j = 0; j < FL - i - 1; ++j) {
            if (produto[j].id > produto[j + 1].id) {
                aux = produto[j];
                produto[j] = produto[j + 1];
                produto[j + 1] = aux;
            }
        }
    }

}

void generateRelatorioEstoque(int ent, Produto produto[], int *IL, int *FL) {
    if (ent == 3) {
        printf("\nLista Completa: ");
        for (int i = *IL; i <= *FL - 1; i++) {
            printf("\nProduto - %d. Id: %d --- Nome: %s --- Preço: %.2f --- Validade: %s\n",
                   i + 1, produto[i].id, produto[i].nome, produto[i].preco, produto[i].validade);
        }
    }
    return;
}

void deleteById(int ent) {
    //IMPLEMENTAR DELETAR PELO CODIGO(ID) DO PRODUTO
    if (ent == 3) {

    }
    return;
}

void updateQuantidadeProdutoEstoque(int ent) {
    //IMPLEMENTAR ATUALIZAR A QUANDIDADE DE PRODUTOS NO ESTOQUE
    //DIMINUIR OU AUMENTAR A QUANDIDADE DE PRODUTOS EXISTENTES
    //SELECIONAR O PRODUTO PELO ID
    if (ent == 2 || ent == 3) {

    }
    return;
}

void generateRelatorioVenda(int ent) {
    //IMPLEMENTAR PRINTAR AS VENDAS QUE FORAM FEITAS
    if (ent == 3) {

    }
    return;
}

float insertCombustivel(int ent) {
    //IMPLEMENTAR AUMENTAR A QUANTIDADE DE COMBUST?VEL DO TANQUE
    if (ent == 3) {

    }
    return -1;
}

float generateRelatorioCaixa(int ent) {
    if (ent == 3) {

    }
    return -1;
}

float insertQuantidadeProdutoEstoque(int ent) {
    //IMPLEMENTAR AUMENTAR A QUANDIDADE DE UM PRODUTO NO ESTOQUE SELECIONADO PELO ID DELE
    if (ent == 2 || ent == 3) {

    }
    return -1;
}

float updatePrecoProduto(int ent) {
    //IMPLEMENTAR ATUALIZAR  O PRE?O DE UM PRODUTO SELECIONADO PELO ID DELE
    if (ent == 3) {

    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Produto produto[MAX];
    int ent, posicao = 0, IL = 0, FL = -1;

    ent = 3;//Valor definido para pular o sistema de login para facilitar testar o sistema
    //  ent = login();
    if (ent == -1) {
        return 0;
    }
    do {

        printf("\n---------------------------------------");
        printf("\nInforme onde deseja inserir o produto:");
        printf("\n\t0. Sair");
        printf("\n\t1. Início da lista\t");
        printf("\n\t2. Meio da lista\t");
        printf("\n\t3. Final da lista\t");
        printf("\n---------------------------------------");
        printf("\nPosição escolhida: ");
        scanf("%d", &posicao);
        if (posicao != 0) {
            insertProdutoEstoque(ent, produto, &IL, &FL, posicao);

        }
    } while (posicao != 0);
    ordenarPorID(produto, FL);
    generateRelatorioEstoque(ent, produto, &IL, &FL);

    return 0;
}