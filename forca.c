#include <stdio.h>
#include <string.h>

int main(void) {
  
  int fim = 0;

  char secreta[10] = "fortaleza";

  int tam = strlen(secreta);
  char palavra[tam+1];

  int vidas = 5;

  //Zerar palavra
  for(int i = 0; i < tam; i++)
  {
    palavra[i] = '_';
  }

  //Estrutura do jogo
  do
  {
    //Imprimir a palavra
    for(int i = 0; i < tam; i++)
    {
      printf("%c ", palavra[i]);
    }

    //Pedir letra
    char caracter;
    printf("\n\nDigite um caracter: ");
    scanf("%c", &caracter);
    getchar();

    int acertou = 0;

    //Verificar se caracter existe em secreta
    for(int i = 0; i < tam; i++)
    {
      if(caracter == secreta[i])
      {
        palavra[i] = caracter;

        acertou = 1;
      }
    }

    if(acertou == 0)
    {
      vidas--;

      if(vidas == 0)
      {
        fim = 1;
      }
    }
    else
    {
      int n_acertos = 0;

      for(int i = 0; i < tam; i++)
      {
        if(palavra[i] != '_')
        {
          n_acertos++;
        }
      }

      if(n_acertos == tam)
      {
        fim = n_acertos;
      }
    }

    printf("\n\n%i vidas restantes!\n\n", vidas);

  }while(!fim);

  if(fim == tam)
  {
    printf("Voce ganhou!");
  }
  else
  {
    printf("Voce perdeu!");
  }


  return 0;
}
