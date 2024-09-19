#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int id;
	int *elementos;
}Lista;

Lista* criarLista(){
	Lista *nova = (Lista*) malloc(sizeof(Lista));
	if (nova == NULL){
		printf("A alocacao de memoria falhou");
		return NULL;
	}
	nova->id = 0;
	nova->elementos = malloc(5 * sizeof(int));
	if (nova->elementos == NULL){
		printf("A alocacao de memoria falhou");
		free(nova);
		return NULL;
	}
	return nova;
}

int inserirElemento(Lista *lista, int valor){
	if(lista == NULL){
		printf("A lista nao existe");
		return 0;
	}
	if(lista->id < 5){
		lista->elementos[lista->id] = valor;
		lista->id++;
	} else {
		printf("A lista esta cheia");
		return 0;
	}
	return 1;	
}

void imprimirElementos(Lista *lista){
	int i;
	if(lista == NULL){
		printf("A lista nao existe");
		return;
	}
	if(lista->id == 0){
		printf("A lista esta vazia");
		return;
	}
	for(i = 0; i < lista->id; ++i){
		printf("%d ", lista->elementos[i]);
	}
}

int main(){
	// #1 lista simplesmente encadeada
    Lista *lista;
    lista = criarLista();
    inserirElemento(lista, 1);
    inserirElemento(lista, 2);
    inserirElemento(lista, 3);
    inserirElemento(lista, 4);
    inserirElemento(lista, 5);
    imprimirElementos(lista);
	return 0;	   	
}