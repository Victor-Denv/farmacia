#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maxremedios 5
typedef struct{
//Estrutura criada para armazenamento de dados dos clientes.
char nome[100];
char CPF[100];
char email [100];
char rg [100];
}Cliente;

typedef struct{                   //para cadastro dos remedios
char nome[maxremedios];
char dataValidade[maxremedios];
int estoqueMaximo;
int estoqueMinimo;
float preco;
int codigo;

}remedio;

typedef struct{
    remedio remedio [5];
  int totalremedio;
}sessaoremedio;

Cliente cliente [100]; //Criamos um vetor do tipo cliente para armazenar os clientes e ser consultado
//na hora da venda se o CPF dele ja consta no sistema.
int total_clientes = 0, total_de_vendas=0, total_vendas_realizadas=0;
//variavel do tipo inteiro para armazenamento de clientes cadastrados. (Informação para relatório do sistema.)

int i;  //contador global 
 // sessoes de cada remedio
int totalremed=0; // funcao para conta quantos remedios foram cadastrados

// esta começando o sistema com 0 remedios cadastrados
sessaoremedio sessaoA = {{0}, 0};  
sessaoremedio sessaoB = {{0}, 0}; 
sessaoremedio sessaoC = {{0}, 0};  
sessaoremedio sessaoD = {{0}, 0}; 
sessaoremedio sessaoE = {{0}, 0};  


void registrarremedio(){
int sessaoescolhida;
  // para registrar cada remedio na respectiva funcao

printf ("::::::::::::::::::::::::::::::::::::::::::::::\n");
printf ("::Escolha a Sessao para Registrar um remedio::  \n");
printf ("::::::::::::::::::::::::::::::::::::::::::::::\n");
printf ("1. Sessao de Medicamentos de dor \n");
printf ("2. Sessao de Medicamentos para febre \n");
printf ("3. Sessao de Medicamentos para Gripe \n");
printf ("4. Sessao de Medicamentos para Alergia \n");
printf ("5. Sessao de Medicamentos Gerais \n");
printf ("Obs : voce deve registrar no maximo  5 remedios em cada sessao .\n -->");
scanf("%d",&sessaoescolhida);
getchar();

sessaoremedio *sessao = NULL;

switch(sessaoescolhida){                 // para escolher qual sessao deve ter o remedio cadastrado
    case 1: sessao = &sessaoA; break;
    case 2: sessao = &sessaoB; break;
    case 3: sessao = &sessaoC; break;
    case 4: sessao = &sessaoD; break;
    case 5: sessao = &sessaoE; break;
    default: printf("Opcao invalida. Tente novamente.\n"); return;
}
    if (sessao ->totalremedio >=5){
        printf("Esta sessao esta cheia \n");
        return;
    }
      remedio *novoRemedio = &sessao->remedio[sessao->totalremedio];    // para obter uma proxima posiçao do array remedio da sessao 
      
      printf("Nome do Remedio: ");
      fgets (novoRemedio->nome,100,stdin);
      setbuf(stdin,NULL);
      printf("Codigo do Remedio: ");
      scanf("%d",&novoRemedio->codigo);
      setbuf(stdin,NULL);
      printf("Data de Validade do Remedio: ");
      scanf("%s/", novoRemedio->dataValidade);
      setbuf(stdin,NULL);
      printf("Estoque Maximo do Remedio: ");
      scanf("%d",&novoRemedio->estoqueMaximo);
      setbuf(stdin,NULL);
      printf("Estoque Minimo do Remedio: ");
      scanf("%d",&novoRemedio->estoqueMinimo);
      setbuf(stdin,NULL);
      printf("Preco do Remedio: ");
      scanf("%f",&novoRemedio->preco);
      setbuf(stdin,NULL);
      printf("remedio cadastrado!!\n");
      setbuf(stdin,NULL);
      sessao->totalremedio++;
     totalremed++;
      return menuremedios();
      }

// para exibir os remedios cadastrados
exibirremedios(){
    int sessaoescolhida;

    printf ("::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::Escolha a Sessao para Exibir os remedios::  \n");
    printf ("::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("1. Sessao de Medicamentos de dor \n");
    printf ("2. Sessao de Medicamentos para febre \n");
    printf ("3. Sessao de Medicamentos para Gripe \n");
    printf ("4. Sessao de Medicamentos para Alergia \n");
    printf ("5. Sessao de Medicamentos Gerais \n");
    scanf("%d",&sessaoescolhida);
    getchar();

    sessaoremedio *sessao = NULL;
    switch(sessaoescolhida){
        case 1:
        sessao = &sessaoA;
        break;
        case 2:
        sessao = &sessaoB;
         break;
        case 3:
        sessao = &sessaoC;
        break;
        case 4:
        sessao = &sessaoD;
        break;
        case 5:
        sessao = &sessaoE;
         break;

        default: printf("Opcao invalida. Tente novamente.\n");
        return;
    }

    if (sessao->totalremedio == 0){
        printf("Nao existem remedios cadastrados nesta sessao.\n");
        return;
    }

    printf("Remedios cadastrados na sessao %d",sessaoescolhida);
      for (i=0;i <sessao->totalremedio;i++){
        printf("\nNome: %s", (*sessao).remedio[i].nome);
        printf("\nCodigo: %d", (*sessao).remedio[i].codigo);
        printf("\nData de Validade: %s", (*sessao).remedio[i].dataValidade);
        printf("\nEstoque Maximo: %d",(*sessao).remedio[i].estoqueMaximo);
        printf("\nEstoque Minimo: %d", (*sessao).remedio[i].estoqueMinimo);
        printf("\nPreco: %.2f\n",(*sessao).remedio[i].preco);
      }
   
}
//Jacson e Vitor
 void menuremedios(){
 int opcao;
 printf ("\n1-Cadastrar Remedio\n2-Exibir Remedios Cadastrados\n3-Voltar Para Menu inicial\n->") ;
 scanf ("%d",&opcao);
 switch (opcao){
case 1 :
  //Chamando função para cadastrar remedio
  registrarremedio();
  break;
  case 2 :
  exibirremedios(); //chamando funçao para exibir remedios cadastrados
break;
case 3 :
system("cls");
printf ("Voltando ao menu inicial ......");
return;
 }

}




//Felipe
void Cliente_farm(){

//Função void para cadastro de cliente a ser invocada no case
int decisao;

printf ("Deseja cadastra um cliente? \n1-Sim \n2-Nao \n");
scanf ("%d",&decisao);

switch (decisao){
case 1:{
    for (int i = 0; i < 100; i++){
        printf ("\nCadastro de Cliente: \n");
        printf ("NOME: ");
        setbuf(stdin, NULL);
        fgets( cliente[i].nome,100,stdin );
        printf ("CPF: ");
        setbuf (stdin, NULL);
        fgets( cliente[i].CPF,100,stdin );
        printf ("RG: ");
        setbuf (stdin, NULL);
        fgets( cliente[i].rg,100,stdin );
        printf ("Email: ");
        setbuf (stdin, NULL);
        fgets( cliente[i].email,100,stdin );

        total_clientes++;

        printf ("\nCliente cadastrado com sucesso!\n");
        system ("cls");
        printf ("Cliente:  %s ",cliente[i].nome);
        printf ("CPF: %s ",cliente[i].CPF);
        printf ("RG: %s ",cliente[i].rg);
        printf ("Email: %s ",cliente[i].email);if(total_clientes == 1);
        break;
        }
    }break;

case 2 :
    printf("Voltando pro menu Principal....\n");
    return;
    break;
    }
}


//Felipe e Emanuel
void caixa_de_vendas() {
    int opcao, codigo, quantidade;
    float valorTotal = 0, valorItem;
    int clienteExistente = 0;
    char cpfCliente[100];

    printf("::::::: Caixa Aberto ::::::\n");
    printf("Cliente tem cadastro? \n1- Sim \n2- Não \n");
    scanf("%d", &opcao);

    if (opcao == 2) {
        Cliente_farm(); // Realiza o cadastro do cliente
        clienteExistente = 1; // Marca que o cliente foi cadastrado
    } else if (opcao == 1) {
        printf("Digite o CPF do cliente: ");
        setbuf(stdin, NULL);
        fgets(cpfCliente, 100, stdin);

        // Verifica se o CPF existe no sistema
        for (int i = 0; i < total_clientes; i++) {
            if (strcmp(cliente[i].CPF, cpfCliente) == 0) {
                clienteExistente = 1;
                break;
            }
        }

        if (!clienteExistente) {
            printf("Cliente não encontrado! Realizando cadastro...\n");
            Cliente_farm(); // Chama a função de cadastro do cliente
            clienteExistente = 1; // Marca que o cliente foi cadastrado
        }
    }

    if (clienteExistente) {
        // Realiza o processo de venda aqui
        while (1) {
            printf("Digite o código do produto (ou 0 para finalizar): ");
            scanf("%d", &codigo);

            if (codigo == 0) break; // Finaliza a seleção de produtos

            // Busca o produto com o código informado
            remedio* produto = NULL;
            sessaoremedio* sessoes[] = {&sessaoA, &sessaoB, &sessaoC, &sessaoD, &sessaoE};

            for (int i = 0; i < 5; i++) { // Itera pelas sessões
                sessaoremedio* sessao = sessoes[i];
                for (int j = 0; j < sessao->totalremedio; j++) { // Itera pelos remédios dentro da sessão
                    if (sessao->remedio[j].codigo == codigo) {
                        produto = &sessao->remedio[j];
                        break;
                    }
                }
                if (produto != NULL) break; // Sai do loop se o produto for encontrado
            }

            if (produto == NULL) {
                printf("Produto não encontrado ou não registrado!\n");
                continue;
            }

            // Solicita a quantidade
            printf("Quantidade do produto %s: ", produto->nome);
            scanf("%d", &quantidade);

            // Verifica se a quantidade é válida
            if (quantidade <= 0) {
                printf("Quantidade inválida! Tente novamente.\n");
                continue;
            }

            // Calcula o valor do item
            valorItem = produto->preco * quantidade;
            valorTotal += valorItem;
            printf("Adicionado %d unidade(s) de %s ao carrinho. Subtotal: %.2f\n", quantidade, produto->nome, valorTotal);
        }

        // Aplica desconto de 5% se o cliente estiver cadastrado
        if (clienteExistente) {
            valorTotal *= 0.95; // Reduz o valor total em 5%
            printf("Desconto de 5%% aplicado! Valor com desconto: %.2f\n", valorTotal);
        }

        // Incrementa o total de vendas realizadas
        total_de_vendas++;
        total_vendas_realizadas++;

        printf("Venda finalizada! Valor total da compra: %.2f\n", valorTotal);
        return;
    }
}


void Relatorio() {

    printf("\n:::::::::::: Relatório :::::::::::\n");

    // Total de vendas realizadas no mês
   
    printf("Total de Vendas Realizadas : %d\n", total_de_vendas);
    printf("Total de Remédios Cadastrados : %d\n", totalremed
    );
    printf("Total de Clientes Cadastrados : %d\n", total_clientes);

    // Exibindo informações sobre o lote dos remédios em cada sessão


    printf("\n:::::::::::::::::::::::::::::::::::::\n");
}




//Felipe

int main(){
setlocale(LC_ALL, "Portuguese");
int opcao;
do {
    printf ("\n::::::::::BEM VINDO AO SISTEMA DROGAFARM:::::::::::::\n");

    printf ("Escolha uma opcao: \n");
    printf ("1- Cadastro de Remedio \n");
    printf ("2- Cadastro de Cliente: \n");
    printf ("3- Caixa / Venda: \n");
    printf ("4- Gerar relatório: \n");
    printf ("5- Sair do Sistema...\n\n->  ");
    scanf ("%d",&opcao);
    switch (opcao) {
    case 1:
        menuremedios();
    break;

    case 2:
        Cliente_farm();
    break;

    case 3:
        caixa_de_vendas();
    break;

    case 4:
        Relatorio();
    break;

    case 5:
        printf ("\nSaindo do Sistema...\n");
    break;

    default:
        printf ("Opção inválida. Tente novamente.\n");
        break;
    }



}while (opcao!=5);
    return 0;
}


