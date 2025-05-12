#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz 10x10 representando o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2; // linha onde será colocado o navio horizontal
    int colunaNavioHorizontal = 4; // coluna inicial do navio horizontal

    int linhaNavioVertical = 6; // linha inicial do navio vertical
    int colunaNavioVertical = 1; // coluna onde será colocado o navio vertical

    // Validação: verifica se os navios cabem no tabuleiro
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posiciona navio horizontal (valor 3)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        }

        // Posiciona navio vertical (valor 3)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se há sobreposição
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == 3) {
                printf("Erro: Sobreposição de navios detectada!\n");
                return 1;
            }
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
        }

    } else {
        printf("Erro: Um ou mais navios ultrapassam os limites do tabuleiro.\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval (0 = Água, 3 = Navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
