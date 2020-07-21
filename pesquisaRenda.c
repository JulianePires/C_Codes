#include <stdio.h>

int main(void) {
  
	float salario, maiorSalario, menorSalario, contSalario, nFilhos, contHabitantes, contFilhos, doisFilhos, i;

	contFilhos = 0;
	doisFilhos = 0;
	contSalario = 0;

	printf("Digite a quantidade de habitantes a serem cadastrados: ");
	scanf("%f",&contHabitantes);

	for (i=1; i<=contHabitantes; i++){
		printf("\nDigite o salário: ");
		scanf("%f",&salario);
		printf("\nDigite o número de filhos: ");
		scanf("%f",&nFilhos);

		contFilhos = contFilhos + nFilhos;
		contSalario = contSalario + salario;
		
		if (i==1){
			maiorSalario = salario;
			menorSalario = salario;
		}
		if (salario < menorSalario){
			menorSalario = salario;
		}
		if (salario > maiorSalario){
			maiorSalario = salario;
		}
		if (nFilhos > 2){
			doisFilhos = doisFilhos + 1;
		}
	}

	printf("\n\nMédia do salário da população: %f",contSalario/contHabitantes);
	printf("\n\nMédia de número de filhos: %f",contFilhos/contHabitantes);
	printf("\n\nMaior Salário: %f",maiorSalario);
	printf("\n\nMenor Salário: %f",menorSalario);
	printf("\n\nHabitantes com mais de 2 filhos: %f porcento",(doisFilhos/contHabitantes)*100);
	
	return 0;
}
