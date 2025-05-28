#include <stdio.h>

/**
 * Programa de Simulação de Movimentos de Peças de Xadrez - Nível Mestre
 * 
 * Este programa simula o movimento de quatro peças de xadrez:
 * - Torre: usando função recursiva em vez de estrutura de repetição simples
 * - Bispo: usando função recursiva e também loops aninhados (dois métodos diferentes)
 * - Rainha: usando função recursiva em vez de estrutura de repetição simples
 * - Cavalo: usando loops aninhados complexos com múltiplas variáveis e condições
 * 
 * Os movimentos simulados são:
 * - Torre: 5 casas para a direita
 * - Bispo: 5 casas na diagonal (cima e direita)
 * - Rainha: 8 casas para a esquerda
 * - Cavalo: Movimento em "L" (2 casas para cima e 1 para a direita)
 */

// Protótipos das funções recursivas para simular movimentos
/**
 * Simula o movimento da Torre de forma recursiva
 * @param passos Número de casas a serem percorridas pela Torre
 */
void moverTorreRecursivo(int passos);

/**
 * Simula o movimento do Bispo de forma recursiva
 * @param passos Número de casas a serem percorridas pelo Bispo na diagonal
 */
void moverBispoRecursivo(int passos);

/**
 * Simula o movimento da Rainha de forma recursiva
 * @param passos Número de casas a serem percorridas pela Rainha
 */
void moverRainhaRecursivo(int passos);

/**
 * Simula o movimento do Bispo usando loops aninhados
 * @param passos Número de casas a serem percorridas pelo Bispo na diagonal
 */
void moverBispoLoops(int passos);

int main() {
    // Definição das constantes para o número de casas a serem movidas por cada peça
    // Estas variáveis são usadas tanto para as funções recursivas quanto para os loops
    int casasTorre = 5;    // A Torre move 5 casas para a direita
    int casasBispo = 5;    // O Bispo move 5 casas na diagonal (cima e direita)
    int casasRainha = 8;   // A Rainha move 8 casas para a esquerda
    int casasCavaloVertical = 2;  // O Cavalo move 2 casas para cima (movimento em "L")
    int casasCavaloHorizontal = 1; // O Cavalo move 1 casa para a direita (movimento em "L")

    // === Torre (Implementação Recursiva) ===
    // Substituímos o loop for original por uma função recursiva
    printf("=== Movimento da Torre (usando recursão) ===\n");
    moverTorreRecursivo(casasTorre);

    // === Bispo (Implementação Recursiva) ===
    // Substituímos o loop while original por uma função recursiva
    printf("\n=== Movimento do Bispo (usando recursão) ===\n");
    moverBispoRecursivo(casasBispo);

    // === Rainha (Implementação Recursiva) ===
    // Substituímos o loop do-while original por uma função recursiva
    printf("\n=== Movimento da Rainha (usando recursão) ===\n");
    moverRainhaRecursivo(casasRainha);

    // === Bispo com Loops Aninhados ===
    // Implementação adicional do Bispo usando loops aninhados
    // (loop externo para movimento vertical, loop interno para horizontal)
    printf("\n=== Movimento do Bispo (usando loops aninhados) ===\n");
    moverBispoLoops(casasBispo);

    // === Cavalo (Implementação com Loops Complexos) ===
    printf("\n=== Movimento do Cavalo (usando loops complexos) ===\n");
    /**
     * Simulação do movimento do Cavalo em formato "L":
     * - 2 casas para cima e 1 casa para a direita
     * 
     * Implementação com loops aninhados complexos:
     * - Loop externo: controla o número total de movimentos e a sequência das direções
     * - Loop interno: controla a execução de cada movimento específico com base em condições
     * - Usa break e continue para controlar o fluxo de execução dos loops
     * - Utiliza múltiplas variáveis para rastrear os movimentos em cada direção
     */
    
    // Variáveis para controle do movimento do Cavalo
    int totalMovimentos = casasCavaloVertical + casasCavaloHorizontal; // Total de casas a serem percorridas
    int direcaoAtual = 0; // Controla a direção atual: 0 = vertical (cima), 1 = horizontal (direita)
    int movimentosVerticais = 0; // Contador de movimentos realizados na vertical
    int movimentosHorizontais = 0; // Contador de movimentos realizados na horizontal
    
    // Loop externo para controlar toda a sequência de movimentos do Cavalo
    for (int i = 0; i < totalMovimentos; i++) {
        // Loop interno com múltiplas condições e variáveis - executa no máximo 2 iterações
        for (int j = 0; j < 2; j++) {
            // Determina a direção baseada em múltiplas condições
            if (movimentosVerticais < casasCavaloVertical && direcaoAtual == 0) {
                // Executa o movimento vertical (para cima)
                printf("Cima\n");
                movimentosVerticais++;
                
                // Quando completar os movimentos verticais, muda para a direção horizontal
                if (movimentosVerticais >= casasCavaloVertical) {
                    direcaoAtual = 1;
                }
                
                break; // Sai do loop interno após realizar um movimento
            } 
            else if (movimentosHorizontais < casasCavaloHorizontal && direcaoAtual == 1) {
                // Executa o movimento horizontal (para a direita)
                printf("Direita\n");
                movimentosHorizontais++;
                
                // Se estiver no último movimento, usa break para encerrar o loop interno
                if (movimentosHorizontais >= casasCavaloHorizontal) {
                    break;
                }
                
                // Se precisar continuar com mais movimentos horizontais
                // (só relevante se casasCavaloHorizontal > 1)
                continue;
            }
        }
        
        // Verifica se todos os movimentos do Cavalo foram concluídos
        if (movimentosVerticais >= casasCavaloVertical && 
            movimentosHorizontais >= casasCavaloHorizontal) {
            break; // Encerra o loop externo quando completar todos os movimentos
        }
    }

    return 0;
}

/**
 * Função recursiva para simular o movimento da Torre.
 * A Torre move-se em linha reta horizontalmente ou verticalmente.
 * Nesta implementação, a Torre se move para a direita.
 * 
 * A recursão substitui o loop for original do nível novato.
 * A cada chamada recursiva, o número de passos restantes é reduzido em 1.
 * 
 * @param passos Número de passos restantes a serem dados
 */
void moverTorreRecursivo(int passos) {
    // Caso base: quando não há mais passos a serem dados
    if (passos <= 0) {
        return; // Encerra a recursão
    }
    
    // Ação: Move uma casa para a direita
    printf("Direita\n");
    
    // Chamada recursiva: continua o movimento com um passo a menos
    // Esta é a parte recursiva que substitui a iteração do loop
    moverTorreRecursivo(passos - 1);
}

/**
 * Função recursiva para simular o movimento do Bispo.
 * O Bispo move-se na diagonal (cima e direita).
 * 
 * A recursão substitui o loop while original do nível novato.
 * A cada chamada recursiva, o número de passos restantes é reduzido em 1.
 * 
 * @param passos Número de passos restantes a serem dados na diagonal
 */
void moverBispoRecursivo(int passos) {
    // Caso base: quando não há mais passos a serem dados
    if (passos <= 0) {
        return; // Encerra a recursão
    }
    
    // Ação: Move uma casa na diagonal (cima e direita)
    // A impressão de "Cima Direita" representa o movimento diagonal combinado
    printf("Cima Direita\n");
    
    // Chamada recursiva: continua o movimento com um passo a menos
    // Esta é a parte recursiva que substitui a iteração do loop
    moverBispoRecursivo(passos - 1);
}

/**
 * Função recursiva para simular o movimento da Rainha.
 * A Rainha pode mover-se em qualquer direção (horizontal, vertical ou diagonal).
 * Nesta implementação, a Rainha se move para a esquerda.
 * 
 * A recursão substitui o loop do-while original do nível novato.
 * A cada chamada recursiva, o número de passos restantes é reduzido em 1.
 * 
 * @param passos Número de passos restantes a serem dados
 */
void moverRainhaRecursivo(int passos) {
    // Caso base: quando não há mais passos a serem dados
    if (passos <= 0) {
        return; // Encerra a recursão
    }
    
    // Ação: Move uma casa para a esquerda
    printf("Esquerda\n");
    
    // Chamada recursiva: continua o movimento com um passo a menos
    // Esta é a parte recursiva que substitui a iteração do loop
    moverRainhaRecursivo(passos - 1);
}

/**
 * Função para simular o movimento do Bispo usando loops aninhados.
 * O loop externo controla o movimento vertical (cima), e o interno controla o movimento horizontal (direita).
 * Juntos, eles simulam o movimento diagonal do Bispo.
 * 
 * Esta é uma implementação alternativa ao método recursivo, demonstrando
 * como os loops aninhados podem ser usados para simular o mesmo movimento.
 * 
 * @param passos Número total de passos na diagonal
 */
void moverBispoLoops(int passos) {
    // Loop externo para o movimento vertical (cima)
    // Controla quantas casas o Bispo se move para cima
    for (int movimentoVertical = 0; movimentoVertical < passos; movimentoVertical++) {
        // Loop interno para o movimento horizontal (direita)
        // Para cada movimento vertical, realiza um movimento horizontal
        // Limitado a 1 iteração porque cada passo diagonal é uma combinação de um movimento vertical e um horizontal
        for (int movimentoHorizontal = 0; movimentoHorizontal < 1; movimentoHorizontal++) {
            // Cada iteração completa dos dois loops representa um movimento diagonal completo
            printf("Cima Direita\n");
        }
    }
}