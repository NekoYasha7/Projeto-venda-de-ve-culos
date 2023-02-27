//-----------{Bibliotecas}-----------//
#include "biblioteca.h"

//-----------{Funções Extras}-----------//
/*Giovane:*/
int ordenar_por_valor(Lista *lista) {
  if (lista_vazia(*lista) == true)
    return EXIT_FAILURE;

  int cont = lista->tam, cont2 = 0;
  Veiculo veiculo[lista->tam];

  carregar_vetor(*lista, veiculo);

  bubble_sort(veiculo, cont);

  esvaziar_lista(lista);

  while (cont2 < cont) {
    adicionar_na_lista(lista, veiculo[cont2]);
    cont2++;
  }

  return EXIT_SUCCESS;
}

void carregar_vetor(Lista lista, Veiculo *veiculo) {
  int cont = 0;

  while (lista.inicio) {
    veiculo[cont] = lista.inicio->veiculo;
    lista.inicio = lista.inicio->proximo;
    cont++;
  }
}

void bubble_sort(Veiculo *veiculo, int cont) {
  for (int i = 0; i < cont; i++) {
    for (int j = 0; j < cont; j++) {
      if (veiculo[j].valor < veiculo[i].valor) {
        Veiculo veiculo2;
        veiculo2 = veiculo[j];
        veiculo[j] = veiculo[i];
        veiculo[i] = veiculo2;
      }
    }
  }
}

void esvaziar_lista(Lista *lista) {
  No *remover = malloc(sizeof(No));
  while (lista->inicio) {
    remover = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(remover);
    lista->tam--;
  }

}
/*FIM Giovane:*/

/*Eduardo de Souza:*/
void cadastrar_ordenado(Lista *lista, Veiculo veiculo){
  No *aux, *novo = malloc(sizeof(No));
  if(novo == NULL){
    printf("\nErro ao alocar um no\n");
    exit(0);
  }else{
    novo->veiculo = veiculo;
    
    //A lista está vazia?
    if(lista->inicio == NULL){
      lista->inicio = novo;
      novo->proximo = NULL;
    }else if(novo->veiculo.cliente.nome[0] < lista->inicio->veiculo.cliente.nome[0]){  // é menor que o primeio elemento
      novo->proximo = lista->inicio;
      lista->inicio = novo;
    }else{// caso não seja o primeiro elemento tenho que percorrer
      aux = lista->inicio;
      while(aux->proximo &&  novo->veiculo.cliente.nome[0] > aux->proximo->veiculo.cliente.nome[0])
        aux = aux->proximo;

      novo->proximo = aux->proximo;
      aux->proximo = novo;
      lista->tam++;
      
      
    }
  }
}

/*FIM Eduardo de Souza:*/