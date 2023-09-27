
# Sistema de Gerenciamento de Estoque do Posto Esquinão
<div align="center">
<img src="https://github.com/RodrigoWaechter/PostoEsquinao/assets/128084451/e0e2232f-4745-460e-bb27-5525c08167a7" width="700px" />
</div>

>Status: Developing

## Descrição do Projeto
  O sistema "O Esquinão" é um sistema de gerenciamento de estoque desenvolvido para um posto de combustível fictício. O objetivo principal do sistema é facilitar a gestão de produtos, vendas e estoque para os funcionários do posto, incluindo Gerentes, Caixas e Frentistas.

## Funcionalidades
 ### Frentista:
 - **Encher Tanque do Carro:** Preenche o tanque do veículo com a quantidade desejada de combustível.
 - **Calibrar Pneu:** Ajusta a pressão dos pneus do veículo de acordo com a especificação.
 - **Limpar Vidro:** Limpa os vidros do veículo.

### Caixa:
 O Caixa é o operador da caixa registradora e responsável pelas vendas. Suas funções incluem:

- **Cadastrar Venda:** Registra a venda de produtos, gerando uma nota fiscal com informações sobre os produtos adquiridos.

- **Atualizar Produto no Estoque:** Permite ao Caixa atualizar informações de produtos, como preço, quantidade e categoria.

- **Gerar Relatório de Estoque:** Retorna uma lista completa dos produtos em estoque com suas informações.

- **Gerar Receita do Fim de Dia:** Gera um relatório para fechamento de caixa, apresentando o histórico de vendas durante o período de trabalho.
  
  O Caixa pode também verificar o estoque, atualizá-lo e gerar relatórios para garantir um controle eficiente sobre os produtos disponíveis.

### Gerente:
  O Gerente é a autoridade máxima do posto e tem acesso a todas as funcionalidades do sistema. Suas operações incluem:
  
- **Cadastrar Produto:** Adiciona um novo produto ao estoque, fornecendo informações como código, nome, preço, quantidade e validade.
- **Comprar Produtos:** Permite a compra de produtos, inserindo o código e a quantidade desejada, recebendo um prazo de entrega e uma nota fiscal.
- **Ordenar Produtos:** Reorganiza o estoque exibindo os produtos em ordem crescente de ID.
- **Deletar Produtos:** Permite ao Gerente excluir produtos do estoque, independentemente dos valores em seus campos.

O Gerente tem controle total sobre a gestão do estoque, podendo adicionar, comprar, ordenar e excluir produtos conforme necessário.
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
- Linguagem de Programação: C
- [Trello](https://trello.com/b/zuyIEfQr/o-esquin%C3%A3o-organiza%C3%A7%C3%A3o): Usado para gerenciar tarefas e organização do projeto.

# Autores
- Enzo Seibert
- João Swarowsky
- Kelvin Beilke
- Leonardo de Amorim
- Rodrigo Waechter

# Data
Setembro de 2023
