#FILA - LIFO (LAST IN FIRST OUT)

typedef struct item{
	int valor;
	sctruct item* proximo;
}Item;

//INSERCAO

Item* enqueue(int valor, Item* atual){
	
	if(atual == NULL){
		Item* novo = (Item*)malloc(sizeof(Item));
		novo->valor = valor;
		novo->proximo = NULL;

		return novo;
	}else{
		atual->proximo = enqueue(valor, atual->proximo);
		
		return atual;
	}
}

//REMOCAO

Item* dequeue(Item* fila){
	
	if(fila != NULL){
		Item* temp = fila->proximo;
		free(fila);
		return temp;
	}else{
		return NULL;
	}
}

void imprimir(Item* fila){
	if(fila != NULL){
		printf("%i ", fila->valor);
		imprimir(fila->proximo);
	}
}

int main(void){
	
	Item* fila = NULL;
	
	fila = enqueue(10, fila);
	fila = enqueue(2, fila);
	fila = dequeue(fila);
	imprimir(fila);

	return 0;
}

