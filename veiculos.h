//-----------{Bibliotecas}-----------//
#include <stdio.h>
//===========[ Estruturas ]===========//
//-----------{Struct Cliente}-----------//
typedef struct{
  char nome[50];
  int cpf;
  int telefone;
} Cliente;
//-----------{Struct Veiculo}-----------//
typedef struct{
  int codigo_veiculo;
  char placa[18];
  char modelo[30];
  char nome[30];
  int ano;
  float valor;
  Cliente cliente;
} Veiculo;
//-----------{Struct Nó}-----------//
typedef struct no{
  Veiculo veiculo;
  struct no *proximo;
} No;
//-----------{Struct Lista}-----------//
typedef struct{
  No *inicio;
  int tam;
} Lista;

//===========[ Protótipos de Funções e Procedimentos ]===========//
//-----------{Menu}-----------//
bool mensagem_com_opcoes(Lista *lista);
void selecionar_opcao(int opcao, Lista *lista);
bool verificar_opcao(int opcao);
void limpar_tela();
int inserir_codigo_a_buscar();

//-----------{Cadastro}-----------//
Veiculo cadastrar_veiculo();
Cliente cadastrar_cliente();

//-----------{Funções Extras}-----------//
/*Giovane:*/
int ordenar_por_valor(Lista *lista);
void carregar_vetor(Lista lista, Veiculo *veiculo);
void bubble_sort(Veiculo *veiculo, int cont);
void esvaziar_lista(Lista *lista);
/*Eduardo de Souza:*/
void cadastrar_ordenado(Lista*, Veiculo);

//-----------{Arquivos}-----------//
bool salvar_dados(Lista *lista);
bool ler_dados_arquivos(Lista *lista);

//-----------{Manipular Lista}-----------//
void criar_lista(Lista *lista);
int adicionar_na_lista(Lista *lista, Veiculo veiculo);
void adicionar_no_inicio(Lista *lista, No *novo);
void adicionar_no_fim(Lista *lista, No *novo, No *aux);
int remover_da_lista(Lista *lista, int cod_veiculo);
bool editar_venda(Lista *lista, int cod_veiculo);
int apagar_todos_os_dados(Lista *lista);

//-----------{Imprimir Lista}-----------//
void divisoria();
int ver_lista_de_vendas(Lista lista);
void imprimir_info_do_veiculo(Veiculo veiculo);
void imprimir_info_do_cliente(Cliente cliente);
int consultar_venda(Lista lista, int cod_veiculo);
//-----------{Tamanho da Lista}-----------//
bool lista_vazia(Lista lista);
