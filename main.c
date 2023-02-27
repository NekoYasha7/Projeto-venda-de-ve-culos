//-----------{Bibliotecas}-----------//
#include "biblioteca.h"

//----------{Função principal}----------//
int main(void) 
{
  
  setlocale(LC_ALL, "portuguese");
  Lista lista;

  criar_lista(&lista);
  
  ler_dados_arquivos(&lista);
  
  
  while(mensagem_com_opcoes(&lista) == true);
  
  printf("-> Programa encerrado!\n\n");
  return EXIT_SUCCESS;
}