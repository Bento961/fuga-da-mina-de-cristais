#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Comando para inicializar o gerador de números aleatórios (Randomize)
    srand(time(NULL));

    // Declaração de variáveis para o estado do jogo
    int cristais = 0;
    int bateria = 100;
    int instabilidade = 0;
    int rodada = 1;
    
    // Variáveis de controle de escolhas e sorteios
    int escolha_usuario;
    int destino_porta;
    int sorteio_valores;

    printf("==================================================\n");
    printf("        BEM-VINDO A FUGA DA MINA DE CRISTAIS       \n");
    printf("==================================================\n");
    printf(" Voce esta preso em uma mina desmoronando!\n");
    printf(" Objetivo: Colete 100 cristais para escapar.\n");
    printf(" Perigo: Nao deixe sua bateria zerar ou a mina desabar!\n");
    printf("==================================================\n\n");

    // Estrutura de repetição principal do jogo (Loop do Gameplay)
    while (cristais < 100 && bateria > 0 && instabilidade < 100) {
        
        printf("--------- RODADA %d ---------\n", rodada);
        printf(" Cristais Coletados: %d / 100\n", cristais);
        printf(" Bateria da Lanterna: %d%%\n", bateria);
        printf(" Instabilidade da Mina: %d%%\n", instabilidade);
        printf("-----------------------------\n");

        // Interação com o usuário: Escolha do caminho
        printf("Escolha um tunel para explorar (1, 2 ou 3): ");
        scanf("%d", &escolha_usuario);

        // Validação da entrada com uma estrutura de repetição limpa
        while (escolha_usuario < 1 || escolha_usuario > 3) {
            printf("Opcao invalida! Escolha apenas o tunel 1, 2 ou 3: ");
            scanf("%d", &escolha_usuario);
        }

        // Lógica de Sorteio do Destino do Túnel (1 = Cristais, 2 = Gás/Bateria, 3 = Tremor/Instabilidade)
        // O número sorteado independe da porta escolhida, garantindo o fator surpresa
        destino_porta = (rand() % 3) + 1; 

        // Estruturas condicionais para aplicar o resultado da escolha
        if (destino_porta == 1) {
            // Sorteia ganho de cristais entre 10 e 25
            sorteio_valores = (rand() % 16) + 10; 
            cristais += sorteio_valores;
            printf("\n[SUCESSO] Voce encontrou um filao reluzente e coletou %d cristais!\n\n", sorteio_valores);
        } 
        else if (destino_porta == 2) {
            // Sorteia perda de bateria entre 15% e 30%
            sorteio_valores = (rand() % 16) + 15;
            bateria -= sorteio_valores;
            printf("\n[PERIGO] Tunel com gas toxico! O purificador gastou %d%% da bateria da lanterna.\n\n", sorteio_valores);
        } 
        else {
            // Sorteia aumento de instabilidade entre 15% e 35%
            sorteio_valores = (rand() % 21) + 15;
            instabilidade += sorteio_valores;
            printf("\n[ALERTA] TETO SE MOVENDO! Um forte tremor aumentou a instabilidade em %d%%.\n\n", sorteio_valores);
        }

        // Condição Extra / Evento Dinâmico: Estação de Descanso a cada 3 rodadas
        // Verifica se as condições de fim de jogo já não foram atingidas antes de oferecer o bônus
        if (rodada % 3 == 0 && cristais < 100 && bateria > 0 && instabilidade < 100) {
            printf("========== ESTACAO DE DESCANSO ENCONTRADA ==========\n");
            printf("Voce achou uma area segura antiga. Escolha seu beneficio:\n");
            printf("1 - Recarregar 20%% de Bateria\n");
            printf("2 - Escorar o teto (Reduzir 20%% de Instabilidade)\n");
            printf("Sua escolha (1 ou 2): ");
            scanf("%d", &escolha_usuario);

            while (escolha_usuario < 1 || escolha_usuario > 2) {
                printf("Opcao invalida! Digite 1 ou 2: ");
                scanf("%d", &escolha_usuario);
            }

            if (escolha_usuario == 1) {
                bateria += 20;
                if (bateria > 100) bateria = 100; // Impede que a bateria passe de 100%
                printf("\n-> Lanterna recarregada! Bateria atual: %d%%\n\n", bateria);
            } else {
                instabilidade -= 20;
                if (instabilidade < 0) instabilidade = 0; // Impede que a instabilidade seja negativa
                printf("\n-> Teto reforçado! Instabilidade atual: %d%%\n\n", instabilidade);
            }
        }

        rodada++; // Incremento da estrutura de repetição
    }

    // Tela Final: Verificação dos Critérios de Vitória ou Derrota
    printf("==================================================\n");
    if (cristais >= 100) {
        printf("       PARABENS! VOCE CONSEGUIU ESCAPAR!        \n");
        printf(" Voce coletou %d cristais e saiu vivo da mina!\n", cristais);
        printf(" Rodadas jogadas: %d\n", rodada - 1);
    } 
    else if (bateria <= 0) {
        printf("       GAME OVER: A LANTERNA APAGOU...          \n");
        printf(" Ficando na completa escuridao, voce se perdeu para sempre.\n");
    } 
    else if (instabilidade >= 100) {
        printf("       GAME OVER: O TETO DESABOU!               \n");
        printf(" A mina ruiu. Voce foi soterrado pelos escombros.\n");
    }
    printf("==================================================\n");

    return 0;
}