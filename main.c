#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    char senha[30];


    printf("\n");
    printf("______________________________\n");
    printf("|============================| ");
    printf("\n|-Bem-vindo ao Posto Esquinão|\n");
    printf("|============================|\n");
    printf("|1. Entrar como Gerente      |\n");
    printf("|2. Entrar como Caixa        |\n");
    printf("|3. Entrar como Frentista    |\n");
    printf("|____________________________|\n");
    printf("Escolha uma opção: ");
    scanf("%d", &ent);

    printf("Digite a senha: ");
    scanf("%s", &senha);

    if (strcmp(senha, senhaCaixa) == 0&& ent == 2) {
        printf("Login feito com sucesso!!");
        return ent;
    } else if (strcmp(senha, senhaGerente) == 0&& ent == 1) {
        printf("Login feito com sucesso!!");
        return ent;
    } else if (strcmp(senha, senhaFrentista) == 0&& ent == 3) {
        printf("Login feito com sucesso!!");
        return ent;
    } else {
        printf("Senha incorreta");
    }
    return 0;
}
void deleteById(int ent);

void updateQuantidadeProdutoEstoque(int ent);

void generateRelatorioVenda(int ent);

void generateRelatorioEstoque(int ent);

float insertCombustivel(int ent);

float insertProdutoEstoque(int ent);

float generateRelatorioCaixa(int ent);

float insertQuantidadeProdutoEstoque(int ent){
    if(ent !=2){
        return 0;
    }
}

float updatePrecoProduto(int ent){

}
int main() {
    setlocale(LC_ALL, "Portuguese");


    login();
    return 0;
}
