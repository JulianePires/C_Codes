#LISTA DUPLAMENTE ENCADEADA (ELEMENTOS INTERLIGADOS)

typedef struct no{
	int valor;
	struct no* proximo;
	struct no* anterior;
}

//INSERCAO

No* inserir(int valor, No* atual){
	
	if(atual == NULL){
	
		No* novo = (No*)malloc(sizeof(No));
		novo->valor = valor;
		novo->proximo = NULL;
		//novo->anterior = NULL;
		
		return novo;
	}else{
		atual->proximo = inserir(valor, atual->proximo);
		return atual;
	}
}

//REMOCAO

No* remover(int valor, No* atual){
	
	if(atual == NULL){
		return NULL;
	}else{
		if(atual->valor == valor){
			No* temp = atual->proximo;
			free(atual);
			return temp;
		}else{
			atual->proximo = remover(valor, atual->proximo);
			atual->proximo->anterior = atual;
			return atual;
		}
	}
}

//IMPRESSAO

void imprimir(No* atual){
	
	if(atual != NULL){
		printf("%i ", atual->valor);
		imprimir(atual->proximo);
	}
}

void imprimir2(No* atual){

	if(atual != NULL){
		imprimir(atual->proximo);
		printf("%i ", atual->valor);
	}
}

int main(void){
	
	No* lista = NULL;
	
	lista = inserir(10, lista);
	lista = inserir(2, lista);
	lista = inserir(3, lista);
	lista = remover(10, lista);
	lista = imprimir(lista);

	return 0;
}




	
