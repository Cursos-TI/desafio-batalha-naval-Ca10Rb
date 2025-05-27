#include <stdio.h>

int main (){
  
   char colunas[10] = {'A', 'B', 'C', 'D', 'E', 
                      'F', 'G', 'H', 'I', 'J'};

   int tabuleiro [10][10];
   
//inicializar o tabuleiro com 0 (água)

   for (int i = 0; i < 10; i++)
   {
     for (int j = 0; j < 10; j++)
     {
        tabuleiro[i][j] = 0;
     }
   }

// - Posicionamento dos navios

// Navio 1 - horizontal

   int linhaH = 1; // linha 2 porque começa em 0
   int colunaH = 2; // coluna c
   int tamanhoH = 3; 

// Vefifica se o navio horizontal cabe

   if (colunaH + tamanhoH <= 10)  // verifica se cabe no tabuleiro
   {
      for (int i = 0; i < tamanhoH; i++)
     {
       tabuleiro[linhaH][colunaH + i] = 3;
     }
   
   }

// Navio 2 - vertical

   int linhaV = 5; // linha 6
   int colunaV = 5; // coluna f 
   int tamanhoV = 3;

// Verifica se o navio vertical cabe e não sobrepõe outro

   if (linhaV + tamanhoV <= 10)
   {
      int sobreposicao = 0;
      
      for (int i = 0; i < tamanhoV; i++) 
      {
        if (tabuleiro[linhaV + i][colunaV] != 0) 
        {
            sobreposicao = 1; //já tem navio lá
        }
      }

      if (!sobreposicao)
      {
         for (int i = 0; i < tamanhoV; i++)
         {
            tabuleiro[linhaV + i][colunaV] = 3;
         }

        } else { 
        printf("Erro: O navio está sobrepondo outro!\n");
        }
      }
   
// Navio 3 -  Diagonal (principal)
    
   int linhaD1 = 0;
   int colunaD1 = 0;
   int tamanhoD1 = 3;

   if (linhaD1 + tamanhoD1 <= 10 && colunaD1 + tamanhoD1 <= 10)
   {
    int sobreposicao = 0;

    for (int i = 0; i < tamanhoD1; i++)
    {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
        {
            sobreposicao = 1;
        }
    }

    if (!sobreposicao)
    {
       for (int i = 0; i < tamanhoD1; i++)
       {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
       }
    } else 
    {
        printf("Erro: sobreposição no navio diagonal \n");
    }
    }
    
// Navio 4 - diagonal (secundária)
   
   int linhaD2 = 0;
   int colunaD2 = 9;
   int tamanhoD2 = 3;
   
   if (linhaD2 + tamanhoD2 <= 10 && colunaD2 - (tamanhoD2 - 1) >= 0)
   {
      int sobreposicao = 0;

      for (int i = 0; i < tamanhoD2; i++)
      {
         if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
         {
           sobreposicao = 1;
         }
      }
      if (!sobreposicao)
      {
        for (int i = 0; i < tamanhoD2; i++)
        {
            tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
        }
      }
      else {
        printf("Erro: sobreposição no navio diagonal\n");
      }
   }
   
//Exibe as colunas

   printf("   "); //espaço alinhando com as letras

   for (int i = 0; i < 10; i++)
   {
     printf(" %c ", colunas[i]);
   }
   printf("\n");

// Exibe tabuleiro com números nas linhas

   for (int i = 0; i < 10; i++)
   {
     printf("%2d |", i + 1);

     for (int j = 0; j < 10; j++)
     {
        printf(" %d ", tabuleiro[i][j]);
     }

     printf("\n");
    
   }

return 0;
}