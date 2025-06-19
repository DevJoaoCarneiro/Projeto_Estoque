# Sistema de Controle de Estoque em C

Este repositório contém o código-fonte de um Sistema de Controle de Estoque desenvolvido em linguagem C. O projeto utiliza listas encadeadas para gerenciar produtos e suas movimentações, sendo uma aplicação prática dos conceitos de Estrutura de Dados.

https://github.com/user-attachments/assets/73562888-109b-40f2-bf43-97a3fa55db12
## 📜 Descrição

[cite_start]O objetivo principal deste sistema é efetuar o controle eficiente da entrada e saída de mercadorias no estoque de uma empresa. [cite_start]Um controle de estoque preciso permite um melhor planejamento de compras, garantindo que a empresa saiba exatamente a quantidade de cada produto disponível para atender à demanda de seus clientes.

[cite_start]O sistema funciona a partir do cadastro inicial de todos os produtos. [cite_start]A cada nova entrada ou saída, o saldo do produto é atualizado automaticamente, refletindo o estado real do estoque da empresa.

## ✨ Funcionalidades

[cite_start]O sistema oferece uma interface de usuário simples, baseada em menus, com as seguintes funcionalidades:

* **Cadastro de Produtos**:
    * [cite_start]Inclusão de produtos no início, em uma posição específica ou no final da lista.
    * [cite_start]Alteração dos dados de produtos já cadastrados.
    * [cite_start]Consulta de produtos.
    * [cite_start]Exclusão de produtos do início, de uma posição específica ou do final da lista.
* **Movimentação de Estoque**:
    * [cite_start]Registro de operações de entrada e saída de produtos no estoque.
* **Reajuste de Preços**:
    * [cite_start]Alteração do preço de um ou mais produtos do estoque.
* **Relatórios**:
    * [cite_start]**Lista de Preços**: Gera uma relação de todos os produtos em ordem alfabética, com preço e unidade de medida.
    * [cite_start]**Balanço Físico/Financeiro**: Exibe uma relação de todos os produtos em ordem alfabética, com a quantidade disponível, valor total por produto e o valor total geral do estoque.

## 🛠️ Tecnologias e Estruturas de Dados

* [cite_start]**Linguagem**: O projeto foi desenvolvido inteiramente em **Linguagem C**.
* [cite_start]**Persistência**: Os dados são lidos de arquivos no início da execução e salvos de volta em disco ao finalizar o programa.
* [cite_start]**Estrutura de Dados**: Todo o processamento durante a execução é feito em memória usando listas encadeadas.

### Listas Encadeadas

1.  **Lista Simplesmente Encadeada (Produtos)**
    * [cite_start]**Uso**: Armazena o cadastro de produtos, mantidos em ordem crescente de código.
    * [cite_start]**Vantagens**: Facilidade de inserção e remoção de elementos e crescimento dinâmico da lista.
    * **Estrutura do Produto (`reg_produto`)**:
        * `cd_produto` (int): Código do Produto.
        * [cite_start]`ds_produto` (char[50]): Nome do produto.
        * `ds_unid_med` (char[03]): Unidade de medida.
        * [cite_start]`dt_validade` (char[11]): Data de Validade.
        * `qt_produto` (float): Quantidade em Estoque.
        * [cite_start]`vl_CustoMedio` (float): Custo Médio Unitário.
        * `vl_total` (float): Valor Total do Estoque.

2.  **Lista Duplamente Encadeada (Movimentações)**
    * [cite_start]**Uso**: Armazena o histórico de todas as movimentações de entrada e saída do estoque.
    * **Estrutura da Movimentação (`reg_movim`)**:
        * `dt_movim` (char[11]): Data da Movimentação.
        * `cd_prod_movim` (int): Código do Produto movimentado.
        * `tp_movim` (char): Tipo de Movimentação ('E' = Entrada; 'S' = Saída).
        * `qt_movim` (float): Quantidade movimentada.
        * `vl_unit_movim` (float): Valor Unitário da movimentação.
        * `vl_total_movim` (float): Valor Total da Movimentação.

## 🧮 Cálculo do Custo Médio

[cite_start]Para manter a consistência do valor do estoque, o Custo Médio Unitário é recalculado a cada nova entrada de mercadoria. [cite_start]Os campos de `Quantidade em Estoque`, `Custo Médio Unitário` e `Valor total de estoque` são iniciados com zero e não podem ser manipulados diretamente, sendo atualizados apenas pelas movimentações.

A fórmula para o cálculo é:

$$
\text{Custo Médio} = \frac{(\text{Valor do estoque atual} \times \text{Quantidade em estoque atual}) + (\text{Valor de compra} \times \text{Quantidade comprada})}{(\text{Quantidade em estoque atual} + \text{Quantidade comprada})}
[cite_start]$$ 

### Exemplo Prático:

1.  **Estoque Atual**: 100 unidades a R$10,00 cada. [cite_start]Total: R$1.000,00.
2.  **Nova Compra**: 50 unidades a R$15,00 cada. [cite_start]Total: R$750,00.
3.  **Cálculo**:
    $$
    \text{Custo Médio} = \frac{(100 \times 10) + (50 \times 15)}{100 + 50} = \frac{1000 + 750}{150} = \text{R\$ 11,67}
    [cite_start]$$ 

## ⚙️ Regras de Negócio e Observações

* O saldo do estoque **não pode ser negativo**. [cite_start]A quantidade de saída nunca poderá ser maior que o saldo em estoque.
* A **data da movimentação** não pode ser anterior à última data movimentada para o mesmo produto.
* [cite_start]O código deve ser modularizado com o uso de **subprogramas** (procedures e functions).
* [cite_start]O programa deve testar todas as **condições de erro** possíveis.

## 🖥️ Telas do Sistema (Layout)

A interface do sistema é organizada em menus e telas de cadastro/consulta, conforme os layouts a seguir:

* **TELA 1.0 - MENU PRINCIPAL**: Opções para acessar o cadastro de produtos, movimentação de estoque ou finalizar o programa.
* [cite_start]**TELA 1.1 - MENU PRODUTO**: Opções para cadastrar, remover, consultar e alterar produtos.
* [cite_start]**TELA 1.1.1 - CADASTRAR PRODUTO**: Formulário para entrada dos dados do produto.
* **TELA 1.1.1 - CONSULTA DE PRODUTOS**: Exibição da lista de produtos cadastrados.
* [cite_start]**TELA 2.0 - MENU MOVIMENTAÇÃO**: Opções para cadastrar ou listar movimentações.
* [cite_start]**TELA 2.1 - CADASTRAR MOVIMENTAÇÃO**: Formulário para registro de entradas e saídas de produtos.
* **TELA 2.2 - CONSULTA MOVIMENTAÇÃO**: Exibição do histórico de movimentações para um produto.
