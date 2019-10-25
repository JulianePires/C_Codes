#PILHA - FILO (First In Last Out)

#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	
	int valor;
	struct item* proximo;
}Item;

//INSERCAO

Item* push(int valor, Item* pilha){
	
	Item* novo = (Item*)malloc(sizeof(Item));
	novo->valor = valor;
	novo->proximo = pilha;

	return novo;
}

//REMOCAO

Item* pop(Item* pilha){
	
	if(pilha != NULL){
		
		Item* temp = pilha;
		free(pilha);
		return temp;
	
	}else{
		
		return null;
	}
}

//IMPRESSAO

void imprimir(Item* pilha)
{
	if(pilha != null){
		printf("%i ", pilha->valor);
		imprimir(pilha->proximo);
	}
}

int main (void){
	Item* pilha = NULL;
	
	pilha = push(1, pilha);
	pilha = pop(pilha);
	imprimir (pilha);
	
	return 0;
}

	
	
