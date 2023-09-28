#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NULL ((void *)0)
#define MAX 50
#define IA 0
#define MAX_TAMANHO_SENHA 50

//defini��o das senhas
const static char senhaGerente[] = "gerente";
const static char senhaCaixa[] = "caixa";
const static char senhaFrentista[] = "frentista";

//STRUCTS
typedef struct {
    int id;
    float preco;
    char nome[50];
    char validade[20];
    int qntd;
} Produto;

typedef struct {
    float litrosTanque;
    float limiteTanque;
    float calibrePneu;
    bool vidroSujo;
    char modelo[15];
    char cor[15];
    int ano;
} Carro;

typedef struct {
    char nome[50];
    int qntd;
    float precoU;
    float precoT;
} Historico;


// FUN��ES DE MENU
int login() {
    int ent;
    char senha[MAX_TAMANHO_SENHA];
    do {
        printf("\n");
        printf("______________________________\n");
        printf("|============================| ");
        printf("\n|-Bem-vindo ao Posto Esquin�o|\n");
        printf("|============================|\n");
        printf("|1. Entrar como Gerente      |\n");
        printf("|2. Entrar como Caixa        |\n");
        printf("|3. Entrar como Frentista    |\n");
        printf("|____________________________|\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &ent);

        //Verifica se a op��o escolhida est� de acordo com a interface
        if (ent == 1 || ent == 2 || ent == 3) {
            printf("Digite a senha: ");
            scanf("%s", &senha);

            //Veririfa se a senha est� correta
            if ((ent == 1 && strcmp(senha, senhaGerente) == 0) ||
                (ent == 2 && strcmp(senha, senhaCaixa) == 0) ||
                (ent == 3 && strcmp(senha, senhaFrentista) == 0)) {
                printf("\nLogin feito com sucesso!!");
                return ent;
            } else {
                printf("\nSenha incorreta. Tente novamente.");
            }
        } else {
            printf("\nOp��o inv�lida, selecione outra.");
        }
    } while (1 || 2 || 3);
}

int menu() {
    int posicao;
    printf("\n---------------------------------------");
    printf("\nAc�es do gerente ou caixa:");
    printf("\n\t0. Gerar relat�rio do estoque");
    printf("\n\t1. In�cio da lista (Apenas gerente)");
    printf("\n\t2. Meio da lista (Apenas gerente)");
    printf("\n\t3. Final da lista (Apenas gerente)");
    printf("\n\t4. Deletar pelo ID (Apenas gerente)");
    printf("\n\t5. Comprar produto(Apenas gerente)");
    printf("\n\t6. Ordenar por Id(Apenas gerente)");
    printf("\n\t7. Inserir Venda");
    printf("\n\t8. Atualizar quantidade do produto");
    printf("\n\t9. Atualizar o pre�o do produto");
    printf("\n\t10. Gerar relat�rio de vendas");
    printf("\n\t11. Consultar produto pelo ID");
    printf("\n\t12. Sair");
    printf("\n---------------------------------------");
    printf("\nPosi��o escolhida: ");
    scanf("%d", &posicao);
    return posicao;
}

int menuFrentista() {
    int posicao;
    printf("\n---------------------------------------");
    printf("\nA��es do frentista:");
    printf("\n\t0. Sair");
    printf("\n\t1. Encher tanque");
    printf("\n\t2. Calibrar pneus");
    printf("\n\t3. Limpar vidros");
    printf("\n\t4. Chamar novo cliente");
    printf("\n---------------------------------------");
    printf("\nPosi��o escolhida: ");
    scanf("%d", &posicao);
    return posicao;
}

// OPERA��ES DE GERA��O

void generateNotaFiscal(Historico vendas[], int IH, int FH) {
    float preco_final;
    //Printa a nota fiscal de acordo com o tamanho do 'Hist�rico'(lista)
    for (int i = IH; i < FH; i++) {
        preco_final = preco_final + vendas[i].precoT;
        printf("\n\t|=========NOTA FISCAL===========|");
        printf("\n\t| Produto: %s\t\t|", vendas[i].nome);
        printf("\n\t| Quantidade: %d\t\t|", vendas[i].qntd);
        printf("\n\t| Pre�o Unit�rio: %.2f\t\t|", vendas[i].precoU);
        printf("\n\t| Pre�o Total: %.2f\t\t|", vendas[i].precoT);
        printf("\n\t|===============================|");
        printf("\n\t| Pre�o Final: %.2f\t\t|", preco_final);
        printf("\n\t|===============================|");
    }
}

void generateRelatorioEstoque(Produto produto[], int *IL, int *FL) {
    printf("\nRelat�rio de Estoque: ");
    //Verifica se a lista n�o est� vazia
    if (*FL == 0) {
        printf("\nEstoque vazio. :(");
    }
    //Printa a lista
    for (int i = *IL; i <= *FL - 1; i++) {
        printf("\n{Produto - %d} --- [Id: %d] --- [Nome: %s] --- [Pre�o: %.2f] --- [Validade: %s] --- [Quantidade: "
               "%d]",
               i + 1, produto[i].id, produto[i].nome, produto[i].preco, produto[i].validade, produto[i].qntd);
    }
}

void generateRelatorioVendas(Historico vendas[], int *IH, int *FH) {
    printf("\nHist�rico de Vendas: ");
    //Verifica se a lista n�o est� vaiza
    if (*FH == 0) {
        printf("\nNenhuma venda efetuada at� o momento.");
    }
    //Printa a lista
    for (int i = *IH; i < *FH; i++) {
        printf("\n[Produto: %s]--[Quantidade: %d]--[Pre�o Unit�rio: %.2f]--[Pre�o Total: %.2f]\n", vendas[i].nome,
               vendas[i].qntd, vendas[i].precoU, vendas[i].precoT);
    }
}

int procurarProdutoPorID(Produto produto[], int *IL, int *FL, int id) {
    //percorre a lista procurando o ID informado
    for (int i = *IL; i < *FL; ++i) {
        if (produto[i].id == id) {
            return i;  // Retorna a posi��o do produto com o ID
        }
    }
    return -1;  // Retorna -1 se o produto n�o for encontrado
}

void consultarPorID(Produto produto[], int *IL, int *FL) {

    int id, posicao = -1;
    printf("\nInforme o ID do produto para a busca: ");
    scanf("%d", &id);

    //Procura na lista a posi��o informada
    posicao = procurarProdutoPorID(produto, IL, FL, id);


    //Verifica se a posi��o foi encontrada
    if (posicao != -1) {
        printf("\n{Produto - %d} --- [Id: %d] --- [Nome: %s] --- [Pre�o: %.2f] --- [Validade: %s] --- [Quantidade: "
               "%d]\n",
               posicao + 1, produto[posicao].id, produto[posicao].nome, produto[posicao].preco,
               produto[posicao].validade,
               produto[posicao].qntd);

    } else {
        printf("Produto com o ID %d n�o encontrado.\n", id);
    }

}

//serve para simular um banco de dados para o Caixa poder realizar suas a��es
// j� que n�o tem a permiss�o de inserir elementos na lista
void inicializarProdutosPreDefinidos(Produto produto[], int FL, int totalProdutosPreDefinidos) {
    Produto produtosPreDefinidos[] =
            {
                    {1, 32.0,  "Filtro",     "31/12/2025", 132},
                    {2, 78.0,  "Palheta",    "10/08/2025", 36},
                    {3, 61.0,  "Oleo_1L",    "13/11/2027", 200},
                    {4, 170.0, "Oleo_3L",    "06/09/2028", 120},
                    {5, 12.0,  "Refri_2L",   "27/02/2024", 43},
                    {6, 30.0,  "Salgadinho", "16/03/2024", 17},
                    {7, 25.0,  "Bolacha",    "02/03/2024", 300}
            };
    //Insere os valores na lista
    for (int i = 0; i < totalProdutosPreDefinidos; i++) {
        produto[i] = produtosPreDefinidos[i];
        FL++;
    }
}

// OPERA��ES DE INSER��O

void insertVenda(Historico vendas[], Produto produto[], int *IH, int *FH, int FL, char resposta[]) {
    int quantidadeVendida;

    char nomeProduto[50];

    printf("\nInforme o Nome do produto e a Quantidade vendida: ");
    scanf("%s%d", nomeProduto, &quantidadeVendida);

    bool produtoEncontrado = false;
    int posicao;

    //procuta a informa��o desejada pelo nome na lista
    for (int j = 0; j < FL; j++) {
        if (strcmp(produto[j].nome, nomeProduto) == 0) {
            produtoEncontrado = true;
            posicao = j;
            break;
        }
    }
    if (produtoEncontrado) {
        //verifica se a quantidade no estoque � maior que a quantidade informada para ser vendida
        if (produto[posicao].qntd >= quantidadeVendida) {
            produto[posicao].qntd -= quantidadeVendida;//subtrai a quantidade desejada

            //realoca as informa��es para as respectivas vari�veis
            vendas[*FH].qntd = quantidadeVendida;
            vendas[*FH].precoU = produto[posicao].preco;
            vendas[*FH].precoT = quantidadeVendida * produto[posicao].preco;
            strcpy(vendas[*FH].nome, produto[posicao].nome);//Maneira de copiar um string para outra string

            (*FH)++;

            //verifica se a resposta � diferente de 'n'/'N'
            if (strcmp(resposta, "n") != 0 && strcmp(resposta, "N") != 0) {
                generateNotaFiscal(vendas, *IH, *FH);
            }
            printf("\nVenda registrada com sucesso!\n");
        } else {
            printf("\nQuantidade insuficiente no estoque para realizar a venda.\n");
        }
    } else {
        printf("\nProduto n�o encontrado.\n");
    }
}

void insertInicio(Produto produto[], int *IL, int *FL) {
    //est� percorrendo a lista come�ando pelo final e realocando as informa��es para a 'direita'
    // abrindo espa�o para inserir valores no inicio
    for (int i = *FL; i > *IL; i--) {
        produto[i] = produto[i - 1];
    }
    printf("\nDigite o Id, o Nome, o Pre�o, a Validade e a Quantidade do produto: ");
    scanf("%d%s%f%s%d", &produto[*IL].id, &produto[*IL].nome, &produto[*IL].preco, &produto[*IL].validade,
          &produto[*IL].qntd);

    for (int i = 0; i < *FL; i++) {
        //verifica se a informa��o a ser inserida ja existe na lista
        if (produto[i].id == produto[*IL].id && i != *IL) {
            printf("\nProduto com o ID %d j� existe. Insira um ID �nico.\n", produto[*IL].id);

            // Reverte a a��o, movendo os elementos de volta
            for (int j = *IL; j < *FL; j++) {
                produto[j] = produto[j + 1];
            }
            return;
        }
    }
    (*FL)++;
}

void insertMeio(Produto produto[], int *IL, int *FL, int k) {
    //verifica se a posi��o � valida (se � entre 2 valores)
    if (k < IA || k > *FL) {
        printf("\nPosi��o inv�lida. A posi��o deve estar entre %d e %d\n", IA, *FL);
        return;
    }
    k--;
    //desloca os elementos da lista para abrir espa�o para o 'k'
    for (int i = *FL; i >= k; i--) {
        produto[i + 1] = produto[i];
    }
    printf("\nDigite o Id, o Nome, o Pre�o, a Validade e a Quantidade do produto: ");
    scanf("%d%s%f%s%d", &produto[k].id, &produto[k].nome, &produto[k].preco, &produto[k].validade,
          &produto[k].qntd);


    for (int i = 0; i < *FL; i++) {
        //verifica se a informa��o a ser inserida ja existe na lista
        if (produto[i].id == produto[*IL].id && i != *IL) {
            printf("\nProduto com o ID %d j� existe. Insira um ID �nico.\n", produto[*IL].id);

            // Reverte a a��o, movendo os elementos de volta
            for (int j = *IL; j < *FL; j++) {
                produto[j] = produto[j + 1];
            }
            return;
        }
    }
    (*FL)++;
}

void insertFim(Produto produto[], int *IL, int *FL) {
    int posicao = *FL;
    printf("\nDigite o Id, o Nome, o Pre�o, a Validade e a Quantidade do produto: ");
    scanf("%d%s%f%s%d", &produto[posicao].id, &produto[posicao].nome, &produto[posicao].preco,
          &produto[posicao].validade, &produto[posicao].qntd);

    for (int i = 0; i < *FL; i++) {
        //verifica se a informa��o a ser inserida ja existe na lista
        if (produto[i].id == produto[*IL].id && i != *IL) {
            printf("\nProduto com o ID %d j� existe. Insira um ID �nico.\n", produto[*IL].id);

            // Reverte a a��o, movendo os elementos de volta
            for (int j = *IL; j < *FL; j++) {
                produto[j] = produto[j + 1];
            }
            return;
        }
    }
    (*FL)++;
}

void insertProdutoEstoque(int ent, Produto produto[], int *IL, int *FL, int posicao) {
    int k;
    //verifica se a lista est� cheia
    if (*FL == MAX) {
        printf("\nImposs�vel realizar a a��o: Lista cheia\n");
        return;
    }
    //Verifica se foi logado com a entidade gerente, para poder executar essas a��es
    if (ent == 1) {
        //verifica qual a posi��o selecionada pra inserir os elementos e chama o respectivo m�todo
        if (posicao == 1) {
            insertInicio(produto, IL, FL);

        } else if (posicao == 2) {
            printf("\nDigite a posi��o onde deseja inserir o produto: ");
            scanf("%d", &k);
            insertMeio(produto, IL, FL, k);
        } else if (posicao == 3) {
            insertFim(produto, IL, FL);
        } else {
            printf("\nPosi��o desejada inv�lida.\n");
        }
    } else {
        printf("Voc� n�o possui as permiss�es nescess�rias para realizar essa a��o.");
        return;
    }
}

//sorteia um valor entre 0 a 9 inclusive
int sortearDia() {
    int dia = rand() % 10;
    return dia;
}

void insertQuantidadeProdutoEstoque(Produto produto[], int *IL, int *FL) {
    int id, maisQntd, posicao = -1;

    for (int i = *IL; i <= *FL - 1; i++) {
        printf("\n{Produto - %d} --- [Id: %d] --- [Nome: %s] --- [Quantidade: %d]", i + 1, produto[i].id,
               produto[i].nome, produto[i].qntd);
    }
    printf("\nInforme o ID do produto que desejas comprar: ");
    scanf("%d", &id);

    //procuta a informa��o desejada na lista
    posicao = procurarProdutoPorID(produto, IL, FL, id);

    if (posicao != -1) {
        printf("\nQuantas unidades deseja adicionar ao estoque: ");
        scanf("%d", &maisQntd);

        if (maisQntd > 0) {
            //adicioa a quantidade informada a quantidade ja existente
            produto[id - 1].qntd = produto[id - 1].qntd + maisQntd;
            printf("\nSua compra chegar� em %d dias.", sortearDia());

        } else {
            printf("\nValor inv�lido.");
        }
    } else {
        printf("Id n�o encontrado...");
    }
}

// OPERA��ES DE ORDENA��O

void ordenarPorID(int ent, Produto produto[], int FL) {
    //verifica se foi logado como gerente
    if (ent == 1) {
        Produto aux;
        //executa o bubble sort para organizar os elementos de acordo com o id
        for (int i = 0; i < FL; ++i) {
            for (int j = 0; j < FL - i - 1; ++j) {
                if (produto[j].id > produto[j + 1].id) {
                    aux = produto[j];
                    produto[j] = produto[j + 1];
                    produto[j + 1] = aux;
                }
            }
        }
        printf("\nOrdena��o por ID conclu�da.");
    }
}

// OPERA��ES DE EXCLUS�O

void deleteById(int ent, Produto produto[], int *IL, int *FL) {
    if (ent == 1) {
        int id, posicao = -1;
        for (int i = *IL; i <= *FL - 1; i++) {
            printf("\n{Produto - %d} --- [Id: %d] --- [Nome: %s]", i + 1, produto[i].id, produto[i].nome);
        }
        printf("\nInforme o ID do produto que desejas deletar: ");
        scanf("%d", &id);

        //procuta a informa��o desejada na lista
        posicao = procurarProdutoPorID(produto, IL, FL, id);

        if (posicao != -1) {
            // Move os produtos uma posi��o para tr�s a partir da posi��o do produto a ser exclu�do
            for (int i = posicao; i < *FL - 1; i++) {
                produto[i] = produto[i + 1];
            }
            (*FL)--;// Reduz o tamanho da lista para refletir a exclus�o
            printf("\nProduto com o ID %d deletado com sucesso.\n", id);
        } else {
            printf("Produto com o ID %d n�o encontrado.\n", id);
        }
    } else {
        printf("Voc� n�o possui as permiss�es necess�rias para realizar essa a��o.\n");
    }

}

// OPERA��ES DE ATUALIZA��O

void updateQuantidadeProdutoEstoque(int ent, Produto produto[], int *IL, int *FL) {
    if (ent == 1 || ent == 2) {
        int id, newQntd, posicao = -1;

        for (int i = *IL; i <= *FL - 1; i++) {
            printf("\n{Produto - %d} --- [Id: %d] --- [Nome: %s] --- [Quantidade: %d]", i + 1, produto[i].id,
                   produto[i].nome, produto[i].qntd);
        }
        printf("\nInforme o ID do produto que desejas atualizar a quantidade: ");
        scanf("%d", &id);

        //procuta a informa��o desejada na lista
        posicao = procurarProdutoPorID(produto, IL, FL, id);

        if (posicao != -1) {
            printf("\nQuantidade desejada: ");
            scanf("%d", &newQntd);
            if (newQntd >= 0) {
                //substitui a quantidade antiga pela nova informada
                produto[id - 1].qntd = newQntd;
            } else {
                printf("Quantidade inv�lida!");
            }

        } else {
            printf("Id n�o encontrado...");
        }
    }
}

void updatePrecoProduto(Produto produto[], int *IL, int *FL) {
    int id, posicao = -1;
    float newPreco;

    for (int i = *IL; i <= *FL - 1; i++) {
        printf("\n{Produto - %d} --- [Id: %d] --- [Nome: %s] --- [Pre�o: %.2f]", i + 1, produto[i].id, produto[i].nome,
               produto[i].preco);
    }
    printf("\nInforme o ID do produto que desejas atualizar: ");
    scanf("%d", &id);

    //procuta a informa��o desejada na lista
    posicao = procurarProdutoPorID(produto, IL, FL, id);

    if (posicao != -1) {
        printf("\nInforme o novo pre�o do produto: R$");
        scanf("%f", &newPreco);
        if (newPreco >= 0) {
            //substitui o pre�o antigo pelo novo informado
            produto[id - 1].preco = newPreco;
        } else {
            printf("Pre�o inv�lido!");
        }
    } else {
        printf("Id n�o encontrado...");
    }
}

// INTERA��O COM VE�CULO

//sorteina um n�mero entre 0 e 56(este n�o incluso)
double sortearCombustivel() {
    double combustivel = (double) rand() / RAND_MAX * 56.0;
    return combustivel;
}

//sorteina um n�mero entre 0 e 36(este n�o incluso)
double sortearCalibragem() {
    double calibragem = (double) rand() / RAND_MAX * 36.0;
    return calibragem;
}

//retorna um n�mero entre 0 e 1
bool sortearVidro() {
    int vidro = rand() % 2;
    if (vidro == 0) {
        return false;
    } else if (vidro == 1) {
        return true;
    }
    return NULL;//retorna null se a a��o acima n�o ocorrer(altamente improv�vel)
}

//sorteia um n�mero entre 1 a 10 inclusive e entra em um dos casos pr� definidos
char *sortearModelo() {
    int carro = rand() % 10 + 1;
    switch (carro) {
        case 1:
            return "Monza";
            break;
        case 2:
            return "Astra";
            break;
        case 3:
            return "Hilux";
            break;
        case 4:
            return "Uno";
            break;
        case 5:
            return "Gol";
            break;
        case 6:
            return "Mobi";
            break;
        case 7:
            return "Up";
            break;
        case 8:
            return "Palio";
            break;
        case 9:
            return "Argo";
            break;
        case 10:
            return "Onyx";
            break;
    }
    return NULL;// altamente improv�vel de acontecer
}

//sorteia um n�mero entre 1 a 5 inclusive e entra em 1 dos casos pr� definidos
char *sortearCor() {
    int cor = rand() % 5 + 1;
    switch (cor) {
        case 1:
            return "Preto";
            break;
        case 2:
            return "Prata";
            break;
        case 3:
            return "Branco";
            break;
        case 4:
            return "Vermelho";
            break;
        case 5:
            return "Azul";
            break;
    }
    return NULL;// altamente improv�vel de acontecer
}

//sorteia um valor entre 2000 e 2023
int sortearAno() {
    int ano = rand() % 24 + 2000;
    return ano;
}

//sorteia um n�mero entre 0 a 9 inclusive
int novoCliente() {
    int cliente = rand() % 10;
    return cliente;
}

float encherTanque(Carro carros[], int indice, float valorTanque) {
    float combustivel, total;

    // verifica se os litros do tanque s�o diferentes da capacidade m�xima do tanque
    if (carros[indice].litrosTanque != carros[indice].limiteTanque) {
        printf("\n[Capacidade do Tanque: %.2f]--[Litros atuais: %.2f]\nInforme quantos litros de combust�vel deseja "
               "adicionar ao tanque: ",
               carros[indice].limiteTanque, carros[indice].litrosTanque);
        scanf("%f", &combustivel);

        if (combustivel > 0) {
            //verifica se os litros que j� est�o no tanque + os adicionados s�o menores que o limite do tanque
            if (carros[indice].litrosTanque + combustivel < carros[indice].limiteTanque) {
                //adiciona os litros adicionais no tanque
                carros[indice].litrosTanque = carros[indice].litrosTanque + combustivel;
                //subtrai os litros adicionados da capacidade total do tanque
                valorTanque = valorTanque - combustivel;
                if (valorTanque < 2000) {
                    printf("\nN�vel de combust�vel escasso. Ligar para o Teg�o!");
                }
                total = combustivel * 5.99;
                printf("\nTanque abastecido! O tanque agora tem %.2f litros.", carros[indice].litrosTanque);
                printf("\nValor � pagar pelo combust�vel: R$%.2f", total);
            } else {
                printf("\nImpossivel abastecer! Vai derramar!!!");
            }
        } else {
            printf("\nValor inv�lido.");
        }
    } else {
        printf("\nO Tanque est� cheio!");
    }
    return valorTanque;
}

void calibrarPneu(Carro carros[], int indice) {
    float totalLibras = 0;
    float libras;
    printf("\nPar�metros:[0 a 20: Murcho]--[26 a 35: Ideal]\n[Libras atuais: %.2f]\nInforme quantas libras deseja adicionar � calibragem do pneu: ",
           carros[indice].calibrePneu);
    scanf("%f", &libras);

    if (libras > 0) {
        //adiciona as libras informadas as j� existentes
        totalLibras = carros[indice].calibrePneu + libras;
        carros[indice].calibrePneu = totalLibras;

        if (totalLibras > 36) {
            printf("\nImposs�vel colocar essa quantidade.");
            return;
        }
        printf("\nPneus calibrados! Agora est�o com %.2f libras.", carros[indice].calibrePneu);
    } else {
        printf("\nValor inv�lido.");
    }
    return;
}

void limparVidro(Carro carros[], int indice) {
    if (carros[indice].vidroSujo == true) {
        carros[indice].vidroSujo = false;
        printf("\nOs vidros foram limpos!");
    } else {
        printf("\nO Vidro j� est� limpo!");
    }

}

void preencherClientes(Carro carros[]) {
    //Junta todos os m�todos de sorteio para atribuir os valores para as posi��es correspondentes na lista de 'carros'
    for (int x = 0; x < 10; x++) {
        strcpy(carros[x].modelo, sortearModelo());
        strcpy(carros[x].cor, sortearCor());

        carros[x].ano = sortearAno();
        carros[x].litrosTanque = sortearCombustivel();
        carros[x].limiteTanque = 72;
        carros[x].calibrePneu = sortearCalibragem();
        carros[x].vidroSujo = sortearVidro();

    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Produto produto[MAX];
    Historico vendas[MAX];
    Carro carros[10];
    char resposta[10];
    int ent, posicao, IL = 0;
    int IH = 0, FH = 0, FL = 0;
    float tanque_posto = 3000;

    //executa o login
    ent = login();
    if (ent == 2) {

        int totalProdutosPreDefinidos = 7;

        FL = totalProdutosPreDefinidos;
        //inicializa a lista pr� definida acrescentando seus elementos na lista de produtos
        inicializarProdutosPreDefinidos(produto, FL, totalProdutosPreDefinidos);
    }
    //verifica se o login foi feito com o gerente(1) ou com o caixa(2)
    if (ent == 1 || ent == 2) {
        do {
            //executa o menu
            posicao = menu();
            switch (posicao) {
                case 0:
                    generateRelatorioEstoque(produto, &IL, &FL);
                    break;
                case 1:
                case 2:
                case 3:
                    insertProdutoEstoque(ent, produto, &IL, &FL, posicao);
                    break;
                case 4:
                    deleteById(ent, produto, &IL, &FL);
                    break;
                case 5:
                    insertQuantidadeProdutoEstoque(produto, &IL, &FL);
                    break;
                case 6:
                    ordenarPorID(ent, produto, FL);
                    break;
                case 7:
                    do {
                        //fica em um loop de vendas at� que a resposta seja 'n'/'N'
                        insertVenda(vendas, produto, &IH, &FH, FL, resposta);
                        printf("Deseja continuar inserindo vendas?(Y/N)");
                        fflush(stdin);
                        scanf("%s", resposta);
                    } while (strcmp(resposta, "n") != 0 && strcmp(resposta, "N") != 0);
                    break;
                case 8:
                    updateQuantidadeProdutoEstoque(ent, produto, &IL, &FL);
                    break;
                case 9:
                    updatePrecoProduto(produto, &IL, &FL);
                    break;
                case 10:
                    generateRelatorioVendas(vendas, &IH, &FH);
                    break;
                case 11:
                    consultarPorID(produto, &IL, &FL);
                    break;
                default:
                    printf("\nOp��o inv�lida, selecione outra.");
            }
        } while (posicao != 12);
    }
    //verifica se o login foi feito como frentista(3)
    if (ent == 3) {
        int posicaoFrentista;

        int i = novoCliente();
        //executa a cria��o de um novo carro com informa��es aleat�rias
        preencherClientes(carros);

        printf("\n\nUM NOVO CLIENTE CHEGOU!\n[Modelo: %s]--[Cor: %s]--[Ano: %d]--[Tanque: %.2f l]--[Pneus: %.2f lbs]--[Vidros: %s]",
               carros[i].modelo, carros[i].cor, carros[i].ano, carros[i].litrosTanque, carros[i].calibrePneu,
               carros[i].vidroSujo ? "Sujo" : "Limpo");//utiliza o operador tern�rio para simplificar um if-else

        do {
            //executa o menu separado para o frentista
            posicao = menuFrentista();

            switch (posicao) {
                case 1:
                    tanque_posto = encherTanque(carros, i, tanque_posto);
                    break;
                case 2:
                    calibrarPneu(carros, i);
                    break;
                case 3:
                    limparVidro(carros, i);
                    break;
                case 4:
                    //chama um novo cliente
                    i = novoCliente();
                    printf("\n\nUM NOVO CLIENTE CHEGOU!\n[Modelo: %s]--[Cor: %s]--[Ano: %d]--[Tanque: %.2f l]--[Pneus: %.2f "
                           "lbs]--[Vidros: %s]",
                           carros[i].modelo, carros[i].cor, carros[i].ano, carros[i].litrosTanque,
                           carros[i].calibrePneu,
                           carros[i].vidroSujo ? "Sujo" : "Limpo");
                    break;
                default:
                    printf("\nOp��o inv�lida, selecione outra.");
            }

        } while (posicao != 0);

    }
    return 0;
}