#include <stdio.h>

int main() {
    // Número de casas a serem movidas por cada peça
    int casasTorre = 5;    // A Torre move 5 casas para a direita
    int casasBispo = 5;    // O Bispo move 5 casas na diagonal (cima e direita)
    int casasRainha = 8;   // A Rainha move 8 casas para a esquerda

    printf("=== Movimento da Torre (usando for) ===\n");
    // Simulação do movimento da Torre: 5 casas para a direita usando for
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n=== Movimento do Bispo (usando while) ===\n");
    // Simulação do movimento do Bispo: 5 casas na diagonal (cima e direita) usando while
    int contadorBispo = 1;
    while (contadorBispo <= casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    printf("\n=== Movimento da Rainha (usando do-while) ===\n");
    // Simulação do movimento da Rainha: 8 casas para a esquerda usando do-while
    int contadorRainha = 1;
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    return 0;
}
