#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX 10
#define IA 0
#define MAX_TAMANHO_SENHA 50

const static char senhaGerente[] = "gerente";
const static char senhaCaixa[] = "caixa";
const static char senhaFrentista[] = "frentista";

// STRUCTS

typedef struct {
    int id;
    float preco;
    char nome[50];
    char validade;
    int qntd;

} Produto;

typedef struct {
    float litrosTanque;
    float limiteTanque;
    float litrosOleo;
    float limiteOleo;
    float litrosRadiador;
    float limiteRadiador;
    float calibrePneu;
    bool vidroSujo;
    char modelo;
    char cor;
    char ano;
} Carro;

typedef struct {
    char nome[50];
    int qntd;
    float precoU;
    float precoT;


} Historico;

// FUNÇÕES DE MENU


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

int menu() {
    int posicao;
    printf("\n---------------------------------------");
    printf("\nInforme onde deseja inserir o produto:");
    printf("\n\t0. Sair");
    printf("\n\t1. Início da lista");
    printf("\n\t2. Meio da lista");
    printf("\n\t3. Final da lista");
    printf("\n\t4. Deletar pelo ID");
    printf("\n\t5. Inserir Venda");
    printf("\n---------------------------------------");
    printf("\nPosição escolhida: ");
    scanf("%d", &posicao);
    return posicao;
}

// OPERAÇÕES DE INSERÇÃO

void generateNotaFiscal(int ent, Historico vendas[], int IH, int FH) {
    if (ent == 3) {

        float totalPreco = 0.0;

        for (int i = IH; i <= FH; ++i) {
            printf("\n\t|===========================|");
            printf("\n\t Produto: %s", vendas[i].nome);
            printf("\n\t Quantidade: %d", vendas[i].qntd);
            printf("\n\t Preço Unitário: %.2f", vendas[i].precoU);
            printf("\n\t Preço Total: %.2f", vendas[i].precoT);
            printf("\n\t|===========================|");
        }
    } else {
        printf("Você não possui as permissões nescessárias para realizar essa ação.");


        return;
    }

}

void insertVenda(Historico vendas[], Produto produto[], int *IH, int *FH, int FL) {
    int quantidadeVendida;
    char nomeProduto[50];

    printf("\nInforme o Nome do produto e a Quantidade vendida: ");
    scanf("%s%d", nomeProduto, &quantidadeVendida);

    bool produtoEncontrado = false;
    int posicao;

    for (int j = 0; j < FL; j++) {
        if (strcmp(produto[j].nome, nomeProduto) == 0) {
            produtoEncontrado = true;
            posicao = j;
            break;
        }
    }

    if (produtoEncontrado) {
        if (produto[posicao].qntd >= quantidadeVendida) {
            produto[posicao].qntd -= quantidadeVendida;

            vendas[*FH].qntd = quantidadeVendida;
            vendas[*FH].precoU = produto[posicao].preco;
            vendas[*FH].precoT = quantidadeVendida * produto[posicao].preco;
            strcpy(vendas[*FH].nome, produto[posicao].nome);

            (*IH)++;
            (*FH)++;

            printf("\nVenda registrada com sucesso!\n");

            generateNotaFiscal(3, vendas, *IH, *FH);

        } else {
            printf("\nQuantidade insuficiente no estoque para realizar a venda.\n");
        }
    } else {
        printf("\nProduto não encontrado.\n");
    }
}

void insertInicio(Produto produto[], int *IL, int *FL) {
    for (int i = *FL; i > *IL; i--) {
        produto[i] = produto[i - 1];
    }
    printf("\nDigite o Id, o Nome, o Preço, a Validade e a Quantidade do produto: ");
    scanf("%d%s%f%s%d", &produto[*IL].id, &produto[*IL].nome, &produto[*IL].preco, &produto[*IL].validade,
          &produto[*IL].qntd);

    for (int i = 0; i < *FL; i++) {
        if (produto[i].id == produto[*IL].id && i != *IL) {
            printf("\nProduto com o ID %d já existe. Insira um ID único.\n", produto[*IL].id);

            // Reverte a ação, movendo os elementos de volta
            for (int j = *IL; j < *FL; j++) {
                produto[j] = produto[j + 1];
            }
            return;
        }
    }

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
    printf("\nDigite o Id, o Nome, o Preço, a Validade e a Quantidade do produto: ");
    scanf("%d%s%f%s%d", &produto[k].id, &produto[k].nome, &produto[k].preco, &produto[k].validade, &produto[k].qntd);
    (*FL)++;

    for (int i = 0; i < *FL; i++) {
        if (produto[i].id == produto[k].id) {
            printf("\nProduto com o ID %d já existe. Insira um ID único.\n", produto[k].id);
            return;
        }
    }
}

void insertFim(Produto produto[], int *IL, int *FL) {
    int posicao = *FL;
    printf("\nDigite o Id, o Nome, o Preço, a Validade e a Quantidade do produto: ");
    scanf("%d%s%f%s%d", &produto[posicao].id, &produto[posicao].nome, &produto[posicao].preco,
          &produto[posicao].validade, &produto[posicao].qntd);

    for (int i = 0; i < *FL; i++) {
        if (produto[i].id == produto[posicao].id) {
            printf("\nProduto com o ID %d já existe. Insira um ID único.\n", produto[posicao].id);
            return;
        }
        (*FL)++;
    }
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
    } else {
        printf("Você não possui as permissões nescessárias para realizar essa ação.");
        return;
    }
}

float insertQuantidadeProdutoEstoque(int ent, Produto produto[], int *IL, int *FL) {
    //IMPLEMENTAR AUMENTAR A QUANDIDADE DE UM PRODUTO NO ESTOQUE SELECIONADO PELO ID DELE
    if (ent == 2 || ent == 3) {
        int id, maisQntd;
        bool idExiste = false;

        printf("\nInforme o ID do produto que desejas atualizar: ");
        scanf("%d", &id);

        for (int i = *IL; i < *FL; ++i) {
            if (produto[i].id == id) {
                idExiste = true;
                break;
            }
        }
        if (idExiste == true) {
            printf("\nQuantas unidades deseja adicionar no estoque: ");
            scanf("%d", &maisQntd);

            produto[id].qntd = produto[id].qntd + maisQntd;

        } else {
            printf("Id não encontrado...");
        }
    } else {
        printf("Você não possui as permissões nescessárias para realizar essa ação.");
        return -1;
    }
}

// OPERAÇÕES DE ORDENAÇÃO

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

// OPERAÇÕES DE GERAÇÃO

void generateRelatorioEstoque(int ent, Produto produto[], int *IL, int *FL) {
    if (ent == 3) {
        printf("\nLista Completa: ");
        for (int i = *IL; i <= *FL - 1; i++) {
            printf("\n{Produto - %d} --- [Id: %d] --- [Nome: %s] --- [Preço: %.2f] --- [Validade: %s] --- [Quantidade: %d]\n",
                   i + 1, produto[i].id, produto[i].nome, produto[i].preco, produto[i].validade, produto[i].qntd);
        }
    } else {
        printf("Você não possui as permissões nescessárias para realizar essa ação.");
        return;
    }
}


float generateRelatorioVendas(int ent, Historico vendas[], int *IH, int *FH) {
    //IMPLEMENTAR PRINTAR AS VENDAS QUE FORAM FEITAS
    if (ent == 3) {
        printf("\nHistórico de Vendas: ");
        for (int i = *IH; i <= *FH - 1; i++) {
            printf("\n[Produto: %s]--[Quantidade: %d]--[Preço Unitário: %.2f]--[Preço Total: %.2f]\n",
                   vendas[i].nome,
                   vendas[i].qntd, vendas[i].precoU, vendas[i].precoT);
        }
    } else {
        printf("Você não possui as permissões nescessárias para realizar essa ação.");
        return -1;
    }
    return -1;
}

// OPERAÇÕES DE EXCLUSÃO

void deleteById(int ent, Produto produto[], int *IL, int *FL) {
    if (ent == 3) {
        int id, posicao = -1;

        printf("\nInforme o ID do produto que desejas deletar: ");
        scanf("%d", &id);

        for (int i = *IL; i < *FL; ++i) {
            if (produto[i].id == id) {
                posicao = i;
                break;
            }
        }

        if (posicao != -1) {
            for (int i = posicao; i < *FL - 1; i++) {
                produto[i] = produto[i + 1];
            }
            (*FL)--;
            printf("\nProduto com o ID %d deletado com sucesso.\n", id);
        } else {
            printf("Produto com o ID %d não encontrado.\n", id);
        }
    } else {
        printf("Você não possui as permissões necessárias para realizar essa ação.\n");
    }

}

// OPERAÇÕES DE ATUALIZAÇÃO

void updateQuantidadeProdutoEstoque(int ent, Produto produto[], int *IL, int *FL) {
    //IMPLEMENTAR ATUALIZAR A QUANDIDADE DE PRODUTOS NO ESTOQUE
    //DIMINUIR OU AUMENTAR A QUANDIDADE DE PRODUTOS EXISTENTES
    //SELECIONAR O PRODUTO PELO ID
    if (ent == 2 || ent == 3) {
        int id, newQntd;
        bool idExiste = false;

        printf("\nInforme o ID do produto que desejas atualizar: ");
        scanf("%d", &id);

        for (int i = *IL; i < *FL; ++i) {
            if (produto[i].id == id) {
                idExiste = true;
                break;
            }
        }
        if (idExiste == true) {
            printf("\n{Quantidade atual: %d}\nQuantidade desejada: ", produto[id].qntd);
            scanf("%d", &newQntd);

            produto[id].qntd = newQntd;

        } else {
            printf("Id não encontrado...");
        }
    } else {
        printf("Você não possui as permissões nescessárias para realizar essa ação.");
        return;
    }
}

float updatePrecoProduto(int ent, Produto produto[], int *IL, int *FL) {
    //IMPLEMENTAR ATUALIZAR  O PRE?O DE UM PRODUTO SELECIONADO PELO ID DELE

    if (ent == 3) {
        int id;
        float newPreco;
        bool idExiste = false;

        printf("\nInforme o ID do produto que desejas atualizar: ");
        scanf("%d", &id);

        for (int i = *IL; i < *FL; ++i) {
            if (produto[i].id == id) {
                idExiste = true;
                break;
            }
        }
        if (idExiste == true) {
            printf("\nInforme o novo preço do produto: R$");
            scanf("%f", &newPreco);

            produto[id].preco = newPreco;

        } else {
            printf("Id não encontrado...");
        }

    } else {
        printf("Você não possui as permissões nescessárias para realizar essa ação.");
        return -1;
    }
}

// INTERAÇÃO COM VEÍCULO

double sortearCombustivel()
{
    double combustivel = (double)rand() / RAND_MAX * 56.0;
    return combustivel;
}
double sortearCalibragem(){
    double calibragem = (double)rand() / RAND_MAX * 36.0;
    return calibragem;
}
bool sortearVidro()
{
    int vidro = rand() % 2;
    if(vidro == 0)
    {
        return false;
    }
    else if (vidro == 1)
    {
        return true;
    }
}
char sortearModelo()
{
    int carro = rand() % 10;
    switch(carro)
    {
        case 1:
            return 'Monza';
            break;
        case 2:
            return 'Astra';
            break;
        case 3:
            return 'Hilux';
            break;
        case 4:
            return 'Uno';
            break;
        case 5:
            return 'Gol';
            break;
        case 6:
            return 'Mobi';
            break;
        case 7:
            return 'Up';
            break;
        case 8:
            return 'Palio';
            break;
        case 9:
            return 'Argo';
            break;
        case 10:
            return 'Onyx';
            break;
    }
}
char sortearCor()
{
    int cor = rand() % 5;
    switch(cor)
    {
        case 1:
            return 'Preto';
            break;
        case 2:
            return 'Prata';
            break;
        case 3:
            return 'Branco';
            break;
        case 4:
            return 'Vermelho';
            break;
        case 5:
            return 'Azul';
            break;
    }
}
char sortearAno()
{
    int ano = rand() % 24 + 2000;
    return ano;
}
int novoCliente()
{
    int cliente = rand() % 10;
    return cliente;
}

// int i = novoCliente();
// printf("\nUM NOVO CLIENTE CHEGOU!\n[Modelo: %s]--[Cor: %s]--[Motor: %f]--[Ano: %d]--[Tanque: %.2f l]--[Pneus: %.2f lbs]--[Vidros: ]");

void encherTanque(int ent, Carro carros[], int indice)
{
    float combustivel;
    if (carros[indice].litrosTanque != carros[indice].limiteTanque)
    {
        printf("\n[Capacidade do Tanque: %f]--[Litros atuais: %.2f]\nInforme quantos litros de combustível deseja adicionar ao tanque: "
                , carros[indice].limiteTanque, carros[indice].litrosTanque);
        scanf("%f", &combustivel);

        carros[indice].litrosTanque = carros[indice].litrosTanque + combustivel;
    }
    else
    {
        printf("O Tanque está cheio!");
    }
}
void calibrarPneu(int ent, Carro carros[], int indice)
{
    float libras;
    printf("\n[Parâmetros:[0 a 20: Murcho]--[26 a 35: Ideal]\n[Libras atuais: %.2f]\nInforme quantas libras deseja adicionar à calibragem do pneu: "
            , carros[indice].calibrePneu);
    scanf("%f", &libras);

    carros[indice].calibrePneu = carros[indice].calibrePneu + libras;

}
void limparVidro(int ent, Carro carros[], int indice)
{
    if(carros[indice].vidroSujo == true)
    {
        carros[indice].vidroSujo = false;
    }
    else
    {
        printf("O Vidro já está limpo!");
    }

}
void preencherClientes(Carro carros[])
{
    for(int x = 0; x<=9; x++)
    {
        carros[x].modelo = sortearModelo();
        carros[x].cor = sortearCor();
        carros[x].ano = sortearAno();
        carros[x].litrosTanque = sortearCombustivel();
        carros[x].limiteTanque = 72;
        carros[x].calibrePneu = sortearCalibragem();
        carros[x].vidroSujo = sortearVidro();

        x++;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Produto produto[MAX];
    Historico vendas[MAX];
    Carro carros[10];
    int ent, posicao, IL = 0, FL = 0;
    int IH = 0, FH = 0;
    char resposta[MAX];

    ent = 3;//Valor definido para pular o sistema de login para facilitar testar o sistema
    //  ent = login();
    if (ent == -1) {
        return 0;
    }
    do {
        posicao = menu();
        switch (posicao) {
            case 1:
            case 2:
            case 3:
                insertProdutoEstoque(ent, produto, &IL, &FL, posicao);
                break;
            case 4:
                deleteById(ent, produto, &IL, &FL);
                break;
            case 5:
                insertVenda(vendas, produto, &IH, &FH, FL);
                break;
        }
        ordenarPorID(produto, FL);
        generateRelatorioEstoque(ent, produto, &IL, &FL);
    } while (posicao != 0);


    return 0;
}
