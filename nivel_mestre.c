#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
   char estado = 'A';
    char codigo[5] = "A01";
    char nome[15] = "São Paulo";
    int populacao1 = 123250000;
    float area1 = 1521.11; //Em KM²
    float pib = 699.280; //Bilhões de Reais
    int numerodepontosturisticos1 = 50;
    float densidadepopulacional = populacao1/area1;
    float pibpercapita = pib/populacao1;
    float superpoder = populacao1 + area1 + pib + pibpercapita + densidadepopulacional + numerodepontosturisticos1;

    char estado2 = 'B';
    char codigo2[5] = "B02";
    char nome2[15] = "Rio de Janeiro";
    int populacao2 = 67480000;
    float area2 = 1200.25 //Em KM²
    float pib2 = 300.500; //Bilhões de Reais
    int numerodepontosturisticos2 = 30;
    float densidadepopulacional2 = populacao2/area2;
    float pibpercapita2 = pib2/populacao2;
    float superpoder2 = populacao2 + area2 + pib2 + pibpercapita2 + densidadepopulacional2 + numerodepontosturisticos2;

    printf("Carta 1: \n");
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Carta: %s\n", nome);
    printf("População 1: %d\n", populacao1);
    printf("Área (em KM²): %.2f\n", area1);
    printf("PIB: %.2f Bilhões Em Reais\n", pib);
    printf("Número de Pontos Turisticos: %d\n", numerodepontosturisticos1);
    printf("Dividindo a População: %d Com a Área: %.2f Em KM²\n", populacao1, area1);
    printf("A Densidade populacional será: %.2f\n", populacao1/area1);
    printf("Dividindo o PIB: %.2f Em Bilhões de Reais Com a PopulaçãO: %d\n", pib, populacao1);
    printf("O PIB Per Capita Será: %e\n", pib/populacao1);
    printf("Dividindo a densidade populacional: %.2f e o PIB per capita: %e Teremos: %.2f\n", densidadepopulacional, pibpercapita, densidadepopulacional/pibpercapita);
    printf("Super poder: %.2f\n", superpoder);

  

    printf("Carta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Carta: %s\n", nome2);
    printf("População 2: %d\n", populacao2);
    printf("Área (em KM²): %.2f\n", area2);
    printf("PIB: %.2f Bilhões Em Reais\n", pib2);
    printf("Número de Pontos Turisticos: %d\n", numerodepontosturisticos2);
    printf("Dividindo a População: %d Com a Área: %.2f Em KM²\n", populacao2, area2);
    printf("A Densidade populacional será: %.2f\n", populacao2/area2);
    printf("Dividindo o PIB: %.2f Em Bilhões de Reais Com a PopulaçãO: %d\n", pib2, populacao2);
    printf("O PIB Per Capita Será: %e\n", pib2/populacao2);
    printf("Dividindo a densidade populacional: %.2f e o PIB per capita: %e Teremos: %.2f\n", densidadepopulacional2, pibpercapita2, densidadepopulacional2/pibpercapita2);
    printf("Super poder: %.2f\n", superpoder2);

    printf("A população da carta 1 é maior do que a carta 2? %d\n", populacao1 > populacao2);
    printf("A área da carta 1 é maior do que a carta 2? %d\n", area1 > area2);
    printf("O PIB da carta 1 é maior do que a carta 2? %d\n", pib > pib2);
    printf("O número de pontos turisticos da carta 1 é maior do que a carta 2? %d\n", numerodepontosturisticos1 > numerodepontosturisticos2);
    printf("A densidade populacional da carta 1 é menor do que a carta 2? %d\n", densidadepopulacional < densidadepopulacional2);
    printf("O PIB per capita da carta 1 é maior do que a carta 2? %d\n", pibpercapita > pibpercapita2);
    printf("O super poder da carta 1 é maior do que a carta 2? %d\n", superpoder > superpoder2);
    
    
    printf("***Exercício de soma simples:***\n");


    float area, pib;  // Declara e inicializa a segunda variável
    Printf("Digite o valor da área: ");
    scanf("%f", &area);
    Printf("Digite o valor do PIB: ");
    scanf("%f", &pib); 
    printf("A soma de %.2f e %.2f é: %.2f\n", area , pib);
    
 

    float area2, pib2;  // Declara e inicializa a segunda variável
    Printf("Digite o valor da área: ");
    scanf("%f", &area2);
    Printf("Digite o valor do PIB: ");
    scanf("%f", &pib2); 
    printf("A soma de %.2f e %.2f é:\n", area2 , pib2);
    

    printf("Soma maior de dois elementos dos atributos, Pib e Área:\n"); 
   float resultado1, resultado2;
   resultado1 = area + pib;
   resultado2 = area2 + pib2;
    if(resultado1 > resultado2) {
         printf("A carta 1 tem a maior soma com: %.2f\n", resultado1);
    } else if(resultado1 < resultado2) {
         printf("A carta 2 tem a maior soma com: %.2f\n", resultado2);
    } else {
         printf("As duas cartas têm a mesma soma: %.2f\n", resultado1);
    }
    return 0;
}
   
  