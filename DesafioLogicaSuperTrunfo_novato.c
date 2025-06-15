#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular densidade populacional e PIB per capita
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para imprimir os dados principais de uma carta
void imprimirCarta(struct Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", carta.pibPerCapita);
}

int main() {
    // Cadastro das duas cartas
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 780000000000.0, 15};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6718903, 1182.30, 411000000000.0, 12};

    // Cálculo dos indicadores para cada carta
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Impressão das cartas cadastradas
    printf("=== Carta 1 ===\n");
    imprimirCarta(carta1);

    printf("=== Carta 2 ===\n");
    imprimirCarta(carta2);

    // Comparação pelo atributo escolhido: PIB per capita
    printf("Comparacao de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s (%.2f)\n", carta1.nomeCidade, carta1.pibPerCapita);
    printf("Carta 2 - %s (%.2f)\n", carta2.nomeCidade, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
