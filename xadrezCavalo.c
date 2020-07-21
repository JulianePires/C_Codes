#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
	char tabuleiro[8][8];

	//zerando o tabuleiro
	int x, y;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tabuleiro[i][j] = '*';
		}
	}
	
	//Posicionando as peças do adversário
	int adv_x, adv_y;

	for (int aux=0; aux<=8;)
	{
		adv_x=rand()%8;
		adv_y=rand()%8;
		while(tabuleiro[adv_x][adv_y] != 'A')
		{
			if (tabuleiro[adv_x][adv_y] == '*')
			{
				tabuleiro[adv_x][adv_y] = 'A';
				aux++;
			}
		}
	}

	//Posicionando o cavalo
	int cav_x, cav_y;
	cav_x=rand()%8;
	cav_y=rand()%8;
	while (tabuleiro[cav_x][cav_y] != 'C')
	{
		if (tabuleiro[cav_x][cav_y] == '*')
		{
			tabuleiro[cav_x][cav_y] = 'C';
		}
	}

	//Imprimindo o tabuleiro
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%c ", tabuleiro[i][j]);
		}
		printf("\n");
	}

  int chance = 0;

			if (tabuleiro[cav_x+2][cav_y+1] == 'A' && (cav_x+2 <= 7) && (cav_y+1 >= 0))
			{
				chance++;
			}
		
			if(tabuleiro[cav_x+2][cav_y-1] == 'A' && (cav_x+2 <= 7) && (cav_y-1 >= 0))
			{
				chance++;
			}

			if(tabuleiro[cav_x-2][cav_y+1] == 'A' && (cav_x-2 >= 0) && (cav_y+1 <= 7))
			{
				chance++;
			}

			if(tabuleiro[cav_x-2][cav_y-1] == 'A' && (cav_x-2 >= 0) && (cav_y-1 >= 0))
			{
				chance++;
			}

			if(tabuleiro[cav_x+1][cav_y+2] == 'A' && (cav_x+1 <= 7) && (cav_y+2 <= 7))
			{
				chance++;
			}

			if(tabuleiro[cav_x-1][cav_y+2] == 'A' && (cav_x-1 >= 0) && (cav_y+2 <= 7))
			{
				chance++;
			}

			if(tabuleiro[cav_x+1][cav_y-2] == 'A' && (cav_x+1 <= 7) && (cav_y-2 >= 0))
			{
				chance++;
			}

			if(tabuleiro[cav_x-1][cav_y-2] == 'A' && (cav_x-1 >= 0) && (cav_y-2 >= 0))
			{
				chance++;
			}

	printf("\nVocê consegue derrubar %i peças do seu adversário!",chance);
	
  return 0;
}
