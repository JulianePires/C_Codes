#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("----------- POKEMON, EM BUSCA DA INSIGNIA DE PEDRA -------------\n\n");
	printf("VOCÊ É ASH (A) E PRECISA CONQUISTAR A INSIGNIA DE PEDRA! PARA ISTO, DEVE ENFRENTAR BROCK NO ESTADIO (E). MAS VOCÊ ESTÁ SEM POKEMONS E PRECISA DE PELO MENOS 3 PARA CONSEGUIR BATALHAR.\n\nCAMINHE PELO CAMINHO NAVEGÁVEL (*) UTILIZANDO AS TECLAS WSAD, CONSIGA POKEBOLAS (B), CAPTURE POKEMONS (P) E SE PREPARE PARA A BATALHA!");

	printf("\n\nObs1: as chances de captura do pokemon são de 80 porcento, se você não conseguir capturá-lo, ele fugirá e você perderá a pokebola.\nObs2: se você encontrar um pokemon e estiver sem pokebolas, ele fugirá!");
    srand((unsigned)time(NULL));
    char mapa[12][10]; // Mapa declarado

    //Zerando o mapa
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mapa[i][j] = '_';
        }
    }
    //Posicionando Ash
    int ash_x = 0, ash_y = 0;
    mapa[ash_x][ash_y] = 'A';

    //inicializando caminhos navegáveis

    for (int i=1; i<=6; i++)
    {
        mapa [0][i] ='*' ;
    }

    for (int i=8; i<=10; i++)
    {
        mapa [0][i] ='*' ;
    }

    for (int i=1; i<=4; i++)
    {
        mapa [i][0] = '*';
    }

    for (int i=1; i<=3; i++)
    {
        mapa [i][6] = '*';
    }

    mapa[3][7] = '*';


    for (int i=1; i<=7; i++)
    {
        mapa [i][8] = '*';
    }

    for (int i=1; i<=2; i++)
    {
        mapa [4][i] = '*';
    }

    for (int i=1; i<=4; i++)
    {
        mapa [9][i] ='*' ;
    }

    for (int i=1; i<=4; i++)
    {
        mapa [7][i] ='*' ;
    }

    for (int i=0; i<=3; i++)
    {
        mapa [11][i] ='*' ;
    }

    for (int i=4; i<=7; i++)
    {
        mapa [i][2] ='*' ;
    }

    for (int i=7; i<=11; i++)
    {
        mapa [i][3] ='*' ;
    }

    for (int i=3; i<=7; i++)
    {
        mapa [i][4] ='*' ;
    }

    for (int i=9; i<=11; i++)
    {
        mapa [i][5] ='*' ;
    }

    for (int i=7; i<=11; i++)
    {
        mapa [i][7] ='*' ;
    }

    for (int i=0; i<=5; i++)
    {
        mapa [7][i] ='*' ;
    }

    mapa [5][5] = '*';
    mapa [11][0] = 'E';

    //inicializando os pokemons
    int pokemon = 10;

    for (int i = 0; i <= pokemon;)
    {
        int poke_x, poke_y;
        poke_x = rand()%12;
        poke_y = rand()%10;
        if(mapa[poke_x][poke_y] == '*')
        {
            mapa[poke_x][poke_y] = 'P';
            i++;
        }
    }

    //inicializando as pokebolas
    int pokebola = 5;

    for (int i = 0; i <= pokebola;)
    {
        int ball_x, ball_y;
        ball_x = rand()%12;
        ball_y = rand()%10;
        if(mapa[ball_x][ball_y] == '*')
        {
            mapa[ball_x][ball_y] = 'B';
            i++;
        }
    }

    int fim = 1, n_pokemon=0, n_pokebola=0;
    do
    {
				printf("\n\n");
        //imprimindo o mapa
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ",mapa[i][j]);
            }
            printf("\n");
        }

        printf("\nPokebolas: %i\nPokemons: %i",n_pokebola,n_pokemon);

        //implementando navegação
        char mov;
        printf("\nMovimento: ");
        scanf("%c",&mov);
        getchar();

        switch (mov)
        {
            case 'w':
                if(ash_x-1>=0 && mapa[ash_x-1][ash_y]!='_')
                {
                    //encontrando pokebola
                    if(mapa[ash_x-1][ash_y] == 'B')
                    {
                        printf("\nVocê encontrou uma pokebola!");
                        n_pokebola++;
                    }
                    //encontrando pokemon
                    if(mapa[ash_x-1][ash_y] == 'P')
                    {
                        if(n_pokebola > 0){
                            int aux = rand()%101;
                            if(aux <= 80)
                            {
                                printf("\nVocê capturou um pokemon!");
                                n_pokebola--;
                                n_pokemon++;

                            }
                            else
                            {
                                printf("\nVocê não conseguiu capturar o pokemon e ele escapou!");
																n_pokebola--;
                            }
                        }
                        else
                        {
                            printf("\nVocê não possuia pokebolas e o pokemon escapou!");
                        }
                    }


                    mapa[ash_x][ash_y]='*';
                    ash_x--;
                    mapa[ash_x][ash_y]='A';
                }
                else
                {
                    printf("\nCaminho não navegável!");
                }
                break;

            case 's':
                if(ash_x+1<=11 && mapa[ash_x+1][ash_y]!='_')
                {
                    //encontrando pokebola
                    if(mapa[ash_x+1][ash_y] == 'B')
                    {
                        printf("\nVocê encontrou uma pokebola!");
                        n_pokebola++;
                    }
                    //encontrando pokemon
                    if(mapa[ash_x+1][ash_y] == 'P')
                    {
                        if(n_pokebola > 0){
                            int aux = rand()%101;
                            if(aux <= 80)
                            {
                                printf("\nVocê capturou um pokemon!");

                                n_pokebola--;
                                n_pokemon++;

                            }
                            else
                            {
                                printf("\nVocê não conseguiu capturar o pokemon e ele escapou!");
																n_pokebola--;
                            }
                        }
                        else
                        {
                            printf("\nVocê não possuia pokebolas e o pokemon escapou!");
                        }
                    }


                    mapa[ash_x][ash_y]='*';
                    ash_x++;
                    mapa[ash_x][ash_y]='A';
                }
                else
                {
                    printf("\nCaminho não navegável!");
                }
                break;

            case 'a':
                if(ash_y-1>=0 && mapa[ash_x][ash_y-1]!='_')
                {
                    //encontrando pokebola
                    if(mapa[ash_x][ash_y-1] == 'B')
                    {
                        printf("\nVocê encontrou uma pokebola!");
                        n_pokebola++;
                    }
                    //encontrando pokemon
                    if(mapa[ash_x][ash_y-1] == 'P')
                    {
                        if(n_pokebola > 0){
                            int aux = rand()%101;
                            if(aux <= 80)
                            {
                                printf("\nVocê capturou um pokemon!");

                                n_pokebola--;
                                n_pokemon++;

                            }
                            else
                            {
                                printf("\nVocê não conseguiu capturar o pokemon e ele escapou!");
																n_pokebola--;
                            }
                        }
                        else
                        {
                            printf("\nVocê não possuia pokebolas e o pokemon escapou!");
                        }
                    }

                    //encontrando estádio
                    if(mapa[ash_x][ash_y-1] == 'E'){
                        if(n_pokemon<3){
                            printf("\nVocê chegou ao estádio sem um número de pokemons suficiente, fim de jogo!");
                            fim = 0;
                            break;
                        }
                        else
                        {
                            printf("\n\nVocê conseguiu chegar ao estádio com 3 pokemons, vamos batalhar!");
														printf("\n\nVocê e Brock batalharão com 3 pokemons, cada batalha um rolará um dado, e ao perder, o pokemon é nocauteado. Vence quem conseguir derrotar os pokemons do adversário primeiro. BOA SORTE!");
                            int n_ash, n_brock, pok_ash=3, pok_brock=3, fim_batalha = 1;
                            while(fim_batalha != 0){
                                printf("\nPressione enter para rolar o dado: ");
                                getchar();
                                n_ash = rand()%11;
                                n_brock = rand()%11;
                                printf("\n----- Você: %i | Brock : %i",n_ash,n_brock);
                                if(n_ash>n_brock){
                                    printf("\nVocê venceu a batalha!");
                                    pok_brock--;
                                }
                                else if(n_ash == n_brock)
                                {
                                    printf("\nDeu empate!");
                                }
                                else
                                {
                                    printf("\nBrock venceu!");
                                    pok_ash--;
                                }
																if (pok_ash == 0 || pok_brock == 0)
																{
																	fim_batalha = 0;
																}
                            }
                            if (pok_ash>pok_brock){
                                printf("\nParabéns! Você venceu e ganhou a insigna da pedra!");
                                fim = 0;
                                break;
                            }
                            else
                            {
                                printf("\nVocê foi derrotado! Boa sorte na próxima!");
                                fim = 0;
                                break;
                            }
                        }
                    }

                    mapa[ash_x][ash_y]='*';
                    ash_y--;
                    mapa[ash_x][ash_y]='A';
                }
                break;

            case 'd':
                if(ash_y+1<=9 && mapa[ash_x][ash_y+1]!='_')
                {
                    //encontrando pokebola
                    if(mapa[ash_x][ash_y+1] == 'B')
                    {
                        printf("\nVocê encontrou uma pokebola!");
                        n_pokebola++;
                    }
                    //encontrando pokemon
                    if(mapa[ash_x][ash_y+1] == 'P')
                    {
                        if(n_pokebola > 0)
                        {
                            int aux = rand()%101;
                            if(aux <= 80)
                            {
                                printf("\nVocê capturou um pokemon!");

                                n_pokebola--;
                                n_pokemon++;
                            }
                            else
                            {
                                printf("\nVocê não conseguiu capturar o pokemon e ele escapou!");
																n_pokebola--;
                            }
                        }
                        else
                        {
                            printf("\nVocê não possuia pokebolas e o pokemon escapou!");
                        }
                    }


                    mapa[ash_x][ash_y]='*';
                    ash_y++;
                    mapa[ash_x][ash_y]='A';
                }
                else
                {
                    printf("\nCaminho não navegável!");
                }
                break;
        }

    }while(fim != 0);





    return 0;
}
