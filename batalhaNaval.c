#include <stdio.h>

int main() {

    // -------------------------
    // 1. CRIAÇÃO DO TABULEIRO
    // -------------------------

    int tabuleiro[10][10];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------
    // 2. POSIÇÃO DOS 4 NAVIOS
    // -------------------------

    // Tamanho fixo dos navios
    int tamanho = 3;


    // -------------------------
    // NAVIO 1 (HORIZONTAL)
    // -------------------------

    int n1_linha = 2;
    int n1_coluna = 1;

    // Validação simples
    if (n1_coluna + tamanho <= 10) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[n1_linha][n1_coluna + i] = 3;
        }
    }

    // -------------------------
    // NAVIO 2 (VERTICAL)
    // -------------------------

    int n2_linha = 5;
    int n2_coluna = 7;

    if (n2_linha + tamanho <= 10) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[n2_linha + i][n2_coluna] = 3;
        }
    }

    // -------------------------
    // NAVIO 3 (DIAGONAL PRINCIPAL)
    // (linha e coluna aumentam juntos)
    // -------------------------

    int n3_linha = 0;
    int n3_coluna = 0;

    if (n3_linha + tamanho <= 10 && n3_coluna + tamanho <= 10) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[n3_linha + i][n3_coluna + i] = 3;
        }
    }

    // -------------------------
    // NAVIO 4 (DIAGONAL SECUNDÁRIA)
    // (linha aumenta e coluna diminui)
    // -------------------------

    int n4_linha = 0;
    int n4_coluna = 9;

    if (n4_linha + tamanho <= 10 && n4_coluna - (tamanho - 1) >= 0) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[n4_linha + i][n4_coluna - i] = 3;
        }
    }

    // -------------------------
    // 3. EXIBIR TABULEIRO
    // -------------------------

    printf("\nTABULEIRO 10x10:\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
