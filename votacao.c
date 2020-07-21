#include <stdio.h>

int main(void) {
  
	int voto, nJair, nCarlos, nNeves, nNulo, nBranco, somaVoto;
	nJair = 0;
	nCarlos = 0;
	nNeves = 0;
	nNulo = 0;
	nBranco = 0;
	somaVoto = 0;

	do{
		printf("\nEscolha um candidato de acordo com as opções (1- Candidato Jair Rodrigues | 2- Candidato Carlos Luz | 3- Candidato Neves Rocha | 4- Nulo | 5- Branco) ou digite 6 para finalizar -- ");
		scanf("%i",&voto);

		while (voto<1 || voto>6){
			printf("\nOpção inválida, escolha novamente! ");
			scanf("%i",&voto);
		}

		if(voto == 1){
			nJair++;
		}
		else if(voto == 2){
			nCarlos++;
		}
		else if(voto == 3){
			nNeves++;
		}
		else if(voto == 4){
			nBranco++;
		}
		else if(voto == 5){
			nNulo++;
		}

		somaVoto++;

	}while(voto!=6);

	printf("\nJair Rodrigues: %i votos",nJair);
	printf("\nCarlos Luz: %i votos",nCarlos);
	printf("\nNeves Rocha: %i votos",nNeves);
	printf("\nPercentagem de Nulos: %i porcento",nNulo*100/somaVoto);
	printf("\nPercentagem de Brancos: %i porcento",nBranco*100/somaVoto);

	if(nJair>nCarlos && nJair>nNeves){
		printf("\n\nJair Rodrigues eleito!");
	}
	else if(nCarlos>nJair && nCarlos>nNeves){
		printf("\n\nCarlos Luz eleito!");
	}
	else if(nNeves>nJair && nNeves>nCarlos){
		printf("\n\nNeves Rocha eleito!");
	}
	else{
		printf("\nEleições empatadas!");
	}

	return 0;
}
