
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	
	int valor;
	struct no* esq;
	struct no* dir;

}No;

/* verifica se a arvore está vazia */
int arvoreVazia(No* no){

	return no == NULL;

}

/* conta os nós */ 
int count(No *a){

  if(a == NULL){

    return 0;

	}else{

    return 1 + count(a->esq) + count(a->dir);

	}

}

/* verifica se o elemento pertence à árvore */
int contem(No* n, int valor) {
  
  if(arvoreVazia(n)) { /* se a árvore estiver vazia, então retorna 0 */
    return 0;
  }
  
  /* o operador lógico || interrompe a busca quando o elemento for encontrado */
  return n->valor == valor || contem(n->esq, valor) || contem(n->dir, valor);
}

/* insere valores na árvore */
No* inserir(No* atual, int v){
	if(atual == NULL){ /* se o nó atual estiver livre */
		
		No* novo = (No*)malloc(sizeof(No)); /* alocação de espaço para novo nó */
		novo->valor = v; /* atribui o valor para o novo nó */
		novo->esq = NULL; /* instancia filho da esquerda */
		novo->dir = NULL; /* instancia filho da direita */
		return novo;

	}else{ 

		if(v <= atual->valor){ /* valores menores ou iguais que o nó pai vão para a esquerda */

			atual->esq = inserir(atual->esq, v);
			return atual;

		}else{ /* valores maiores que o nó pai vão para a esquerda */

			atual->dir = inserir(atual->dir, v);
			return atual;

		}
	}
}

/* busca percorrendo a estrutura da árvore */
No* buscar(No* atual, int valor){

	if(atual == NULL){ /* se o nó estiver vazio */

		printf("Valor não pertence à árvore\n");
		return NULL;

	}else if(atual->valor > valor){ /* se o valor do nó atual for maior que o valor buscado a função vai para a esquerda */

		return buscar(atual->esq, valor);

	}else if(atual->valor < valor){ /* se o valor do nó atual for maior que o valor buscado a função vai para a direita */

		return buscar(atual->dir, valor);

	}else{ /* se o valor for encontrado retorna o nó atual */

		return atual;

	}
}

/* remove um valor da árvore a partir de 3 situações */
No* remover(No* no, int v){

	if(no == NULL){

		return NULL;

	}else if(no->valor > v){

		no->esq = remover(no->esq, v);

	}else if(no->valor < v){

		no->dir = remover(no->dir, v);

	}else{

 		if (no->esq == NULL && no->dir == NULL) { /* nó sem filhos */
 		
			free (no);
 			no = NULL;

 		}else if (no->esq == NULL) { /* nó só tem filho à direita */
 			
			No* aux = no;
 			no = no->dir;
 			free (aux);

 		}else if (no->dir == NULL) { /* nó só tem filho à esquerda */ 

 			No* aux = no;
 			no = no->esq;
 			free (aux);

	  }else { /* nó tem os dois filhos */

 			No* aux = no->esq; /* nó auxiliar recebe o valor do nó à esquerda*/

			while (aux->dir != NULL) { /* enquanto o valor do próximo nó à direita for != NULL */
 				aux = aux->dir; /* aux vai receber o próximo valor à direita */ 
 			}

			no->valor = aux->valor; /* o nó recebe o valor do último nó à direita do nó à esquerda */
			aux->valor = v; /* o valor de auxiliar recebe o valor do nó a ser apagado */
			no->esq = remover(no->esq,v); 
			/* como o valor a ser apagado vai ter tomado o lugar do último valor à direita, ao chamar a função passando
			o endereço do nó à esquerda e o valor a ser removido, ele se torna um nó sem filhos e é removido */

		}
	}
	
	return no;
}

/* imprime em pré ordem raiz->esq->dir */
void imprimirPreOrdem(No* atual){ 

	if(atual != NULL){

		printf("%i ", atual->valor);
		imprimirPreOrdem(atual->esq);
		imprimirPreOrdem(atual->dir);

	}
}

/* imprime em ordem esq->raiz->dir */
void imprimirEmOrdem(No* atual){ 

	if(atual != NULL){

		imprimirEmOrdem(atual->esq);
		printf("%i ", atual->valor);
		imprimirEmOrdem(atual->dir);

	}
}

/* imprime em pós ordem esq->dir->raiz */
void imprimirPosOrdem(No* atual){ 

	if(atual != NULL){

		imprimirPosOrdem(atual->esq);
		imprimirPosOrdem(atual->dir);
		printf("%i ", atual->valor);
		
	}
}

/* imprime por "níveis" (FILA) */
void imprimirNiveis(No* no){
  if (no == NULL) return;
  else{
    No* fila;
    int i, f;
    fila = malloc(count(no) * sizeof(No));
    fila[0] = *no;
    i = 0;
    f = 1;
   
	  /* enquanto a Árvore tiver nós à esquerda ou à direita se incrementa o f, se o i for incrementado mas o f não o loop é encerrado */
    while (f > i){
      *no = fila[i++];
      printf("%d ", no->valor);
      if(no->esq != NULL) fila[f++] = *no->esq;
      if(no->dir != NULL) fila[f++] = *no->dir;
    }

    free(fila); /* libera espaço alocado */
  }
}

/* altura de um nó e da árvore */
int altura(No* no){
  if(no == NULL){
		
		return -1;

	} 
  else{
    
		int alt_esq = altura(no->esq);
    int alt_dir = altura(no->dir);

    if(alt_esq > alt_dir){ 
			return alt_esq + 1;
		}else{
			return alt_dir + 1;
		}

	}
}

int main (void){

	No* raiz = NULL;
	raiz = inserir(raiz, 10);
	raiz = inserir(raiz, 19);
	raiz = inserir(raiz, 5);
	raiz = inserir(raiz, 7);
	raiz = inserir(raiz, 2);
	raiz = inserir(raiz, 1);
	raiz = inserir(raiz, 20);
	raiz = inserir(raiz, 12);
	raiz = inserir(raiz, 50);

	printf("Altura da árvore: %i\n\n", altura(raiz));
	
	buscar(raiz, 8);

	printf("\n\n");
	printf("Pre-ordem: \n");
	imprimirPreOrdem(raiz);
	
	printf("\n\n");
	printf("Em ordem: \n");
	imprimirEmOrdem(raiz);
	
	printf("\n\n");
	printf("Pós-ordem: \n");
	imprimirPosOrdem(raiz);
	
	//printf("\n\n");
	//printf("Níveis: \n");
	//imprimirNiveis(raiz);

	remover(raiz, 10);
	
	printf("\n\n");
	printf("Pre-ordem: \n");
	imprimirPreOrdem(raiz);
	
	printf("\n\n");
	printf("Em ordem: \n");
	imprimirEmOrdem(raiz);
	
	printf("\n\n");
	printf("Pós-ordem: \n");
	imprimirPosOrdem(raiz);

	free(raiz); /* libera a memória alocada pela estrutura árvore */
	return 0;
}
