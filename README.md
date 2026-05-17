# 💎 A Fuga da Mina de Cristais

Este é um jogo interativo de gerenciamento de risco e sorte desenvolvido inteiramente na **Linguagem C**. O projeto foi criado como parte das atividades práticas do curso, aplicando conceitos fundamentais de lógica de programação.

---

## 🎯 Objetivo do Jogo
O jogador assume o papel de um minerador preso em uma caverna instável que está desmoronando. O grande objetivo é conseguir explorar os túneis e coletar **100 cristais** para garantir a sua fuga antes que a bateria da sua lanterna acabe ou que a mina desabe completamente.

## 📜 Regras e Mecânicas
A cada rodada, o jogador deve escolher entrar em um dos 3 túneis disponíveis (Portas 1, 2 ou 3). O destino de cada escolha é gerado de forma pseudoaleatória pelo sistema:

*   **Túnel Seguro:** O minerador encontra um filão brilhante e ganha entre 10 e 25 cristais.
*   **Túnel de Gás:** O ar fica pesado, forçando o purificador da lanterna a gastar entre 15% e 30% de bateria.
*   **Túnel Instável:** Um forte tremor abala as estruturas, aumentando a instabilidade da mina entre 15% e 35%.

### 🔋 Evento Especial: Estação de Descanso
A cada 3 rodadas sobrevivendo, o jogador encontra uma antiga área segura onde pode escolher **um** benefício para se recuperar:
1. Recarregar 20% da bateria da lanterna.
2. Escorar o teto para reduzir 20% da instabilidade da mina.

### 🛑 Condições de Fim de Jogo
*   **Vitória:** Alcançar ou ultrapassar 100 cristais coletados.
*   **Derrota por Escuridão:** A bateria da lanterna chegar a 0%.
*   **Derrota por Soterramento:** A instabilidade da caverna atingir 100%.

---

## 🛠️ Restrições Técnicas Aplicadas
Para atender estritamente aos requisitos do módulo avaliado, o código foi estruturado utilizando **exclusivamente**:
*   Estruturas sequenciais e condicionais (`if`, `else if`, `else`).
*   Estruturas de repetição (`while`) para o fluxo principal e validações de dados.
*   Geração de números aleatórios utilizando as bibliotecas `<stdlib.h>` e `<time.h>`.
*   **Sem o uso** de vetores, matrizes, funções personalizadas ou procedimentos.

---

## 🚀 Como Executar o Jogo

1. Certifique-se de ter um compilador de C instalado no seu computador (como o GCC através do Code::Blocks ou Dev-C++).
2. Baixe o arquivo principal do jogo deste repositório.
3. Compile e execute o arquivo através do seu terminal ou IDE de preferência.
4. (Opcional) Você também pode copiar o código e colá-lo em um compilador online como o [OnlineGDB](https://www.onlinegdb.com/).