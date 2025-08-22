#include <stdio.h>

int main() {
    printf("=== Bem-vindo ao Jogo Super Trunfo! ===\n");

    // Carta 1
    char codigo1[] = "GO01";
    char nomeCidade1[] = "Goiânia";
    int populacao1 = 1437366;
    float area1 = 728.8;
    float pib1 = 336.7; // em bilhões
    int pontosTuristicos1 = 30;

    // Cálculos da carta 1
    float densidade1 = populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    // Carta 2
    char codigo2[] = "BAH01";
    char nomeCidade2[] = "Salvador";
    int populacao2 = 2417678;
    float area2 = 693.8;
    float pib2 = 63.0; // em bilhões
    int pontosTuristicos2 = 60;

    // Cálculos da carta 2
    float densidade2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // Menu de atributos
    int opcao1, opcao2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    char nomeAttr1[30], nomeAttr2[30];

    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Guardar valores do primeiro atributo
    switch (opcao1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; sprintf(nomeAttr1,"População"); break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; sprintf(nomeAttr1,"Área"); break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; sprintf(nomeAttr1,"PIB"); break;
        case 4: valor1_c1 = pontosTuristicos1; valor1_c2 = pontosTuristicos2; sprintf(nomeAttr1,"Pontos Turísticos"); break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; sprintf(nomeAttr1,"Densidade Populacional"); break;
        case 6: valor1_c1 = pibPerCapita1; valor1_c2 = pibPerCapita2; sprintf(nomeAttr1,"PIB per Capita"); break;
        default: printf("Opção inválida! Encerrando...\n"); return 0;
    }

    // Menu dinâmico para o segundo atributo
    do {
        printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != opcao1) {
                switch (i) {
                    case 1: printf("1 - População\n"); break;
                    case 2: printf("2 - Área\n"); break;
                    case 3: printf("3 - PIB\n"); break;
                    case 4: printf("4 - Pontos Turísticos\n"); break;
                    case 5: printf("5 - Densidade Populacional (menor vence)\n"); break;
                    case 6: printf("6 - PIB per Capita\n"); break;
                }
            }
        }
        printf("Opção: ");
        scanf("%d", &opcao2);

        if (opcao2 == opcao1) {
            printf("⚠️ Você já escolheu esse atributo. Escolha outro!\n");
        }

    } while (opcao2 == opcao1);

    // Guardar valores do segundo atributo
    switch (opcao2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; sprintf(nomeAttr2,"População"); break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; sprintf(nomeAttr2,"Área"); break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; sprintf(nomeAttr2,"PIB"); break;
        case 4: valor2_c1 = pontosTuristicos1; valor2_c2 = pontosTuristicos2; sprintf(nomeAttr2,"Pontos Turísticos"); break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; sprintf(nomeAttr2,"Densidade Populacional"); break;
        case 6: valor2_c1 = pibPerCapita1; valor2_c2 = pibPerCapita2; sprintf(nomeAttr2,"PIB per Capita"); break;
        default: printf("Opção inválida! Encerrando...\n"); return 0;
    }

    // Comparação dos atributos
    int vencedor1, vencedor2;
    vencedor1 = (opcao1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : 2) : (valor1_c1 > valor1_c2 ? 1 : 2);
    vencedor2 = (opcao2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : 2) : (valor2_c1 > valor2_c2 ? 1 : 2);

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\n========== RESULTADO DA RODADA ==========\n");
    printf("Carta 1 (%s): %s = %.2f | %s = %.2f | Soma = %.2f\n",
           nomeCidade1, nomeAttr1, valor1_c1, nomeAttr2, valor2_c1, soma1);
    printf("Carta 2 (%s): %s = %.2f | %s = %.2f | Soma = %.2f\n",
           nomeCidade2, nomeAttr1, valor1_c2, nomeAttr2, valor2_c2, soma2);

    if (soma1 > soma2) {
        printf("\nVencedora: Carta 1 (%s)\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("\nVencedora: Carta 2 (%s)\n", nomeCidade2);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}