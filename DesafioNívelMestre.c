#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define HAB_SIZE 5


// Criar cone

void criarCone(int cone[HAB_SIZE][HAB_SIZE]) {

    for(int i = 0; i < HAB_SIZE; i++) {
        for(int j = 0; j < HAB_SIZE; j++) {
            if (i == 0 && j == 2) {
                cone[i][j] = 1;
            }
            else if (i == 1 && (j >= 1 && j <= 3)) {
                cone[i][j] = 1;
            }
            else if (i == 2 && (j >= 0 && j <= 4)) {
                cone[i][j] = 1;
            }
            else {
                cone[i][j] = 0;
            }
        }
    }
}


// Criar Cruz

void criarCruz(int cruz[HAB_SIZE][HAB_SIZE]) {

    for(int i = 0; i < HAB_SIZE; i++) {
        for(int j = 0; j < HAB_SIZE; j++) {
            if (j == 2) {
                cruz[i][j] = 1;
            }
            else if (i == 2) {
                cruz[i][j] = 1;
            }
            else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Criar octaedro

void criarOctaedro(int octaedro[HAB_SIZE][HAB_SIZE]) {

    for(int i = 0; i < HAB_SIZE; i++) {
        for(int j = 0; j < HAB_SIZE; j++) {
            int dist = abs(i - 2) + abs(j - 2); 
            if (dist <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Função que aplica a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[SIZE][SIZE], int habilidade[HAB_SIZE][HAB_SIZE], int origemLinha, int origemColuna, int valor) {
    int offset = HAB_SIZE / 2; 
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha - offset + i;
                int colTab = origemColuna - offset + j;

                // Verifica limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < SIZE && colTab >= 0 && colTab < SIZE) {
                    // Só marca se não for navio (3)
                    if (tabuleiro[linhaTab][colTab] == 0) {
                        tabuleiro[linhaTab][colTab] = valor;
                    }
                }
            }
        }
    }
}

int main() {
    char colunas[SIZE] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[SIZE][SIZE];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tabuleiro[i][j] = 0;

    tabuleiro[1][2] = 3; tabuleiro[1][3] = 3; tabuleiro[1][4] = 3; // horizontal
    tabuleiro[5][5] = 3; tabuleiro[6][5] = 3; tabuleiro[7][5] = 3; // vertical
    tabuleiro[0][0] = 3; tabuleiro[1][1] = 3; tabuleiro[2][2] = 3; // diagonal principal
    tabuleiro[0][9] = 3; tabuleiro[1][8] = 3; tabuleiro[2][7] = 3; // diagonal secundária

    // Cria as matrizes das habilidades
    int cone[HAB_SIZE][HAB_SIZE];
    int cruz[HAB_SIZE][HAB_SIZE];
    int octaedro[HAB_SIZE][HAB_SIZE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem para as habilidades no tabuleiro
    int origemConeLinha = 3, origemConeColuna = 3;
    int origemCruzLinha = 6, origemCruzColuna = 5;
    int origemOctaedroLinha = 4, origemOctaedroColuna = 7;

    // Aplica as habilidades no tabuleiro (valor 5 para marcar área afetada)
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna, 5);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna, 5);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna, 5);

    // Exibe colunas
    printf("   ");
    for(int i = 0; i < SIZE; i++) {
        printf(" %c ", colunas[i]);
    }
    printf("\n");

    // Exibe tabuleiro
    for(int i = 0; i < SIZE; i++) {
        printf("%2d |", i + 1);
        for(int j = 0; j < SIZE; j++) {
            int val = tabuleiro[i][j];
            if(val == 0) printf(" ~ ");      // água
            else if(val == 3) printf(" N "); // navio
            else if(val == 5) printf(" * "); // área habilidade
            else printf(" ? ");              
        }
        printf("\n");
    }

    return 0;
}
