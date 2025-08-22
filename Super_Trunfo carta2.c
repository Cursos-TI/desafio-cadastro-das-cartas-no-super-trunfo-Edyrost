#include <stdio.h>
    int main() {
           
        printf("Carta 2\n");
       
        char estado = 'B';
        char codigo[] = "B01";
        char nome[20] = "Rio de Janeiro";
        int populacao = 12314556;
        float area = 1612.11; // Área em km²
        float pib = 450000.00; // PIB em milhões de reais
        int pontos = 65;
        float densidade = populacao / area; // Densidade populacional
        float pib_per_capita = pib / populacao; // PIB per capita
        
        printf("Estado 2: %c\n", estado);
        printf("Código 2: %s\n", codigo);
        printf("Nome da Cidade: %s\n", nome);
        printf("População: %d\n", populacao);
        printf("Área: %.2f km²\n", area);
        printf("PIB: %.2f milhões de reais\n", pib);
        printf("Pontos Turísticos: %d\n", pontos);
        printf("Densidade Populacional: %.2f habitantes/km²\n", densidade);
        printf("PIB per Capita: %.2f reais\n", pib_per_capita);

        return 0;
    }

