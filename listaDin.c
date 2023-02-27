//-----------{Bibliotecas}-----------//
#include "biblioteca.h"

//=======[ Protótipos de Funções e Procedimentos ]=======//
//-----------{Criar Lista}-----------//
void criar_lista(Lista *lista)
{
  lista->inicio = NULL;
  lista->tam = 0;
}

//----------{Adicionar elementos na lista}----------//
int adicionar_na_lista(Lista *lista, Veiculo veiculo)
{
  
  No *aux, *novo = malloc(sizeof(No));
  
  if(novo){
    novo->veiculo = veiculo;
    if(lista->inicio == NULL)
      adicionar_no_inicio(lista, novo);
    else
      adicionar_no_fim(lista, novo, aux);
    lista->tam++;
  } else{
    printf("Erro ao alocar memória!\n\n");
    return  EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

//--------{Adicionar elementos no inicio da lista}--------//
void adicionar_no_inicio(Lista *lista, No *novo)
{
  novo->proximo = lista->inicio;
  lista->inicio = novo;
}

//--------{Adicionar elementos no fim da lista}--------//
void adicionar_no_fim(Lista *lista, No *novo, No *aux)
{
  aux = lista->inicio;
  while(aux->proximo)
    aux = aux->proximo;
  novo->proximo = NULL;
  aux->proximo = novo;
}

//----------{Remover elementos da lista}----------//
int remover_da_lista(Lista *lista, int cod_veiculo)
{

  if(lista_vazia(*lista) == true)
    return EXIT_FAILURE;

  No *remover = malloc(sizeof(No)), *aux;
  aux = lista->inicio;

  if(cod_veiculo == aux->veiculo.codigo_veiculo){
    remover = lista->inicio;
    lista->inicio = lista->inicio->proximo;
  }
  else{
      while(aux->proximo && aux->proximo->veiculo.codigo_veiculo != cod_veiculo)
        aux = aux->proximo;

    if(aux->proximo == NULL)
      return EXIT_FAILURE;
 
    remover = aux->proximo;
    aux->proximo = remover->proximo;
  }
  printf("\t\nREMOVIDO: \n");
  imprimir_info_do_veiculo(remover->veiculo);
  free(remover);
  lista->tam--;
  
  return EXIT_SUCCESS;
}

//----------{Editar elementos da lista}----------//
bool editar_venda(Lista *lista, int cod_veiculo){
  
  No *aux = lista->inicio;
  
  if(aux == NULL) return false; //Lista vazia
  else{
    while(aux && cod_veiculo != aux->veiculo.codigo_veiculo)
        aux = aux->proximo;
    if(aux){
      printf("\nCódigo encontrado\n");
      aux->veiculo = cadastrar_veiculo();
    }else 
      printf("\nCódigo NÃO encontrado\n");
    
      return true; //Alteração feita com sucesso
  }
}

//-----------{Apagar todos os dados do arquivo}-----------//
int apagar_todos_os_dados(Lista *lista)
{
  
  while(lista->inicio){
    free(lista->inicio);
    lista->inicio = lista->inicio->proximo;
  }
  
  if(lista->inicio)
    return EXIT_FAILURE;
  
  return EXIT_SUCCESS;
}

//-----------{Imprimir Lista}-----------//
int ver_lista_de_vendas(Lista lista)
{
  if(lista_vazia(lista) == true)
    return EXIT_FAILURE;

  int cont = 0;
  while(lista.inicio){
    cont++;
    printf("\n|---------------------------\n");
    printf("|-----------------\n");
    printf("|DADOS DO VEÍCULO %d:\n", cont);
    printf("|-----------------\n");
    imprimir_info_do_veiculo(lista.inicio->veiculo);
    lista.inicio = lista.inicio->proximo;
    printf("\n|---------------------------\n");
  }

  return EXIT_SUCCESS;
}

//----------{Imrprimir informações do veículo}----------//
void imprimir_info_do_veiculo(Veiculo veiculo)
{
  printf("|Nome do veículo: %s", veiculo.nome);
  printf("-----------------\n");
  printf("|Modelo: %s", veiculo.modelo);
  printf("|-----------------\n");
  printf("|Placa do veículo: %s", veiculo.placa);
  printf("-----------------\n");
  printf("|Código do veículo: %d\n", veiculo.codigo_veiculo);
  printf("|-----------------\n");
  printf("|Ano do veículo: %d\n", veiculo.ano);
  printf("-----------------\n");
  printf("|Valor do veículo: %.2f\n", veiculo.valor);
  printf("|-----------------\n");
  printf("|-----------------\n");

  imprimir_info_do_cliente(veiculo.cliente);
}

//----------{Imprimir informações do cliente}----------//
void imprimir_info_do_cliente(Cliente cliente)
{
  printf("|DADOS DO CLIENTE\n");
  printf("|-----------------\n");
  printf("|Nome do cliente: %s\n", cliente.nome);
  printf("|-----------------\n");
  printf("|CPF do cliente: %d\n", cliente.cpf);
  printf("|-----------------\n");
  printf("|Telefone do cliente: %d\n", cliente.telefone);
  printf("-----------------");

}

//--------{Consultar venda buscada pelo usuário}--------//
int consultar_venda(Lista lista, int cod_veiculo)
{
  if(lista_vazia(lista) == true)
    return EXIT_FAILURE;

  while(lista.inicio && lista.inicio->veiculo.codigo_veiculo != cod_veiculo)
    lista.inicio = lista.inicio->proximo;
  
  if(lista.inicio == NULL)
    return EXIT_FAILURE;
  
  imprimir_info_do_veiculo(lista.inicio->veiculo);
  printf("\nDigite enter para retornar ao menu-> \n");
  getchar();
  system("clear");
  return EXIT_SUCCESS;
}

//-----------{Verificar tamanho da Lista}-----------//
bool lista_vazia(Lista lista)
{
  if(lista.inicio) return false;
  printf("Sem vendas registradas!\n\n");
  return true;
}
