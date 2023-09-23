
# Sistema de Gerenciamento de Estoque do Posto Esquinão
>Status: Developing

## Descrição do Projeto
  O sistema "O Esquinão" é um sistema de gerenciamento de estoque desenvolvido para um posto de combustível fictício. O objetivo principal do sistema é facilitar a gestão de produtos, vendas e estoque para os funcionários do posto, incluindo Gerentes, Caixas e Frentistas.

## Funcionalidades
 ### Frentista:
 - **Gerar Relatório do Estoque:** Permite que o frentista verifique a disponibilidade de produtos no estoque. O sistema fornece uma lista completa dos itens armazenados com informações detalhadas, como quantidade, preço e validade.
 - **Vender Unidades de Produto:** Possibilita ao frentista realizar vendas de produtos aos clientes. O frentista insere o código do produto e a quantidade desejada, com atualização automática do estoque e cálculo do preço final.
 - **Gerar Nota de Venda:** Após uma venda bem-sucedida, o frentista pode gerar uma nota fiscal com informações essenciais, como produto, quantidade, preço unitário e preço final.

### Caixa:
  O Caixa possui todas as funcionalidades do Frentista e ainda pode:

- **Cadastrar Produto no Estoque:** No início do dia, o Caixa preenche o estoque com os produtos disponíveis, inserindo informações como código, nome, preço, quantidade, validade e categoria.

- **Atualizar Produto no Estoque:** Permite ao Caixa atualizar informações de produtos, como preço, quantidade e categoria.

- **Ordenar Produtos do Estoque:** Facilita a organização do estoque, possibilitando a ordenação por diferentes critérios, como código, quantidade, preço, validade e categoria.

- **Gerar Receita do Fim de Dia:** No fechamento do caixa, o sistema gera um relatório com a receita total do dia, exibindo o valor arrecadado.

### Gerente:
  O Gerente tem acesso a todas as funcionalidades dos Frentistas e Caixas e pode executar ações adicionais, incluindo:

- **Comprar Produtos:** Permite ao Gerente comprar produtos para o estoque, especificando o código do produto e a quantidade desejada. O sistema fornece um prazo de entrega e uma nota fiscal da compra.

- **Deletar Produtos:** Permite ao Gerente excluir produtos do estoque, independentemente dos valores em seus campos.

## Uso do Sistema
  Os funcionários do posto de combustível acessam o sistema escolhendo sua função (Frentista, Caixa ou Gerente) e realizam as operações correspondentes. O sistema fornece menus intuitivos para guiar os usuários durante as interações.

### Exemplo de Execução:
  Inicie o programa e escolha a função (Frentista, Caixa ou Gerente).
  
  Realize as operações disponíveis conforme a função selecionada.
  
  No final do dia, o Caixa ou o Gerente pode gerar um relatório com a receita total arrecadada.
#### Observações:
  - O programa foi desenvolvido com o objetivo de facilitar a gestão do posto de combustível, melhorando o controle de estoque, vendas e receitas.
  - Todas as ações realizadas no sistema são registradas para fins de auditoria e controle.
  - O sistema é fictício e foi criado apenas como um exemplo de gerenciamento de estoque.

# Tecnologias/Ferramentas Utilizadas
### O sistema será desenvolvido utilizando as seguintes tecnologias:
- Linguagem de Programação: C/C++
- [Trello](https://trello.com/b/zuyIEfQr/o-esquin%C3%A3o-organiza%C3%A7%C3%A3o): Usado para gerenciar tarefas e organização do projeto.

# Autores
- Enzo Seibert
- João Swarowsky
- Kelvin Beilke
- Leonardo de Amorim
- Rodrigo Waechter

# Data
Setembro de 2023
