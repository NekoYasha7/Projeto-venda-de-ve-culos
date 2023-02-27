//-----------{Bibliotecas}-----------//
#include "biblioteca.h"


//-----------{Ler dados do arquivo}-----------//
bool ler_dados_arquivos(Lista *lista){
  
  FILE *file = fopen("Todas_vendas.bin","rb");
  No *aux = malloc(sizeof(No));
  
  if(file == NULL) {
    printf("\nSem dados salvos\n\n");
    return false; 
  }
    
  else{
      while(fread(&aux->veiculo , sizeof(Veiculo), 1 , file))
          adicionar_na_lista(lista, aux->veiculo);
  }
  
  fclose(file);
  
  return true;
}

//----------{Salvar dados no arquivo}----------//
bool salvar_dados(Lista *lista){
  FILE *file = fopen("Todas_vendas.bin","wb");
  No *aux = lista->inicio;

  if(file == NULL) 
    return false;
  else{
      while(aux){
        fwrite(&aux->veiculo, sizeof(Veiculo), 1 , file);
        aux = aux->proximo;
      }  
  }
  
  fclose(file);
  
  return true;
}
