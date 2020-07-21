#include <stdio.h>

int main(void) {
  
	int i, num, n1, n2, aux;
	n1 = 1;
	n2 = 0;
	aux = 0;

	printf("\nDigite o n-ésimo número da sequencia fibonacci a ser pesquisado: ");
	scanf("%i",&num);

	for (i=1; i<num; i++){
			n2 = aux;
			n2 = n2 + n1;
			aux = n1;
			n1 = n2;
	}

	printf("\nO %iº número da sequencia fibonacci é: %i",num,n2);
	return 0;
}
