//-----------{Bibliotecas}-----------//
#include "biblioteca.h"

//========[ Funções e Procedimentos ]========//
//-----------{Cadastrar veículo}-----------//
Veiculo cadastrar_veiculo()
{
  Veiculo v;
  printf("\n|---------------------------\n");
  printf("|Insira o nome do veículo: \n|-> ");
  fgets(v.nome, 29, stdin);
  printf("|Insira o modelo do veículo: \n|-> ");
  fgets(v.modelo, 29, stdin);
  printf("|Insira a placa do veículo: \n|-> ");
  fgets(v.placa, 17, stdin);
  printf("|Insira o código do veículo: \n|-> ");
  scanf("%d", &v.codigo_veiculo);
  fflush(stdin);
  printf("|Insira o ano do veículo: \n|-> ");
  scanf("%d", &v.ano);
  printf("|Insira o valor do veículo: \n|-> ");
  scanf("%f", &v.valor);
  getchar();
  printf("| DADOS DO VEÍCULO REGISTRADOS |\n");
  printf("|------------------------------|");
  printf("\n|-> ");
  v.cliente = cadastrar_cliente();

  return v;
}
Cliente cadastrar_cliente()
{
  Cliente c;

  printf("|Insira o nome do cliente: \n|-> ");
  scanf("%49[^\n]", c.nome); //Não usar "fgets" e "fflush" aqui.
  getchar();
  printf("|Insira o CPF do cliente (apenas números): \n|-> ");
  scanf("%d", &c.cpf);
  printf("|Insira o telefone do cliente: \n|-> ");
  scanf("%d", &c.telefone);
  printf("| DADOS DO VEÍCULO REGISTRADOS \n");
  return c;
}
