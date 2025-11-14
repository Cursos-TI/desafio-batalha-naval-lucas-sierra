#include <stdio.h>

int main() {

    // -----------------------------------------------------
    // TABULEIRO 10x10 INICIALIZADO COM ÁGUA (0)
    // -----------------------------------------------------
    int tabuleiro[10][10];

    // Preenche toda a matriz com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -----------------------------------------------------
    // NAVIOS DE TAMANHO FIXO = 3
    // Representados por vetores unidimensionais
    // Valor 3 representa parte do navio
    // -----------------------------------------------------
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

    // -----------------------------------------------------
    // COORDENADAS DOS NAVIOS (DEFINIDAS NO CÓDIGO)
    // -----------------------------------------------------
    int linhaH = 2;   // navio horizontal começa na linha 2
    int colunaH = 4;  // e coluna 4

    int linhaV = 5;   // navio vertical começa na linha 5
    int colunaV = 1;  // e coluna 1

    // -----------------------------------------------------
    // VALIDAÇÃO BÁSICA — GARANTE QUE O NAVIO CABE NO TABULEIRO
    // -----------------------------------------------------
    if (colunaH + 3 > 10) {
        printf("Erro: navio horizontal nao cabe no tabuleiro.\n");
        return 0;
    }

    if (linhaV + 3 > 10) {
        printf("Erro: navio vertical nao cabe no tabuleiro.\n");
        return 0;
    }

    // -----------------------------------------------------
    // VALIDAÇÃO SIMPLES DE SOBREPOSIÇÃO
    // -----------------------------------------------------
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] == 3 ||
            tabuleiro[linhaV + i][colunaV] == 3) {
            printf("Erro: navios se sobrepoem.\n");
            return 0;
        }
    }

    // -----------------------------------------------------
    // POSICIONA O NAVIO HORIZONTAL NO TABULEIRO
    // Copiamos os valores do vetor para a matriz
    // -----------------------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // -----------------------------------------------------
    // POSICIONA O NAVIO VERTICAL NO TABULEIRO
    // -----------------------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // -----------------------------------------------------
    // EXIBE O TABULEIRO COMPLETO
    // -----------------------------------------------------
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
