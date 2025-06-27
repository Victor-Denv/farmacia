Beleza, Vitor! Aqui está uma explicação simples, direta e estruturada que você pode colocar no **README** do projeto do sistema da farmácia Drogafarm:

---

# **Sistema de Gerenciamento Drogafarm**

## **Descrição do Projeto**

Este é um sistema simples de gerenciamento para uma farmácia, desenvolvido em **linguagem C**, com o objetivo de controlar o **cadastro de clientes**, **cadastro de remédios**, **processo de vendas** e **relatórios básicos**.

O sistema é totalmente feito em modo console, utilizando estruturas, vetores e funções, ideal para fins acadêmicos ou como projeto de aprendizado.

---

## **Funcionalidades**

✅ Cadastro de Remédios por Sessão
✅ Exibição de Remédios Cadastrados por Sessão
✅ Cadastro de Clientes
✅ Processo de Venda com verificação de CPF e desconto para clientes cadastrados
✅ Relatório de vendas, clientes e remédios cadastrados
✅ Limite de até 5 remédios por sessão
✅ Simulação de sessões: Dor, Febre, Gripe, Alergia e Geral

---

## **Organização do Código**

O sistema está organizado em três estruturas principais:

### **Estrutura Cliente**

```c
typedef struct {
  char nome[100];
  char CPF[100];
  char email[100];
  char rg[100];
} Cliente;
```

Armazena as informações pessoais dos clientes.

---

### **Estrutura Remédio**

```c
typedef struct {
  char nome[100];
  char dataValidade[100];
  int estoqueMaximo;
  int estoqueMinimo;
  float preco;
  int codigo;
} remedio;
```

Armazena as informações dos remédios, como nome, validade, estoque, preço e código identificador.

---

### **Estrutura Sessão de Remédio**

```c
typedef struct {
  remedio remedio[5];
  int totalremedio;
} sessaoremedio;
```

Armazena até 5 remédios por sessão. Existem 5 sessões no sistema:

1. Medicamentos para Dor
2. Medicamentos para Febre
3. Medicamentos para Gripe
4. Medicamentos para Alergia
5. Medicamentos Gerais

---

## **Menus e Funcionalidades**

### **Menu Principal**

Opções disponíveis:

* **1:** Cadastro de Remédio
* **2:** Cadastro de Cliente
* **3:** Caixa / Venda
* **4:** Relatório
* **5:** Sair

---

### **Cadastro de Remédios**

* O usuário escolhe a sessão desejada (1 a 5).
* Limite de até 5 remédios por sessão.
* Coleta de dados do remédio: nome, código, validade, estoque mínimo/máximo e preço.

---

### **Exibição de Remédios**

* Mostra todos os remédios cadastrados em uma sessão específica.

---

### **Cadastro de Clientes**

* Permite o cadastro dos dados de um cliente (nome, CPF, RG e e-mail).
* O sistema usa o CPF para identificar clientes nas vendas.

---

### **Processo de Venda**

* Verifica se o cliente já está cadastrado pelo CPF.
* Se não estiver, realiza o cadastro.
* Permite escolher produtos pelo código e informar a quantidade.
* Aplica **5% de desconto** para clientes cadastrados.
* Exibe o valor total da compra.

---

### **Relatório**

Exibe:

* Total de vendas realizadas
* Total de remédios cadastrados
* Total de clientes cadastrados

---

## **Observações Técnicas**

⚠️ O sistema usa o `setbuf(stdin, NULL)` para evitar problemas de leitura no `scanf` e `fgets`.
⚠️ Limite fixo de 5 remédios por sessão e 100 clientes.
⚠️ Não há persistência de dados (tudo em memória enquanto o programa roda).

---

## **Requisitos para Compilar**

Compilador C como:

* **GCC** (Linux ou Windows)
* Pode ser executado em ambientes como CodeBlocks, Dev-C++, VSCode com extensão C/C++, etc.

---

## **Como Executar**

1. Compile o programa:

```bash
gcc drogafarm.c -o drogafarm
```

2. Execute:

```bash
./drogafarm
```

---

## **Autores**

* Jacson
* Vitor
* Felipe
* Emanuel

---

Se quiser, já posso montar esse arquivo `.md` pronto também. Só dizer!
