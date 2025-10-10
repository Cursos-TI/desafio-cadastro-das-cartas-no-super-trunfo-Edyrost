#include <stdio.h>

int main() {
    char estado = 'A';
    char codigo[5] = "A01";
    char nome[15] = "São Paulo";
    int populacao = 123250000;
    float area = 1521.11; //Em KM²
    float pib = 699.28; //Bilhões de Reais
    int numerodepontosturisticos = 50;
    float densidadepopulacional = (float)populacao/area;
    float pibpercapita = pib/populacao;
    float superpoder = populacao + area + pib + pibpercapita + densidadepopulacional + numerodepontosturisticos;

    char estado2 = 'B';
    char codigo2[5] = "B02";
    char nome2[15] = "Rio de Janeiro";
    int populacao2 =67480000;
    float area2 = 1200.25; //Em KM²
    float pib2 = 300.50; //Bilhões de Reais
    int numerodepontosturisticos2 = 30;
    float densidadepopulacional2 = (float)populacao2/area2;
    float pibpercapita2 = pib2/populacao2;
    float superpoder2 = populacao2 + area2 + pib2 + pibpercapita2 + densidadepopulacional2 + numerodepontosturisticos2;

    printf("Carta 1: \n");
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Carta: %s\n", nome);
    printf("População: %d\n", populacao);
    printf("Área (em KM²): %.2f\n", area);
    printf("PIB: %.2f Bilhões Em Reais\n", pib);
    printf("Número de Pontos Turisticos: %d\n", numerodepontosturisticos);
    printf("Dividindo a População: %d Com a Área: %.2f Em KM²\n", populacao, area);
    printf("A Densidade populacional será: %.2f\n", populacao/area);
    printf("Dividindo o PIB: %.2f Em Bilhões de Reais Com a PopulaçãO: %d\n", pib, populacao);
    printf("O PIB Per Capita Será: %e\n", pib/populacao);
    printf("Dividindo a densidade populacional: %.2f e o PIB per capita: %e Teremos: %.2f\n", densidadepopulacional, pibpercapita, densidadepopulacional/pibpercapita);
    printf("Super poder: %.2f\n", superpoder);

    printf("Carta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Carta: %s\n", nome2);
    printf("População: %d\n", populacao2);
    printf("Área (em KM²): %.2f\n", area2);
    printf("PIB: %.2f Bilhões Em Reais\n", pib2);
    printf("Número de Pontos Turisticos: %d\n", numerodepontosturisticos2);
    printf("Dividindo a População: %d Com a Área: %.2f Em KM²\n", populacao2, area2);
    printf("A Densidade populacional será: %.2f\n", populacao2/area2);
    printf("Dividindo o PIB: %.2f Em Bilhões de Reais Com a PopulaçãO: %d\n", pib2, populacao2);
    printf("O PIB Per Capita Será: %e\n", pib2/populacao2);
    printf("Dividindo a densidade populacional: %.2f e o PIB per capita: %e Teremos: %.2f\n", densidadepopulacional2, pibpercapita2, densidadepopulacional2/pibpercapita2);
    printf("Super poder: %.2f\n", superpoder2);

    printf("A população da carta 1 é maior do que a carta 2? %d\n", populacao > populacao2);
    printf("A área da carta 1 é maior do que a carta 2? %d\n", area > area2);
    printf("O PIB da carta 1 é maior do que a carta 2? %d\n", pib > pib2);
    printf("O número de pontos turisticos da carta 1 é maior do que a carta 2? %d\n", numerodepontosturisticos > numerodepontosturisticos2);
    printf("A densidade populacional da carta 1 é menor do que a carta 2? %d\n", densidadepopulacional < densidadepopulacional2);
    printf("O PIB per capita da carta 1 é maior do que a carta 2? %d\n", pibpercapita > pibpercapita2);
    printf("O super poder da carta 1 é maior do que a carta 2? %d\n", superpoder > superpoder2);

    //Resultado das comparações
    printf("Comparação das Cartas:\n");
    printf("População: A Carta 1 Venceu\n");
    printf("Área: A Carta 1 Venceu\n");
    printf("PIB: A Carta 1 Venceu\n");
    printf("Número de pontos turisticos: A Carta 1 Venceu\n");
    printf("Densidade populacional: A Carta 2 Venceu\n");
    printf("PIB per capita: A Carta 1 Venceu\n");
    printf("Super poder: A Carta 1 Venceu\n");
    
    return 0;
}