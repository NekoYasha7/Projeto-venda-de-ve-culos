//-----------{Bibliotecas}-----------//
#include "biblioteca.h"

//===========[ Protótipos de Funções e Procedimentos ]===========//
bool mensagem_com_opcoes(Lista *lista)
{
  int opcao;

  printf
  (
    "\n|----------------------|\n"
    "|0 - Encerrar programa |"
    "\n|----------------------|\n"
    "|1 - Cadastrar venda   |"
    "\n|----------------------|\n"
    "|2 - Listar vendas     |"
    "\n|----------------------|\n"
    "|3 - Consultar venda   |"
    "\n|----------------------|\n"
    "|4 - Editar venda      |"
    "\n|----------------------|\n"
    "|5 - Excluir venda     |"
    "\n|----------------------|\n"
    "|6 - Ordenar por valor |"
    "\n|----------------------|\n"
    "|7 - Cadastrar ordenado|"
    "\n|----------------------|\n"
    "|8 - Deletar tudo      |"
    "\n|----------------------|"
    "\n|----------------------|\n"
  );
  printf("|----------------------|");
  printf("\n|-> ");
  scanf("%d", &opcao);
  printf("    |-|\n");
  printf("|-----|");
  printf("\n|-> ");
  getchar();

  selecionar_opcao(opcao, lista);

  return verificar_opcao(opcao);
}
void selecionar_opcao(int opcao, Lista *lista)
{
  Veiculo veiculo;
  int cod;

  switch(opcao){
    case 1:
      veiculo = cadastrar_veiculo();
      system("clear"); //Caso Windows, usar "System("cls")";
      if(adicionar_na_lista(lista, veiculo) == EXIT_SUCCESS)
        printf("-> Venda cadastrada com sucesso!\n\n");
      else
        printf("-> Erro ao cadastrar venda\n\n");
    break;
    case 2:
      ver_lista_de_vendas(*lista);
    break;
    case 3:
      cod = inserir_codigo_a_buscar();
      if(consultar_venda(*lista, cod) == EXIT_SUCCESS)
        printf("Removido com sucesso!\n\n");
      else
        printf("-> Venda não encontrada!\n\n");
    break;
    case 4:  editar_venda(lista, inserir_codigo_a_buscar());
      break;
    case 5:
      cod = inserir_codigo_a_buscar();
      if(remover_da_lista(lista, cod) == EXIT_SUCCESS)
        printf("-> Venda removida com sucesso!\n\n");
      else
        printf("-> Venda não encontrada!\n\n");
    break;
    case 6:
      if(ordenar_por_valor(lista) == EXIT_SUCCESS)
        printf(" Vendas ordenadas com sucesso!\n\n");
    break;
    case 7:
      cadastrar_ordenado(lista, cadastrar_veiculo());
    break;
    case 8:
      if(apagar_todos_os_dados(lista) == EXIT_SUCCESS)
        printf("Todos os dados foram deletados!\n\n");
      else
        printf("Ocorreu um erro ao apagar os dados\n\n");
    break;
    default:
      if(opcao != 0) printf("-> Opção inválida!\n\n");
      else{
        system("clear");
        if(salvar_dados(lista)) printf("-> Dados salvos\n");
        else printf(" Erro ao salvar");
      }
  }
}
int inserir_codigo_a_buscar()
{
  int num;
  printf("Insira o código do veículo que deseja buscar: \n");
  scanf("%d", &num);
  getchar();
  
  return num;
}
bool verificar_opcao(int opcao)
{
  if(opcao == 0) return false;
  return true;
}