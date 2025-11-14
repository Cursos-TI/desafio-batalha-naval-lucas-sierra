#include <stdio.h>

int main() {

    // -------------------------
    // 1. TABULEIRO 10x10
    // -------------------------

    int tabuleiro[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // água
        }
    }


    // -------------------------
    // 2. NAVIOS (apagados do foco)
    // mesmo modelo do código anterior
    // -------------------------

    int tamanho = 3;

    // Navio horizontal
    int n1_linha = 2;
    int n1_coluna = 1;

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[n1_linha][n1_coluna + i] = 3;
    }

    // Navio vertical
    int n2_linha = 5;
    int n2_coluna = 7;

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[n2_linha + i][n2_coluna] = 3;
    }

    // Diagonal principal
    int n3_linha = 0;
    int n3_coluna = 0;

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[n3_linha + i][n3_coluna + i] = 3;
    }

    // Diagonal secundária
    int n4_linha = 0;
    int n4_coluna = 9;

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[n4_linha + i][n4_coluna - i] = 3;
    }


    // -------------------------
    // 3. MATRIZES DE HABILIDADE (5x5)
    // -------------------------

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // -------------------------
    // 3.1 CONE (apontado para baixo)
    // ponto de origem na linha 0, coluna 2
    // -------------------------

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // Forma de cone:
            // linha 0 -> coluna central
            // linha 1 -> +-1 colunas
            // linha 2 -> +-2 colunas
            if (i == 0 && j == 2) {
                cone[i][j] = 1;
            }
            else if (i == 1 && j >= 1 && j <= 3) {
                cone[i][j] = 1;
            }
            else if (i == 2 && j >= 0 && j <= 4) {
                cone[i][j] = 1;
            }
            else {
                cone[i][j] = 0;
            }
        }
    }


    // -------------------------
    // 3.2 CRUZ
    // -------------------------

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // condição para cruz:
            // linha central OU coluna central
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }


    // -------------------------
    // 3.3 OCTAEDRO (losango)
    // -------------------------

    // centro = linha 2, coluna 2
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // distâncias até o centro
            int distLinha = i - 2;
            if (distLinha < 0) distLinha = -distLinha;

            int distCol = j - 2;
            if (distCol < 0) distCol = -distCol;

            // forma de losango:
            if (distLinha + distCol <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }


    // -------------------------
    // 4. APLICAR HABILIDADES NO TABULEIRO
    // cada habilidade tem um ponto de origem
    // -------------------------

    int origemConeLinha = 4;
    int origemConeColuna = 4;

    int origemCruzLinha = 7;
    int origemCruzColuna = 2;

    int origemOctLinha = 6;
    int origemOctColuna = 7;


    // -------------------------
    // 4.1 SOBREPOR CONE
    // -------------------------

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (cone[i][j] == 1) {

                int linha = origemConeLinha + i - 2;
                int coluna = origemConeColuna + j - 2;

                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0)
                        tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }


    // -------------------------
    // 4.2 SOBREPOR CRUZ
    // -------------------------

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (cruz[i][j] == 1) {

                int linha = origemCruzLinha + i - 2;
                int coluna = origemCruzColuna + j - 2;

                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0)
                        tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }


    // -------------------------
    // 4.3 SOBREPOR OCTAEDRO
    // -------------------------

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (octaedro[i][j] == 1) {

                int linha = origemOctLinha + i - 2;
                int coluna = origemOctColuna + j - 2;

                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0)
                        tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }



    // -------------------------
    // 5. EXIBIR TABULEIRO COMPLETO
    // -------------------------

    printf("\nTABULEIRO FINAL:\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
