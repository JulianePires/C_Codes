#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL)); //Configurando a função random 
	char mapa[10][10]; //Declarando o mapa

	//Zerando o mapa
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			mapa[i][j]='*';
		}
	}

	//Posicionando Rick
	int rick_x, rick_y;
	rick_x = rand()%10;
	rick_y = rand()%10;
	mapa[rick_x][rick_y] = 'R';

	//Posicionando obstáculos
	for (int obs = 0; obs <= 5;)
	{
		int obs_x, obs_y;
		obs_x = rand()%10;
		obs_y = rand()%10;

		if (mapa[obs_x][obs_y] == '*')
		{
			mapa[obs_x][obs_y] = 'O'; //Obstáculo Posicionado
			obs++;
		}
	}

	//Posicionando zumbis
	for (int zumbi = 0; zumbi <= 5;)
	{
		int zumbi_x, zumbi_y;
		zumbi_x = rand()%10;
		zumbi_y = rand()%10;

		if (mapa[zumbi_x][zumbi_y] == '*')
		{
			mapa[zumbi_x][zumbi_y] = 'Z'; //Zumbi posicionado
			zumbi++;
		}
	}

	//Posicionando Balas
	for (int bala = 0; bala <= 5;)
	{
		int bala_x, bala_y;
		bala_x = rand()%10;
		bala_y = rand()%10;

		if (mapa[bala_x][bala_y] == '*')
		{
			mapa[bala_x][bala_y] = 'B'; //Bala posicionada
			bala++;
		}
	}

	//Posicionando saída
	int saida_x, saida_y;
	do{
		saida_x = rand()%10;
		saida_y = rand()%10;

		if (mapa[saida_x][saida_y] == '*')
		{
		mapa[saida_x][saida_y] = 'S'; //Saída Posicionada
		}
	} while(mapa[saida_x][saida_y] != 'S'); //Garante que a saída seja posicionada mesmo encontrando uma posição ocupada

	int bullet = 0; //variável nº de balas	
	int fim = 1; //condicional para entrada no programa

	//CABEÇALHO
	printf("\n THE WALKING DEAD\n\n");
	printf("Você é Rick (R) e precisa escapar da sala. Mas cuidado, existem obstáculos e zumbis no seu caminho, tente desviá-los e encontrar a saída utilizando as teclas WASD para mover-se pelo mapa. Se você encontrar zumbis e estiver sem balas, será morto!\n\n R = Rick \n\n");
	
	do
	{	
		//Imprimindo o mapa
		for (int x = 0; x < 10; x++){
			for(int y = 0; y < 10; y++){
				printf("%c ", mapa[x][y]);
			}
			printf("\n");
		}
		
		printf("\n Balas: %i", bullet);

		//Movimentação
		char mov;
		printf("\n\nMovimento: ");
		scanf("%c", &mov);
		getchar();
		printf("\n\n");

		switch(mov)
		{
			case 'w':
				
				if(rick_x-1 >= 0)
				{	
					for (int x = 0; x < 10; x++){
						for(int y = 0; y < 10; y++){
							if (mapa[x][y] == 'Z'){
								if (x>rick_x){
									if(mapa[x-1][y] == '*'){
										mapa[x][y] = '*';
										x = x - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y>rick_y){
									if(mapa[x][y-1] == '*'){
										mapa[x][y] = '*';
										y = y - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (x<rick_x){
									if(mapa[x+1][y] == '*'){
										mapa[x][y] = '*';
										x = x + 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y<rick_y){
									if(mapa[x][y+1] == '*'){
										mapa[x][y] = '*';
										y = y + 1;
										mapa[x][y] = 'Z';
									}
								}
							}
						}
					}	

					if (mapa[rick_x-1][rick_y] == 'S') //Encontrando saída
					{	
						printf("PARABÉNS! VOCÊ ENCONTROU A SAÍDA, FIM DE JOGO.\n\n");
						fim = 0;
						break;
					}
					
					if (mapa[rick_x-1][rick_y] == 'B') //Encontrando Balas
					{
						bullet++;
					}
				
					if (mapa[rick_x-1][rick_y] == 'Z') //Encontrando zumbis
					{
						if (bullet == 0)
						{
							printf("VOCÊ ESTAVA SEM BALAS E FOI MORTO POR UM ZUMBI! GAME OVER\n\n");
							fim = 0;
							break;
						}
						else
						{	
							printf("VOCÊ ELIMINOU UM ZUMBI E PERDEU UMA BALA, RESTAM %i BALAS\n\n",bullet);
							bullet--;
						}
					}

					if(mapa[rick_x-1][rick_y] == 'O') //Encontrando Obstáculo
					{
						printf("VOCÊ ENCONTROU UM OBSTÁCULO, MOVA-SE EM OUTRA DIREÇÃO.\n\n");
						break;
					}

					//Decrementando coordenada x
					mapa[rick_x][rick_y] = '*';
					rick_x--;
					mapa[rick_x][rick_y] = 'R';
				}
			break;

			case 'a':
				if(rick_y-1 >= 0)
				{
					for (int x = 0; x < 10; x++){
						for(int y = 0; y < 10; y++){
							if (mapa[x][y] == 'Z'){
								if (x>rick_x){
									if(mapa[x-1][y] == '*'){
										mapa[x][y] = '*';
										x = x - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y>rick_y){
									if(mapa[x][y-1] == '*'){
										mapa[x][y] = '*';
										y = y - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (x<rick_x){
									if(mapa[x+1][y] == '*'){
										mapa[x][y] = '*';
										x = x + 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y<rick_y){
									if(mapa[x][y+1] == '*'){
										mapa[x][y] = '*';
										y = y + 1;
										mapa[x][y] = 'Z';
									}
								}
							}
						}
					}
					if (mapa[rick_x][rick_y-1] == 'S') //Encontrando saída
					{	
						printf("PARABÉNS! VOCÊ ENCONTROU A SAÍDA, FIM DE JOGO.\n\n");
						fim = 0;
						break;
					}
					
					if (mapa[rick_x][rick_y-1] == 'B') //Encontrando Balas
					{
						bullet++;
					}
				
					if (mapa[rick_x][rick_y-1] == 'Z') //Encontrando zumbis
					{
						if (bullet == 0)
						{
							printf("VOCÊ ESTAVA SEM BALAS E FOI MORTO POR UM ZUMBI! GAME OVER\n\n");
							fim = 0;
							break;
						}
						else
						{	
							printf("VOCÊ ELIMINOU UM ZUMBI E PERDEU UMA BALA, RESTAM %i BALAS\n\n",bullet);
							bullet--;
						}
					}

					if(mapa[rick_x][rick_y-1] == 'O') //Encontrando Obstáculo
					{
						printf("VOCÊ ENCONTROU UM OBSTÁCULO, MOVA-SE EM OUTRA DIREÇÃO.\n\n");
						break;
					}

					//Decrementando coordenada y
					mapa[rick_x][rick_y] = '*';
					rick_y--;
					mapa[rick_x][rick_y] = 'R';
				}
				else
				{
					printf("VOCÊ ENCONTROU UM OBSTÁCULO, MOVA-SE EM OUTRA DIREÇÃO.\n\n");
				}
			break;
			
			case 's':
				
				if(rick_x+1 <= 9)
				{
					for (int x = 0; x < 10; x++){
						for(int y = 0; y < 10; y++){
							if (mapa[x][y] == 'Z'){
								if (x>rick_x){
									if(mapa[x-1][y] == '*'){
										mapa[x][y] = '*';
										x = x - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y>rick_y){
									if(mapa[x][y-1] == '*'){
										mapa[x][y] = '*';
										y = y - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (x<rick_x){
									if(mapa[x+1][y] == '*'){
										mapa[x][y] = '*';
										x = x + 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y<rick_y){
									if(mapa[x][y+1] == '*'){
										mapa[x][y] = '*';
										y = y + 1;
										mapa[x][y] = 'Z';
									}
								}
							}
						}
					}
					if (mapa[rick_x+1][rick_y] == 'S') //Encontrando saída
					{	
						printf("PARABÉNS! VOCÊ ENCONTROU A SAÍDA, FIM DE JOGO.\n\n");
						fim = 0;
						break;
					}
					
					if (mapa[rick_x+1][rick_y] == 'B') //Encontrando Balas
					{
						bullet++;
					}
				
					if (mapa[rick_x+1][rick_y] == 'Z') //Encontrando zumbis
					{
						if (bullet==0)
						{
							printf("VOCÊ ESTAVA SEM BALAS E FOI MORTO POR UM ZUMBI! GAME OVER\n\n");
							fim = 0;
							break;
						}
						else
						{	
							printf("VOCÊ ELIMINOU UM ZUMBI E PERDEU UMA BALA, RESTAM %i BALAS\n\n",bullet);
							bullet--;
						}
					}

					if(mapa[rick_x+1][rick_y] == 'O') //Encontrando Obstáculo
					{
						printf("VOCÊ ENCONTROU UM OBSTÁCULO, MOVA-SE EM OUTRA DIREÇÃO.\n\n");
						break;
					}

					//Incrementando coordenada x
					mapa[rick_x][rick_y] = '*';
					rick_x++;
					mapa[rick_x][rick_y] = 'R';
				}
				else
				{
					printf("VOCÊ ENCONTROU UM OBSTÁCULO, MOVA-SE EM OUTRA DIREÇÃO.\n\n");
				}
			break;

			case 'd':
				
				if(rick_y+1 <= 9)
				{
					for (int x = 0; x < 10; x++){
						for(int y = 0; y < 10; y++){
							if (mapa[x][y] == 'Z'){
								if (x>rick_x){
									if(mapa[x-1][y] == '*'){
										mapa[x][y] = '*';
										x = x - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y>rick_y){
									if(mapa[x][y-1] == '*'){
										mapa[x][y] = '*';
										y = y - 1;
										mapa[x][y] = 'Z';
									}
								}
								if (x<rick_x){
									if(mapa[x+1][y] == '*'){
										mapa[x][y] = '*';
										x = x + 1;
										mapa[x][y] = 'Z';
									}
								}
								if (y<rick_y){
									if(mapa[x][y+1] == '*'){
										mapa[x][y] = '*';
										y = y + 1;
										mapa[x][y] = 'Z';
									}
								}
							}
						}
					}
					if (mapa[rick_x][rick_y+1] == 'S') //Encontrando saída
					{	
						printf("PARABÉNS! VOCÊ ENCONTROU A SAÍDA, FIM DE JOGO.\n\n");
						fim = 0;
						break;
					}
					
					if (mapa[rick_x][rick_y+1] == 'B') //Encontrando Balas
					{
						bullet++;
					}
				
					if (mapa[rick_x][rick_y+1] == 'Z') //Encontrando zumbis
					{
						if (bullet==0)
						{
							printf("VOCÊ ESTAVA SEM BALAS E FOI MORTO POR UM ZUMBI! GAME OVER\n\n");
							fim = 0;
							break;
						}
						else
						{	
							printf("VOCÊ ELIMINOU UM ZUMBI E PERDEU UMA BALA, RESTAM %i BALAS\n\n",bullet);
							bullet--;
						}
					}

					if(mapa[rick_x][rick_y+1] == 'O') //Encontrando Obstáculo
					{
						printf("VOCÊ ENCONTROU UM OBSTÁCULO, MOVA-SE EM OUTRA DIREÇÃO.\n\n");
						break;
					}

					//Incrementando coordenada y
					mapa[rick_x][rick_y] = '*';
					rick_y++;
					mapa[rick_x][rick_y] = 'R';
				}
				else
				{
					printf("VOCÊ ENCONTROU UM OBSTÁCULO, MOVA-SE EM OUTRA DIREÇÃO.\n\n");
				}
			break;
		}
	}while(fim!=0);
	return 0;
}
